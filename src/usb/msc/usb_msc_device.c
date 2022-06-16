#include "usb_msc_device.h"
#include "usbd_core.h"
#include "usbd_msc_desc.h"
#include "usbd_msc.h"
#include "usbd_storage_if.h"

USBD_HandleTypeDef mscUsbDeviceFS;


void MX_USB_MSC_DEVICE_Init(void) {
  if (USBD_Init(&mscUsbDeviceFS, &FS_MSC_Desc, DEVICE_FS) != USBD_OK) {
    Error_Handler();
  }
  if (USBD_RegisterClass(&mscUsbDeviceFS, &USBD_MSC) != USBD_OK) {
    Error_Handler();
  }
  if (USBD_MSC_RegisterStorage(&mscUsbDeviceFS, &USBD_Storage_Interface_fops_FS) != USBD_OK) {
    Error_Handler();
  }
  if (USBD_Start(&mscUsbDeviceFS) != USBD_OK) {
    Error_Handler();
  }
}
