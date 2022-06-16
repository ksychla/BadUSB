#include "usbd_core.h"
#include "usbd_msc_desc.h"
#include "usbd_conf.h"
#include "usb_common.h"


#define USBD_MSC_VID     1155
#define USBD_MSC_LANGID_STRING     1033
#define USBD_MSC_MANUFACTURER_STRING     "STMicroelectronics"
#define USBD_MSC_PID_FS     22314
#define USBD_MSC_PRODUCT_STRING_FS     "STM32 Mass Storage"
#define USBD_MSC_CONFIGURATION_STRING_FS     "MSC Config"
#define USBD_MSC_INTERFACE_STRING_FS     "MSC Interface"

#define USB_MSC_SIZ_BOS_DESC            0x0C


static void Get_MSC_SerialNum(void);

uint8_t* USBD_FS_MSC_DeviceDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t* USBD_FS_MSC_LangIDStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t* USBD_FS_MSC_ManufacturerStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t* USBD_FS_MSC_ProductStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t* USBD_FS_MSC_SerialStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t* USBD_FS_MSC_ConfigStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t* USBD_FS_MSC_InterfaceStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
#if (USBD_LPM_ENABLED == 1)
uint8_t * USBD_FS_USR_BOSDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
#endif /* (USBD_LPM_ENABLED == 1) */


USBD_DescriptorsTypeDef FS_MSC_Desc = {
  USBD_FS_MSC_DeviceDescriptor
, USBD_FS_MSC_LangIDStrDescriptor
, USBD_FS_MSC_ManufacturerStrDescriptor
, USBD_FS_MSC_ProductStrDescriptor
, USBD_FS_MSC_SerialStrDescriptor
, USBD_FS_MSC_ConfigStrDescriptor
, USBD_FS_MSC_InterfaceStrDescriptor
#if (USBD_LPM_ENABLED == 1)
, USBD_FS_USR_BOSDescriptor
#endif /* (USBD_LPM_ENABLED == 1) */
};

#if defined ( __ICCARM__ ) /* IAR Compiler */
  #pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */
/** USB standard device descriptor. */
__ALIGN_BEGIN uint8_t USBD_FS_MSC_DeviceDesc[USB_LEN_DEV_DESC] __ALIGN_END = {
  0x12,                       /*bLength */
  USB_DESC_TYPE_DEVICE,       /*bDescriptorType*/
#if (USBD_LPM_ENABLED == 1)
  0x01,                       /*bcdUSB */ /* changed to USB version 2.01
                                             in order to support LPM L1 suspend
                                             resume test of USBCV3.0*/
#else
  0x00,                       /*bcdUSB */
#endif /* (USBD_LPM_ENABLED == 1) */
  0x02,
  0x00,                       /*bDeviceClass*/
  0x00,                       /*bDeviceSubClass*/
  0x00,                       /*bDeviceProtocol*/
  USB_MAX_EP0_SIZE,           /*bMaxPacketSize*/
  LOBYTE(USBD_MSC_VID),           /*idVendor*/
  HIBYTE(USBD_MSC_VID),           /*idVendor*/
  LOBYTE(USBD_MSC_PID_FS),        /*idProduct*/
  HIBYTE(USBD_MSC_PID_FS),        /*idProduct*/
  0x00,                       /*bcdDevice rel. 2.00*/
  0x02,
  USBD_IDX_MFC_STR,           /*Index of manufacturer  string*/
  USBD_IDX_PRODUCT_STR,       /*Index of product string*/
  USBD_IDX_SERIAL_STR,        /*Index of serial number string*/
  USBD_MAX_NUM_CONFIGURATION  /*bNumConfigurations*/
};

/* USB_DeviceDescriptor */
/** BOS descriptor. */
#if (USBD_LPM_ENABLED == 1)
#if defined ( __ICCARM__ ) /* IAR Compiler */
  #pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */
__ALIGN_BEGIN uint8_t USBD_FS_BOSDesc[USB_MSC_SIZ_BOS_DESC] __ALIGN_END =
{
  0x5,
  USB_DESC_TYPE_BOS,
  0xC,
  0x0,
  0x1,  /* 1 device capability*/
        /* device capability*/
  0x7,
  USB_DEVICE_CAPABITY_TYPE,
  0x2,
  0x2,  /* LPM capability bit set*/
  0x0,
  0x0,
  0x0
};
#endif /* (USBD_LPM_ENABLED == 1) */

#if defined ( __ICCARM__ ) /* IAR Compiler */
  #pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */

/** USB lang identifier descriptor. */
__ALIGN_BEGIN uint8_t USBD_MSC_LangIDDesc[USB_LEN_LANGID_STR_DESC] __ALIGN_END = {
     USB_LEN_LANGID_STR_DESC,
     USB_DESC_TYPE_STRING,
     LOBYTE(USBD_MSC_LANGID_STRING),
     HIBYTE(USBD_MSC_LANGID_STRING)
};

#if defined ( __ICCARM__ ) /* IAR Compiler */
  #pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */
/* Internal string descriptor. */
__ALIGN_BEGIN uint8_t USBD_MSC_StrDesc[USBD_MAX_STR_DESC_SIZ] __ALIGN_END;

#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4
#endif
__ALIGN_BEGIN uint8_t USBD_MSC_StringSerial[USB_SIZ_STRING_SERIAL] __ALIGN_END = {
  USB_SIZ_STRING_SERIAL,
  USB_DESC_TYPE_STRING,
};


uint8_t* USBD_FS_MSC_DeviceDescriptor(USBD_SpeedTypeDef speed, uint16_t* length) {
  UNUSED(speed);
  *length = sizeof(USBD_FS_MSC_DeviceDesc);
  return USBD_FS_MSC_DeviceDesc;
}

uint8_t* USBD_FS_MSC_LangIDStrDescriptor(USBD_SpeedTypeDef speed, uint16_t* length) {
  UNUSED(speed);
  *length = sizeof(USBD_MSC_LangIDDesc);
  return USBD_MSC_LangIDDesc;
}

uint8_t* USBD_FS_MSC_ProductStrDescriptor(USBD_SpeedTypeDef speed, uint16_t* length) {
  if(speed == 0) {
    USBD_GetString((uint8_t*)USBD_MSC_PRODUCT_STRING_FS, USBD_MSC_StrDesc, length);
  } else {
    USBD_GetString((uint8_t*)USBD_MSC_PRODUCT_STRING_FS, USBD_MSC_StrDesc, length);
  }
  return USBD_MSC_StrDesc;
}

uint8_t* USBD_FS_MSC_ManufacturerStrDescriptor(USBD_SpeedTypeDef speed, uint16_t* length) {
  UNUSED(speed);
  USBD_GetString((uint8_t*)USBD_MSC_MANUFACTURER_STRING, USBD_MSC_StrDesc, length);
  return USBD_MSC_StrDesc;
}

uint8_t* USBD_FS_MSC_SerialStrDescriptor(USBD_SpeedTypeDef speed, uint16_t* length) {
  UNUSED(speed);
  *length = USB_SIZ_STRING_SERIAL;

  Get_MSC_SerialNum();
  return (uint8_t*) USBD_MSC_StringSerial;
}

uint8_t* USBD_FS_MSC_ConfigStrDescriptor(USBD_SpeedTypeDef speed, uint16_t* length) {
  if(speed == USBD_SPEED_HIGH) {
    USBD_GetString((uint8_t*)USBD_MSC_CONFIGURATION_STRING_FS, USBD_MSC_StrDesc, length);
  } else {
    USBD_GetString((uint8_t*)USBD_MSC_CONFIGURATION_STRING_FS, USBD_MSC_StrDesc, length);
  }
  return USBD_MSC_StrDesc;
}

uint8_t* USBD_FS_MSC_InterfaceStrDescriptor(USBD_SpeedTypeDef speed, uint16_t* length) {
  if(speed == 0) {
    USBD_GetString((uint8_t*)USBD_MSC_INTERFACE_STRING_FS, USBD_MSC_StrDesc, length);
  } else {
    USBD_GetString((uint8_t*)USBD_MSC_INTERFACE_STRING_FS, USBD_MSC_StrDesc, length);
  }
  return USBD_MSC_StrDesc;
}

#if (USBD_LPM_ENABLED == 1)
/**
  * @brief  Return the BOS descriptor
  * @param  speed : Current device speed
  * @param  length : Pointer to data length variable
  * @retval Pointer to descriptor buffer
  */
uint8_t * USBD_FS_USR_BOSDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
  UNUSED(speed);
  *length = sizeof(USBD_FS_BOSDesc);
  return (uint8_t*)USBD_FS_BOSDesc;
}
#endif /* (USBD_LPM_ENABLED == 1) */

static void Get_MSC_SerialNum(void) {
  uint32_t deviceserial0, deviceserial1, deviceserial2;

  deviceserial0 = *(uint32_t*) DEVICE_ID1;
  deviceserial1 = *(uint32_t*) DEVICE_ID2;
  deviceserial2 = *(uint32_t*) DEVICE_ID3;

  deviceserial0 += deviceserial2;

  if (deviceserial0 != 0)
  {
    IntToUnicode(deviceserial0, &USBD_MSC_StringSerial[2], 8);
    IntToUnicode(deviceserial1, &USBD_MSC_StringSerial[18], 4);
  }
}
