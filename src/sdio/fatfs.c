#include "fatfs.h"

uint8_t retSD;    /* Return value for SD */
char SDPath[4];   /* SD logical drive path */
FATFS SDFatFS;    /* File system object for SD logical drive */
FIL SDFile;       /* File object for SD */


void MX_FATFS_Init(void) {
  retSD = FATFS_LinkDriver(&SD_Driver, SDPath);
}

void MX_FATFS_DeInit(void) {
  FATFS_UnLinkDriver(SDPath);
}

DWORD get_fattime(void) {
  return 0;
}
