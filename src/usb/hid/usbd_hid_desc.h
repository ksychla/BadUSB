#ifndef __USBD_DESC__C__
#define __USBD_DESC__C__

#ifdef __cplusplus
 extern "C" {
#endif

#include "usbd_def.h"


#define         DEVICE_HID_ID1          (UID_BASE)
#define         DEVICE_HID_ID2          (UID_BASE + 0x4)
#define         DEVICE_HID_ID3          (UID_BASE + 0x8)

#define  USB_HID_SIZ_STRING_SERIAL       0x1A


extern USBD_DescriptorsTypeDef FS_HID_Desc;


#ifdef __cplusplus
}
#endif

#endif /* __USBD_DESC__C__ */

