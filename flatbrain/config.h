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
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { B0, D2, F4, F5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6, B5, B4, E6, D7, C6, D4 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { F1, B7 }
#define ENCODERS_PAD_B { F0, D5 }

/* number of backlight levels */

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
    #define RGBLED_NUM 10
    #define RGBLIGHT_HUE_STEP 5
    #define RGBLIGHT_SAT_STEP 5
    #define RGBLIGHT_VAL_STEP 5
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_LIMIT_VAL 150
#endif

#endif

#define LEADER_TIMEOUT 300
