#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    louckousse
#define PRODUCT         cod67
#define DESCRIPTION     cod67 rework to fit standard 60% layout

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS { D5, D1, D0, B7, D3}
#define MATRIX_COL_PINS { F7, F6, F5, F4, F1, F0, D2, D4, D6, D7, B4, B5, B6, C6, C7 }
#define UNUSED_PINS {E6}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define RGB_DI_PIN B0
#ifdef RGB_DI_PIN
#define RGBLED_NUM 20
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LAYERS
#endif

#endif

#define LEADER_TIMEOUT 300
