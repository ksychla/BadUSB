#ifndef __USB_DEVICE__H__
#define __USB_DEVICE__H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "usbd_def.h"

#define TRUE 1
#define FALSE 0

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

void MX_USB_DEVICE_Init(void);
void openShell();
void closeShell();
void typeString(char* string);
int8_t isCharInArray(char c, char* array, int size);
void sendKeyPress(keyboardHID* keyboardhid);
uint8_t encodeKey(char character);
void prepareKeyboardHID(keyboardHID* keyboardhid, char* charactersToSend, uint8_t currentModifier);
char toLower(char character);

#ifdef __cplusplus
}
#endif

#endif /* __USB_DEVICE__H__ */
