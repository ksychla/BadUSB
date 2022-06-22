#ifndef __USB_HID_DEVICE__H__
#define __USB_HID_DEVICE__H__

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "usbd_def.h"

#define TRUE 1
#define FALSE 0

#define NOSHELL "@@noshell@@"
#define ONELINE "@@oneline@@"

typedef struct {
  uint8_t MODIFIER;
  uint8_t KEYCODE;
} Key;

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

typedef struct {
  uint16_t numberOfBytes;
  uint8_t noshell;
  uint8_t oneline;
} directives;


void MX_USB_HID_DEVICE_Init(void);
void MX_USB_HID_DEVICE_DeInit(void);
directives parseDirectives(char* string);
Key* prepareKeys(char* string);
void prepareKey(char character, Key* k);
void sendKeys(Key* keys, int size);
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

#endif /* __USB_HID_DEVICE__H__ */
