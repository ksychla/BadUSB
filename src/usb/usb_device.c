#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_hid.h"

USBD_HandleTypeDef hUsbDeviceFS;


void MX_USB_DEVICE_Init(void) {
  if (USBD_Init(&hUsbDeviceFS, &FS_Desc, DEVICE_FS) != USBD_OK) {
    Error_Handler();
  }
  if (USBD_RegisterClass(&hUsbDeviceFS, &USBD_HID) != USBD_OK) {
    Error_Handler();
  }
  if (USBD_Start(&hUsbDeviceFS) != USBD_OK) {
    Error_Handler();
  }

}

void typeEnter() {
  typedef struct {
    uint8_t MODIFIER;
    uint8_t RESERVED;
    uint8_t KEYCODE1;
    uint8_t KEYCODE2;
    uint8_t KEYCODE3;
    uint8_t KEYCODE4;
    uint8_t KEYCODE5;
    uint8_t KEYCODE6;
  } keyboardHID;

  keyboardHID keyboardhid = {0,0,0,0,0,0,0,0};

  keyboardhid.KEYCODE1 = 0x28;
  USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof(keyboardHID));
  HAL_Delay(1);
  keyboardhid.KEYCODE1 = 0x0;
  USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof(keyboardHID));
  HAL_Delay(1);
}

void typeKeys() {
  typedef struct {
    uint8_t MODIFIER;
    uint8_t RESERVED;
    uint8_t KEYCODE1;
    uint8_t KEYCODE2;
    uint8_t KEYCODE3;
    uint8_t KEYCODE4;
    uint8_t KEYCODE5;
    uint8_t KEYCODE6;
  } keyboardHID;

  keyboardHID keyboardhid = {0,0,0,0,0,0,0,0};

  keyboardhid.KEYCODE1 = 0x17;
  keyboardhid.KEYCODE2 = 0x18;
  keyboardhid.KEYCODE3 = 0x19;
  keyboardhid.KEYCODE4 = 0x1a;
  keyboardhid.KEYCODE5 = 0x1b;
  keyboardhid.KEYCODE6 = 0x1c;
  USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof(keyboardHID));
  HAL_Delay(1);
  keyboardhid.KEYCODE1 = 0x0;
  keyboardhid.KEYCODE2 = 0x0;
  keyboardhid.KEYCODE3 = 0x0;
  keyboardhid.KEYCODE4 = 0x0;
  keyboardhid.KEYCODE5 = 0x0;
  keyboardhid.KEYCODE6 = 0x0;
  USBD_HID_SendReport(&hUsbDeviceFS, &keyboardhid, sizeof(keyboardHID));
  HAL_Delay(1);
}
