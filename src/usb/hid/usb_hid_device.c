#include <string.h>

#include "usb_hid_device.h"
#include "usbd_core.h"
#include "usbd_hid_desc.h"
#include "usbd_hid.h"
#include "usb_keyboard.h"

USBD_HandleTypeDef hidUsbDeviceFS;


void MX_USB_HID_DEVICE_Init(void) {
  if (USBD_Init(&hidUsbDeviceFS, &FS_HID_Desc, DEVICE_FS) != USBD_OK) {
    Error_Handler();
  }
  if (USBD_RegisterClass(&hidUsbDeviceFS, &USBD_HID) != USBD_OK) {
    Error_Handler();
  }
  if (USBD_Start(&hidUsbDeviceFS) != USBD_OK) {
    Error_Handler();
  }

}

void MX_USB_HID_DEVICE_DeInit(void) {
  if (USBD_Stop(&hidUsbDeviceFS) != USBD_OK) {
    Error_Handler();
  }
  if (USBD_DeInit(&hidUsbDeviceFS) != USBD_OK) {
    Error_Handler();
  }
}

directives parseDirectives(char* string) {
  directives dirs;
  dirs.numberOfBytes = 0;
  while (1) {
    if (!strncmp(string, "@@", 2) == 0) {
      return dirs;
    }

    if (strncmp(string, NOSHELL, strlen(NOSHELL)) == 0) {
      dirs.noshell = TRUE;
      dirs.numberOfBytes += strlen(NOSHELL) + 1;
      string += strlen(NOSHELL) + 1;
      continue;
    }

    if (strncmp(string, ONELINE, strlen(ONELINE)) == 0) {
      dirs.oneline = TRUE;
      dirs.numberOfBytes += strlen(ONELINE) + 1;
      string += strlen(ONELINE) + 1;
      continue;
    }
  }
}

Key* prepareKeys(char* string) {
  Key* keys = (Key*)malloc(sizeof(Key) * strlen(string));
  int i;
  for (i = 0; i < strlen(string); i++) {
    prepareKey(string[i], &keys[i]);
  }
  return keys;
}

void sendKeys(Key* keys, int size) {
  int i;
  keyboardHID* keyboardhid = (keyboardHID*) calloc(1, sizeof(keyboardHID));
  uint8_t keysToSend[6] = {0};
  uint16_t keysToSendIndex = 0;
  uint8_t currentModifier = 0;
  for (i = 0; i < size; i++) {
    if (isCharInArray(keys[i].KEYCODE, keysToSend, 6) >= 0 
        || (keysToSendIndex > 0 && keys[i].MODIFIER != currentModifier)
        || keysToSendIndex > 5) {
      OPTprepareKeyboardHID(keyboardhid, keysToSend, currentModifier);
      sendKeyPress(keyboardhid);
      memset(keysToSend, 0, 6);
      keysToSendIndex = 0;
      currentModifier = 0;
    }
    keysToSend[keysToSendIndex] = keys[i].KEYCODE;
    currentModifier = keys[i].MODIFIER;
    keysToSendIndex++;
  }
  OPTprepareKeyboardHID(keyboardhid, keysToSend, currentModifier);
  sendKeyPress(keyboardhid);

  free(keyboardhid);
}

void prepareKey(char character, Key* k) {
  char lowerCharacter = toLower(character);
  k->MODIFIER = 0;
  k->KEYCODE = encodeKey(lowerCharacter);
  if (lowerCharacter != character) {
    k->MODIFIER = 0x02;
  }

}

void openShell() {
  keyboardHID* keyboardhid = (keyboardHID*) calloc(1, sizeof(keyboardHID));
  // Windows
  // keyboardhid->MODIFIER = KEY_MOD_LMETA;
  // keyboardhid->KEYCODE1 = KEY_R;
  // sendKeyPress(keyboardhid);
  // HAL_Delay(40);
  // keyboardhid->KEYCODE1 = KEY_C;
  // keyboardhid->KEYCODE2 = KEY_M;
  // keyboardhid->KEYCODE3 = KEY_D;
  // keyboardhid->KEYCODE4 = KEY_SPACE;
  // keyboardhid->KEYCODE5 = KEY_SLASH;
  // sendKeyPress(keyboardhid);
  // keyboardhid->KEYCODE1 = KEY_C;
  // keyboardhid->KEYCODE2 = KEY_ENTER;
  // sendKeyPress(keyboardhid);

  // MacOS
  // keyboardhid->MODIFIER = KEY_MOD_LMETA;
  // keyboardhid->KEYCODE1 = KEY_SPACE;
  // sendKeyPress(keyboardhid);
  // HAL_Delay(40);
  // keyboardhid->KEYCODE1 = KEY_T;
  // keyboardhid->KEYCODE2 = KEY_E;
  // keyboardhid->KEYCODE3 = KEY_R;
  // keyboardhid->KEYCODE4 = KEY_M;
  // keyboardhid->KEYCODE5 = KEY_I;
  // keyboardhid->KEYCODE6 = KEY_N;
  // sendKeyPress(keyboardhid);
  // keyboardhid->KEYCODE1 = KEY_A;
  // keyboardhid->KEYCODE2 = KEY_L;
  // keyboardhid->KEYCODE3 = KEY_ENTER;
  // sendKeyPress(keyboardhid);

  // Linux
  keyboardhid->MODIFIER = KEY_MOD_LCTRL | KEY_MOD_LALT;
  keyboardhid->KEYCODE1 = KEY_T;
  sendKeyPress(keyboardhid);

  HAL_Delay(150);
  free(keyboardhid);
}

void closeShell() {
  keyboardHID* keyboardhid = (keyboardHID*) calloc(1, sizeof(keyboardHID));
  // exit\n
  keyboardhid->KEYCODE1 = KEY_E;
  keyboardhid->KEYCODE2 = KEY_X;
  keyboardhid->KEYCODE3 = KEY_I;
  keyboardhid->KEYCODE4 = KEY_T;
  keyboardhid->KEYCODE5 = KEY_ENTER;
  sendKeyPress(keyboardhid);

  // win + q
  keyboardhid->MODIFIER = KEY_MOD_LMETA;
  keyboardhid->KEYCODE1 = KEY_Q;
  sendKeyPress(keyboardhid);

  free(keyboardhid);
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
  USBD_HID_SendReport(&hidUsbDeviceFS, keyboardhid, sizeof(keyboardHID));
  HAL_Delay(2);
  keyboardhid->MODIFIER = 0x0;
  keyboardhid->KEYCODE1 = 0x0;
  keyboardhid->KEYCODE2 = 0x0;
  keyboardhid->KEYCODE3 = 0x0;
  keyboardhid->KEYCODE4 = 0x0;
  keyboardhid->KEYCODE5 = 0x0;
  keyboardhid->KEYCODE6 = 0x0;
  USBD_HID_SendReport(&hidUsbDeviceFS, keyboardhid, sizeof(keyboardHID));
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
      return KEY_SPACE;
    case '\n':
      return KEY_ENTER;
    case '\t':
      return KEY_TAB;
    case '/':
      return KEY_SLASH;
    case '\\':
      return KEY_BACKSLASH;
    case ';':
      return KEY_SEMICOLON;
    case '\'':
      return KEY_APOSTROPHE;
    case ',':
      return KEY_COMMA;
    case '.':
      return KEY_DOT;
    case '-':
      return KEY_MINUS;
    case '=':
      return KEY_EQUAL;
    case '[':
      return KEY_LEFTBRACE;
    case ']':
      return KEY_RIGHTBRACE;
    case '`':
      return KEY_GRAVE;
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

void OPTprepareKeyboardHID(keyboardHID* keyboardhid, uint8_t* charactersToSend, uint8_t currentModifier) {
  keyboardhid->MODIFIER = currentModifier;
  keyboardhid->KEYCODE1 = charactersToSend[0];
  keyboardhid->KEYCODE2 = charactersToSend[1];
  keyboardhid->KEYCODE3 = charactersToSend[2];
  keyboardhid->KEYCODE4 = charactersToSend[3];
  keyboardhid->KEYCODE5 = charactersToSend[4];
  keyboardhid->KEYCODE6 = charactersToSend[5];
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