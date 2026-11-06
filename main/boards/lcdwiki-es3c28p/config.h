#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

// LCDWiki 2.8inch ESP32-S3 Display (ES3C28P with touch / ES3N28P without touch)
// ESP32-S3 N16R8, ILI9341V 240x320 SPI, FT6336G touch (I2C), ES8311 codec + FM8002E amp,
// 1x MEMS mic, WS2812 RGB LED, microSD (SDIO), TP4054 LiPo charger.
// Pin map: https://www.lcdwiki.com/2.8inch_ESP32-S3_Display

#include <driver/gpio.h>

#define AUDIO_INPUT_SAMPLE_RATE  24000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000

// Audio I2S (ES8311)
#define AUDIO_I2S_GPIO_MCLK      GPIO_NUM_4
#define AUDIO_I2S_GPIO_BCLK      GPIO_NUM_5
#define AUDIO_I2S_GPIO_DIN       GPIO_NUM_6
#define AUDIO_I2S_GPIO_WS        GPIO_NUM_7
#define AUDIO_I2S_GPIO_DOUT      GPIO_NUM_8
// Speaker amplifier enable: LOW = enabled, HIGH = disabled (handled via pa_inverted in the codec)
#define AUDIO_CODEC_PA_PIN       GPIO_NUM_1

// I2C bus shared by the ES8311 codec and the FT6336G touch controller
#define AUDIO_CODEC_I2C_NUM      I2C_NUM_0
#define AUDIO_CODEC_I2C_SCL_PIN  GPIO_NUM_15
#define AUDIO_CODEC_I2C_SDA_PIN  GPIO_NUM_16
#define AUDIO_CODEC_ES8311_ADDR  ES8311_CODEC_DEFAULT_ADDR

// Touch (FT6336G)
#define TOUCH_I2C_ADDR           0x38
#define TOUCH_RST_PIN            GPIO_NUM_18
#define TOUCH_INT_PIN            GPIO_NUM_17

// Buttons / LED
#define BOOT_BUTTON_GPIO         GPIO_NUM_0
#define BUILTIN_LED_GPIO         GPIO_NUM_42   // single-wire WS2812 RGB LED

// Battery voltage ADC (IO9 = ADC1_CH8)
#define BATTERY_ADC_GPIO         GPIO_NUM_9
#define BATTERY_ADC_CHANNEL      ADC_CHANNEL_8

// Display (ILI9341V, 4-wire SPI)
#define DISPLAY_BACKLIGHT_PIN    GPIO_NUM_45
#define DISPLAY_RST_PIN          GPIO_NUM_NC   // shared with the ESP32-S3 EN/RESET line
#define DISPLAY_SCK_PIN          GPIO_NUM_12
#define DISPLAY_DC_PIN           GPIO_NUM_46
#define DISPLAY_CS_PIN           GPIO_NUM_10
#define DISPLAY_MOSI_PIN         GPIO_NUM_11
#define DISPLAY_MIS0_PIN         GPIO_NUM_13
#define DISPLAY_SPI_SCLK_HZ      (40 * 1000 * 1000)
#define DISPLAY_SPI_MODE         0

#define LCD_SPI_HOST             SPI3_HOST

#define LCD_TYPE_ILI9341_SERIAL
#define DISPLAY_WIDTH            320
#define DISPLAY_HEIGHT           240
#define DISPLAY_MIRROR_X         false
#define DISPLAY_MIRROR_Y         false
#define DISPLAY_SWAP_XY          true
#define DISPLAY_INVERT_COLOR     true
#define DISPLAY_RGB_ORDER        LCD_RGB_ELEMENT_ORDER_BGR
#define DISPLAY_OFFSET_X         0
#define DISPLAY_OFFSET_Y         0
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false

// microSD (SDIO 4-bit) - not used by the stock firmware, reserved for custom features
#define SD_CLK_PIN               GPIO_NUM_38
#define SD_CMD_PIN               GPIO_NUM_40
#define SD_D0_PIN                GPIO_NUM_39
#define SD_D1_PIN                GPIO_NUM_41
#define SD_D2_PIN                GPIO_NUM_48
#define SD_D3_PIN                GPIO_NUM_47

// Expansion header (free GPIOs)
#define EXPAND_IO2               GPIO_NUM_2
#define EXPAND_IO3               GPIO_NUM_3
#define EXPAND_IO14              GPIO_NUM_14
#define EXPAND_IO21              GPIO_NUM_21

#endif  // _BOARD_CONFIG_H_
