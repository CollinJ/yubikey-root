#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libusb-1.0/libusb.h>

#define YUBIKEY_MANUFACTURER  0x08ee
#define YUBIKEY_PRODUCTID  0x0021

int main(int argc, char** argv) {

libusb_device **devList = NULL;
libusb_device *devPtr = NULL;
libusb_device_handle *devHandle = NULL;
struct libusb_device_descriptor devDesc;
struct libusb_config_descriptor *configDesc;
unsigned char strDesc[256];
int retVal = 0;

ssize_t numUsbDevs = 0;
ssize_t idx = 0;
libusb_context *ctx = NULL;
retVal = libusb_init(&ctx);
if (retVal < 0) {
    printf("%d", retVal);
    return 1;
  }

numUsbDevs = libusb_get_device_list (ctx, &devList);

while (idx < numUsbDevs) {
  devPtr = devList[idx];

  retVal = libusb_open(devPtr, &devHandle);
  if( retVal != LIBUSB_SUCCESS)
    break;
  retVal = libusb_get_device_descriptor (devPtr, &devDesc);
  if( retVal != LIBUSB_SUCCESS)
    break;

  
}

}
