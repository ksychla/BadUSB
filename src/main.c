#include "main.h"
#include "fatfs.h"
#include "file_handling.h"
#include "usb_hid_device.h"
#include "usb_msc_device.h"

#define PAYLOAD_NAME "payload.txt"

SD_HandleTypeDef hsd;

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SDIO_SD_Init(void);
void flashLED(uint8_t r, uint8_t g, uint8_t b);


int main(void) {
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_SDIO_SD_Init();
  MX_USB_HID_DEVICE_Init();
  MX_FATFS_Init();
  int8_t flag = 0;
  char* buffer = (char*) calloc(BUFFER_SIZE, sizeof(char));
  char* rememberPointer = buffer;
  Key* keys;
  int start = HAL_GetTick();
  directives dirs;
  uint32_t count = 0;
  if (mount_sd() == FR_OK) {
    if (read_file(PAYLOAD_NAME, buffer, 0) > 0) {
      dirs = parseDirectives(buffer);
      buffer += dirs.numberOfBytes;
    }
    do {
      keys = prepareKeys(buffer);
      int interval = HAL_GetTick() - start;
      if (interval < 2000) {
          HAL_Delay(2000 - interval);
      }
      if (!dirs.noshell && count == 0) {
        openShell();
      }
      sendKeys(keys, strlen(buffer));
      flag = 1;
      free(keys);
      count++;
      buffer = rememberPointer;
    } while (read_file(PAYLOAD_NAME, buffer, count * (BUFFER_SIZE - 1)) > 0);
    if (!dirs.noshell) {
      closeShell();
    }
    unmount_sd();
  }
  free(buffer);

  MX_FATFS_DeInit();
  MX_USB_HID_DEVICE_DeInit();

  MX_USB_MSC_DEVICE_Init();

  while (1) {
    if (flag == 1) {
      flashLED(0, 1, 0);
    } else {
      flashLED(1, 0, 0);
    }
    HAL_Delay(100);
  }
}

void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 15;
  RCC_OscInitStruct.PLL.PLLN = 135;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
    Error_Handler();
  }
}

static void MX_SDIO_SD_Init(void) {

  hsd.Instance = SDIO;
  hsd.Init.ClockEdge = SDIO_CLOCK_EDGE_RISING;
  hsd.Init.ClockBypass = SDIO_CLOCK_BYPASS_DISABLE;
  hsd.Init.ClockPowerSave = SDIO_CLOCK_POWER_SAVE_DISABLE;
  hsd.Init.BusWide = SDIO_BUS_WIDE_1B;
  hsd.Init.HardwareFlowControl = SDIO_HARDWARE_FLOW_CONTROL_DISABLE;
  hsd.Init.ClockDiv = 12;
  if (HAL_SD_Init(&hsd) != HAL_OK) {
    Error_Handler();
  }
  if (HAL_SD_ConfigWideBusOperation(&hsd, SDIO_BUS_WIDE_4B) != HAL_OK) {
    Error_Handler();
  }

}

static void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_R_Pin | LED_G_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, LED_B_Pin, GPIO_PIN_RESET);
  // HAL_GPIO_WritePin(GPIOA, LED_R_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : LED_R_Pin LED_G_Pin LED_B_Pin */
  GPIO_InitStruct.Pin = LED_R_Pin|LED_G_Pin|LED_B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

void Error_Handler(void) {
  __disable_irq();
  while (1) { }
}

void flashLED(uint8_t r, uint8_t g, uint8_t b) {
  if (r == 1) {
    HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
  }
  if (g == 1) {
    HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
  }
  if (b == 1) {
    HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin);
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
