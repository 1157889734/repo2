/******************** (C) COPYRIGHT 2009 STMicroelectronics ********************
* File Name          : usb_desc.c
* Author             : MCD Application Team
* Version            : V3.0.0
* Date               : 04/06/2009
* Description        : Descriptors for Joystick Mouse Demo
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* USB Standard Device Descriptor */
const uint8_t Joystick_DeviceDescriptor[JOYSTICK_SIZ_DEVICE_DESC] =
  {
#if 0
    0x12,                       /*bLength */
    USB_DEVICE_DESCRIPTOR_TYPE, /*bDescriptorType*/
    0x00,                       /*bcdUSB */
    0x02,
    0x00,                       /*bDeviceClass*/
    0x00,                       /*bDeviceSubClass*/
    0x00,                       /*bDeviceProtocol*/
    0x40,                       /*bMaxPacketSize40*/
    0x83,                       /*idVendor (0x0483)*/
    0x04,
    0x10,                       /*idProduct = 0x5710*/
    0x57,
    0x00,                       /*bcdDevice rel. 2.00*/
    0x02,
    1,                          /*Index of string descriptor describing
                                                  manufacturer */
    2,                          /*Index of string descriptor describing
                                                 product*/
    3,                          /*Index of string descriptor describing the
                                                 device serial number */
    0x01                        /*bNumConfigurations*/
#endif 
       0x12,                       /*bLength */
        USB_DEVICE_DESCRIPTOR_TYPE, /*bDescriptorType*/
        0x00,                       /*bcdUSB */
        0x01,
        0x00,                       /*bDeviceClass*/
        0x00,                       /*bDeviceSubClass*/
        0x00,                       /*bDeviceProtocol*/
        0x40,                       /*bMaxPacketSize40*/
        0xB4,//0x83,                       /*idVendor (0x0483)*/
        0x04,
        0x00,//0x10,                       /*idProduct = 0x5710*/
        0x00,//0x57,
        0x88,//0x00,                       /*bcdDevice rel. 2.00*/
        0x02,
        1,                          /*Index of string descriptor describing
                                                      manufacturer */
        2,                          /*Index of string descriptor describing
                                                     product*/
        3,                          /*Index of string descriptor describing the
                                                     device serial number */
        0x01                        /*bNumConfigurations*/

  }
  ; /* Joystick_DeviceDescriptor */


/* USB Configuration Descriptor */
/*   All Descriptors (Configuration, Interface, Endpoint, Class, Vendor */
const uint8_t Joystick_ConfigDescriptor[JOYSTICK_SIZ_CONFIG_DESC] =
  {
    0x09, /* bLength: Configuation Descriptor size */
    USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType: Configuration */
    JOYSTICK_SIZ_CONFIG_DESC,
    /* wTotalLength: Bytes returned */
    0x00,
    0x01,         /*bNumInterfaces: 1 interface*/
    0x01,         /*bConfigurationValue: Configuration value*/
    0x00,         /*iConfiguration: Index of string descriptor describing
                                     the configuration*/
    0x40,//0xE0,//         /*bmAttributes: bus powered */
    0x32,         /*MaxPower 100 mA: this current is used for detecting Vbus*/

    /************** Descriptor of Joystick Mouse interface ****************/
    /* 09 */
    0x09,         /*bLength: Interface Descriptor size*/
    USB_INTERFACE_DESCRIPTOR_TYPE,/*bDescriptorType: Interface descriptor type*/
    0x00,         /*bInterfaceNumber: Number of Interface*/
    0x00,         /*bAlternateSetting: Alternate setting*/
   // 0x01,         /*bNumEndpoints*/
    0x02,
    0x03,         /*bInterfaceClass: HID*/
    0x01,         /*bInterfaceSubClass : 1=BOOT, 0=no boot*/
    0x02,         /*nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse*/
    0,            /*iInterface: Index of string descriptor*/
    /******************** Descriptor of Joystick Mouse HID ********************/
    /* 18 */
    0x09,         /*bLength: HID Descriptor size*/
    HID_DESCRIPTOR_TYPE, /*bDescriptorType: HID*/
    0x00,         /*bcdHID: HID Class Spec release number*/
    0x01,
    0x00,         /*bCountryCode: Hardware target country*/
    0x01,         /*bNumDescriptors: Number of HID class descriptors to follow*/
    0x22,         /*bDescriptorType*/
    JOYSTICK_SIZ_REPORT_DESC,/*wItemLength: Total length of Report descriptor*/
    0x00,
    /******************** Descriptor of Joystick Mouse endpoint ********************/
    /* 27 */
    0x07,          /*bLength: Endpoint Descriptor size*/
    USB_ENDPOINT_DESCRIPTOR_TYPE, /*bDescriptorType:*/

    0x81,          /*bEndpointAddress: Endpoint Address (IN)*/
    0x03,          /*bmAttributes: Interrupt endpoint*/
    //0x04,          /*wMaxPacketSize: 4 Byte max */
    0x10,
    0x00,
  //  0x20,          /*bInterval: Polling Interval (32 ms)*/
    0x01,
    /* 34 */
#if 1
    0x07,          /*bLength: Endpoint Descriptor size*/
    USB_ENDPOINT_DESCRIPTOR_TYPE, /*bDescriptorType:*/

    0x01,          /*bEndpointAddress: Endpoint Address (IN)*/
    0x03,          /*bmAttributes: Interrupt endpoint*/
//    0x04,          /*wMaxPacketSize: 4 Byte max */
    0x10,
    0x00,
//    0x20,          /*bInterval: Polling Interval (32 ms)*/
    0x01,
    /* 41 */
#endif
  }
  ; /* MOUSE_ConfigDescriptor */
const uint8_t Joystick_ReportDescriptor[JOYSTICK_SIZ_REPORT_DESC] =
  {
#if 0
    0x05,          /*Usage Page(Generic Desktop)*/
    0x01,
    0x09,          /*Usage(Mouse)*/
    0x02,
    0xA1,          /*Collection(Logical)*/
    0x01,
    0x09,          /*Usage(Pointer)*/
    0x01,
    /* 8 */
    0xA1,          /*Collection(Linked)*/
    0x00,
    0x05,          /*Usage Page(Buttons)*/
    0x09,
    0x19,          /*Usage Minimum(1)*/
    0x01,
    0x29,          /*Usage Maximum(3)*/
    0x03,
    /* 16 */
    0x15,          /*Logical Minimum(0)*/
    0x00,
    0x25,          /*Logical Maximum(1)*/
    0x01,
    0x95,          /*Report Count(3)*/
    0x03,
    0x75,          /*Report Size(1)*/
    0x01,
    /* 24 */
    0x81,          /*Input(Variable)*/
    0x02,
    0x95,          /*Report Count(1)*/
    0x01,
    0x75,          /*Report Size(5)*/
    0x05,
    0x81,          /*Input(Constant,Array)*/
    0x01,
    /* 32 */
    0x05,          /*Usage Page(Generic Desktop)*/
    0x01,
    0x09,          /*Usage(X axis)*/
    0x30,
    0x09,          /*Usage(Y axis)*/
    0x31,
    0x09,          /*Usage(Wheel)*/
    0x38,
    /* 40 */
    0x15,          /*Logical Minimum(-127)*/
    0x81,
    0x25,          /*Logical Maximum(127)*/
    0x7F,
    0x75,          /*Report Size(8)*/
    0x08,
    0x95,          /*Report Count(3)*/
    0x03,
    /* 48 */
    0x81,          /*Input(Variable, Relative)*/
    0x06,
    0xC0,          /*End Collection*/
    0x09,
    0x3c,
    0x05,
    0xff,
    0x09,
    /* 56 */
    0x01,
    0x15,
    0x00,
    0x25,
    0x01,
    0x75,
    0x01,
    0x95,
    /* 64 */
    0x02,
    0xb1,
    0x22,
    0x75,
    0x06,
    0x95,
    0x01,
    0xb1,
    /* 72 */
    0x01,
    0xc0
#endif 
    0x05, 0x0c,			// 应用设备类型
    0x09, 0x01,			// 应用类型
    0x15, 0x81,			// 逻辑最小值
    0x25, 0x7f,			// 逻辑最大值
            
    0xa1, 0x01,			// 应用集合开始标志
    0x09, 0x30,			// 发送包应用类型
    0x75, 0x08,			// 发送单位大小 (8bit)
    0x95, 0x0A,	// 发送单位数量 (8*8bit)
    0x81, 0x02,			// 发送类型标志
    0x09, 0x30,			// 接收包应用类型
    0x75, 0x08,			// 接收单位大小 (8bit)
    0x95, 0x0A,	// 接收单位数量 (8*8bit)
    0x91, 0x02,			// 接收类型标志
    0xc0,		    		// 应用集合结束标志

  }
  ; /* Joystick_ReportDescriptor */

/* USB String Descriptors (optional) */
const uint8_t Joystick_StringLangID[JOYSTICK_SIZ_STRING_LANGID] =
  {
    JOYSTICK_SIZ_STRING_LANGID,
    USB_STRING_DESCRIPTOR_TYPE,
    0x09,
    0x04
  }
  ; /* LangID = 0x0409: U.S. English */

const uint8_t Joystick_StringVendor[JOYSTICK_SIZ_STRING_VENDOR] =
  {
    JOYSTICK_SIZ_STRING_VENDOR, /* Size of Vendor string */
    USB_STRING_DESCRIPTOR_TYPE,  /* bDescriptorType*/
    /* Manufacturer: "STMicroelectronics" */
    'S', 0, 'T', 0, 'M', 0, 'i', 0, 'c', 0, 'r', 0, 'o', 0, 'e', 0,
    'l', 0, 'e', 0, 'c', 0, 't', 0, 'r', 0, 'o', 0, 'n', 0, 'i', 0,
    'c', 0, 's', 0
  };

const uint8_t Joystick_StringProduct[JOYSTICK_SIZ_STRING_PRODUCT] =
  {
    JOYSTICK_SIZ_STRING_PRODUCT,          /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, ' ', 0, 'J', 0,
    'o', 0, 'y', 0, 's', 0, 't', 0, 'i', 0, 'c', 0, 'k', 0
  };
uint8_t Joystick_StringSerial[JOYSTICK_SIZ_STRING_SERIAL] =
  {
    JOYSTICK_SIZ_STRING_SERIAL,           /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, '1', 0, '0', 0
  };

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/

