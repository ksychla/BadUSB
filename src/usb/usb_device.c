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

void typeString(char* string) {
  keyboardHID* keyboardhid = (keyboardHID*) calloc(1, sizeof(keyboardHID));
  char* charsToSend = calloc(6, sizeof(char));
  uint8_t charsToSendIndex = 0;
  uint8_t currentModifier = 0;
  for (int i = 0; i < strlen(string); i++) {
    char lowerCharacter = toLower(string[i]);
    if (isCharInArray(lowerCharacter, charsToSend, 6) >= 0 
        || (charsToSendIndex > 0 && (lowerCharacter != string[i]) != (currentModifier & 0x02) >> 1)
        || charsToSendIndex > 5) {
      prepareKeyboardHID(keyboardhid, charsToSend, currentModifier);
      sendKeyPress(keyboardhid);
      memset(charsToSend, 0, 6);
      charsToSendIndex = 0;
      currentModifier = 0;
    }
    if (lowerCharacter != string[i]) {
      currentModifier = 0x02;
    }
    charsToSend[charsToSendIndex] = lowerCharacter;
    charsToSendIndex++;
  }
  prepareKeyboardHID(keyboardhid, charsToSend, currentModifier);
  sendKeyPress(keyboardhid);

  free(keyboardhid);
  free(charsToSend);
}

int8_t isCharInArray(char c, char* array, int size) {
  for (int i = 0; i < size; i++) {
    if (c == array[i]) {
      return i;
    }
  }
  return -1;
}

void sendKeyPress(keyboardHID* keyboardhid) {
  USBD_HID_SendReport(&hUsbDeviceFS, keyboardhid, sizeof(keyboardHID));
  HAL_Delay(2);
  keyboardhid->MODIFIER = 0x0;
  keyboardhid->KEYCODE1 = 0x0;
  keyboardhid->KEYCODE2 = 0x0;
  keyboardhid->KEYCODE3 = 0x0;
  keyboardhid->KEYCODE4 = 0x0;
  keyboardhid->KEYCODE5 = 0x0;
  keyboardhid->KEYCODE6 = 0x0;
  USBD_HID_SendReport(&hUsbDeviceFS, keyboardhid, sizeof(keyboardHID));
  HAL_Delay(2);
}

uint8_t encodeKey(char character) {
  if (character >= 0x61 && character <= 0x7A) {
    return character - 0x61 + 0x04;
  }
  if (character >= 0x31 && character <= 0x39) {
    return character - 0x31 + 0x1E;
  }
  if (character == 0x30) {
    return 0x27;
  }

  switch (character) {
    case ' ':
      return 0x2c;
    case '\n':
      return 0x28;
    case '\t':
      return 0x2b;
    case '/':
      return 0x38;
    case '\\':
      return 0x31;
    case ',':
      return 0x36;
    case '.':
      return 0x37;
    case '-':
      return 0x2d;
    case '=':
      return 0x2e;
    case '[':
      return 0x2f;
    case ']':
      return 0x30;
    case '`':
      return 0x32;
  }
  return 0x0;
}

void prepareKeyboardHID(keyboardHID* keyboardhid, char* charactersToSend, uint8_t currentModifier) {
  keyboardhid->MODIFIER = currentModifier;
  keyboardhid->KEYCODE1 = encodeKey(charactersToSend[0]);
  keyboardhid->KEYCODE2 = encodeKey(charactersToSend[1]);
  keyboardhid->KEYCODE3 = encodeKey(charactersToSend[2]);
  keyboardhid->KEYCODE4 = encodeKey(charactersToSend[3]);
  keyboardhid->KEYCODE5 = encodeKey(charactersToSend[4]);
  keyboardhid->KEYCODE6 = encodeKey(charactersToSend[5]);
}

char toLower(char character) {
  if (character >= 0x41 && character <= 0x5A) {
    return character + 0x20;
  }
  char* upperCase = "!@#$%^&*()_+{}|:\"<>?~";
  char* lowerCase = "1234567890-=[]\\;\',./`";
  int8_t index = isCharInArray(character, upperCase, strlen(upperCase));
  if (index >= 0) {
    return lowerCase[index];
  }
  return character;
}