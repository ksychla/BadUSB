#include "usbd_storage_if.h"


#define STORAGE_LUN_NBR                  1
#define STORAGE_BLK_NBR                  0x10000
#define STORAGE_BLK_SIZ                  0x200

const int8_t STORAGE_Inquirydata_FS[] = {/* 36 */

  /* LUN 0 */
  0x00,
  0x80,
  0x02,
  0x02,
  (STANDARD_INQUIRY_DATA_LEN - 5),
  0x00,
  0x00,
  0x00,
  'S', 'T', 'M', ' ', ' ', ' ', ' ', ' ', /* Manufacturer : 8 bytes */
  'P', 'r', 'o', 'd', 'u', 'c', 't', ' ', /* Product      : 16 Bytes */
  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
  '0', '.', '0' ,'1'                      /* Version      : 4 Bytes */
};


extern USBD_HandleTypeDef mscUsbDeviceFS;

static int8_t STORAGE_Init_FS(uint8_t lun);
static int8_t STORAGE_GetCapacity_FS(uint8_t lun, uint32_t *block_num, uint16_t *block_size);
static int8_t STORAGE_IsReady_FS(uint8_t lun);
static int8_t STORAGE_IsWriteProtected_FS(uint8_t lun);
static int8_t STORAGE_Read_FS(uint8_t lun, uint8_t *buf, uint32_t blk_addr, uint16_t blk_len);
static int8_t STORAGE_Write_FS(uint8_t lun, uint8_t *buf, uint32_t blk_addr, uint16_t blk_len);
static int8_t STORAGE_GetMaxLun_FS(void);


USBD_StorageTypeDef USBD_Storage_Interface_fops_FS = {
  STORAGE_Init_FS,
  STORAGE_GetCapacity_FS,
  STORAGE_IsReady_FS,
  STORAGE_IsWriteProtected_FS,
  STORAGE_Read_FS,
  STORAGE_Write_FS,
  STORAGE_GetMaxLun_FS,
  (int8_t *)STORAGE_Inquirydata_FS
};

int8_t STORAGE_Init_FS(uint8_t lun) {
  UNUSED(lun);
  return (USBD_OK);
}

int8_t STORAGE_GetCapacity_FS(uint8_t lun, uint32_t *block_num, uint16_t *block_size) {
  HAL_SD_CardInfoTypeDef info;
  int8_t ret = -1;

  HAL_SD_GetCardInfo(&hsd, &info);

  *block_num =  info.LogBlockNbr  - 1;
  *block_size = info.LogBlockSize;
  ret = 0;
  return ret;
}

int8_t STORAGE_IsReady_FS(uint8_t lun) {
  UNUSED(lun);
  return (USBD_OK);
}

int8_t STORAGE_IsWriteProtected_FS(uint8_t lun) {
  UNUSED(lun);
  return (USBD_OK);
}

int8_t STORAGE_Read_FS(uint8_t lun, uint8_t *buf, uint32_t blk_addr, uint16_t blk_len) {
  int8_t ret = -1;

  HAL_SD_ReadBlocks(&hsd, buf, blk_addr, blk_len, HAL_MAX_DELAY);

  while (HAL_SD_GetCardState(&hsd) != HAL_SD_CARD_TRANSFER){}
  ret = 0;
  return ret;
}

int8_t STORAGE_Write_FS(uint8_t lun, uint8_t *buf, uint32_t blk_addr, uint16_t blk_len) {
  int8_t ret = -1;

  HAL_SD_WriteBlocks(&hsd, buf, blk_addr, blk_len, HAL_MAX_DELAY);

  while (HAL_SD_GetCardState(&hsd) != HAL_SD_CARD_TRANSFER){}
  ret = 0;
  return ret;
}

int8_t STORAGE_GetMaxLun_FS(void) {
  return (STORAGE_LUN_NBR - 1);
}
