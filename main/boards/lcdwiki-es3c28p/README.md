# LCDWiki 2.8inch ESP32-S3 Display (ES3C28P / ES3N28P)

Product page and pin map: <https://www.lcdwiki.com/2.8inch_ESP32-S3_Display>

| Item | Value |
|------|-------|
| MCU | ESP32-S3 N16R8 (16 MB flash, 8 MB OPI PSRAM) |
| Display | 2.8" IPS, 240x320, ILI9341V, 4-wire SPI |
| Touch | FT6336G, I2C (shares the bus with ES8311) |
| Audio | ES8311 codec + FM8002E amplifier, 1 MEMS microphone |
| LED | 1x WS2812 on IO42 |
| Storage | microSD (SDIO), pins listed in `config.h`, unused by the stock firmware |

## Build

```
idf.py set-target esp32s3
idf.py menuconfig      # Xiaozhi Assistant -> Board Type -> LCDWiki ES3C28P 2.8-inch ESP32-S3
idf.py build flash monitor
```

or `python scripts/release.py lcdwiki-es3c28p`.

## Things to check on first boot

- Wrong colors: toggle `DISPLAY_INVERT_COLOR` or switch `DISPLAY_RGB_ORDER` between BGR and RGB.
- Image mirrored or rotated: adjust `DISPLAY_SWAP_XY`, `DISPLAY_MIRROR_X`, `DISPLAY_MIRROR_Y`.
- Tearing or noise: lower `DISPLAY_SPI_SCLK_HZ` from 40 MHz to 20 MHz.
- No sound: the amplifier enable (IO1) is active low, the codec is created with `pa_inverted = true`.
- Battery percentage is wrong: the ADC divider values in the board file are inherited from the Freenove 2.8" board and have not been checked against the ES3C28P schematic.

## Touch

The stock firmware only maps taps: single tap toggles chat, double tap starts listening, a 3 s hold opens Wi-Fi setup.
Swipe gestures need an LVGL input device registered on the FT6336G.
