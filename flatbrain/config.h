#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    louckousse
#define PRODUCT         flatbrain
#define DESCRIPTION     Unsplitted 40 percent column staggered keyboard

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/* key matrix pins */
#define MATRIX_ROW_PINS { F5, F4, B4, B5, D4, C6, D7, E6 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
#define RGBLED_NUM 10
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LAYERS
#endif

#endif

#define LEADER_TIMEOUT 300
