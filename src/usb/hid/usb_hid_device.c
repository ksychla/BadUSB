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
  uint8_t keysToSend[REPORT_KEY_NUM] = {0};
  uint16_t keysToSendIndex = 0;
  uint8_t currentModifier = 0;
  for (i = 0; i < size; i++) {
    if (isCharInArray(keys[i].KEYCODE, keysToSend, REPORT_KEY_NUM) >= 0 
        || (keysToSendIndex > 0 && keys[i].MODIFIER != currentModifier)
        || keysToSendIndex > REPORT_KEY_NUM - 1) {
      OPTprepareKeyboardHID(keyboardhid, keysToSend, currentModifier);
      sendKeyPress(keyboardhid);
      memset(keysToSend, 0, REPORT_KEY_NUM * sizeof(uint8_t));
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
  keyboardhid->MODIFIER = KEY_MOD_LMETA;
  keyboardhid->KEYCODES[0] = KEY_R;
  sendKeyPress(keyboardhid);
  HAL_Delay(50);
  keyboardhid->KEYCODES[0] = KEY_C;
  keyboardhid->KEYCODES[1] = KEY_M;
  keyboardhid->KEYCODES[2] = KEY_D;
  keyboardhid->KEYCODES[3] = KEY_ENTER;
  sendKeyPress(keyboardhid);
  
  // MacOS
  // keyboardhid->MODIFIER = KEY_MOD_LMETA;
  // keyboardhid->KEYCODES[0] = KEY_SPACE;
  // sendKeyPress(keyboardhid);
  // HAL_Delay(40);
  // keyboardhid->KEYCODES[0] = KEY_T;
  // keyboardhid->KEYCODES[1] = KEY_E;
  // keyboardhid->KEYCODES[2] = KEY_R;
  // keyboardhid->KEYCODES[3] = KEY_M;
  // keyboardhid->KEYCODES[4] = KEY_I;
  // keyboardhid->KEYCODES[5] = KEY_N;
  // sendKeyPress(keyboardhid);
  // keyboardhid->KEYCODES[0] = KEY_A;
  // keyboardhid->KEYCODES[1] = KEY_L;
  // keyboardhid->KEYCODES[2] = KEY_ENTER;
  // sendKeyPress(keyboardhid);

  // Linux
  keyboardhid->MODIFIER = KEY_MOD_LCTRL | KEY_MOD_LALT;
  keyboardhid->KEYCODES[0] = KEY_T;
  sendKeyPress(keyboardhid);

  HAL_Delay(200);
  free(keyboardhid);
}

void closeShell() {
  keyboardHID* keyboardhid = (keyboardHID*) calloc(1, sizeof(keyboardHID));
  // exit\n
  keyboardhid->KEYCODES[0] = KEY_E;
  keyboardhid->KEYCODES[1] = KEY_X;
  keyboardhid->KEYCODES[2] = KEY_I;
  keyboardhid->KEYCODES[3] = KEY_T;
  keyboardhid->KEYCODES[4] = KEY_ENTER;
  sendKeyPress(keyboardhid);

  // win + q MacOS
  // keyboardhid->MODIFIER = KEY_MOD_LMETA;
  // keyboardhid->KEYCODES[0] = KEY_Q;
  // sendKeyPress(keyboardhid);

  free(keyboardhid);
}

void typeString(char* string) {
  keyboardHID* keyboardhid = (keyboardHID*) calloc(1, sizeof(keyboardHID));
  char* charsToSend = calloc(REPORT_KEY_NUM, sizeof(char));
  uint8_t charsToSendIndex = 0;
  uint8_t currentModifier = 0;
  for (int i = 0; i < strlen(string); i++) {
    char lowerCharacter = toLower(string[i]);
    if (isCharInArray(lowerCharacter, charsToSend, REPORT_KEY_NUM) >= 0
        || (charsToSendIndex > 0 && (lowerCharacter != string[i]) != (currentModifier & 0x02) >> 1)
        || charsToSendIndex > REPORT_KEY_NUM - 1) {
      prepareKeyboardHID(keyboardhid, charsToSend, currentModifier);
      sendKeyPress(keyboardhid);
      memset(charsToSend, 0, REPORT_KEY_NUM * sizeof(char));
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
  memset(keyboardhid->KEYCODES, 0, REPORT_KEY_NUM * sizeof(uint8_t));
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
  int i;
  for (i = 0; i < REPORT_KEY_NUM; i++) {
      keyboardhid->KEYCODES[i] = encodeKey(charactersToSend[i]);
  }
}

void OPTprepareKeyboardHID(keyboardHID* keyboardhid, uint8_t* charactersToSend, uint8_t currentModifier) {
  keyboardhid->MODIFIER = currentModifier;
  int i;
  for (i = 0; i < REPORT_KEY_NUM; i++) {
      keyboardhid->KEYCODES[i] = charactersToSend[i];
  }
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
