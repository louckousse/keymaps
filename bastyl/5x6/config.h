/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#define PRODUCT_ID      0x3536
#define DEVICE_VER      0x0001
#define PRODUCT         Bastyl

#define CATERINA_BOOTLOADER

#define MATRIX_ROWS 10
#define MATRIX_COLS 6

#define DIODE_DIRECTION ROW2COL

#define MATRIX_ROW_PINS { D7, B5, F7, F6, B6 }
#define MATRIX_COL_PINS { B4, E6, C6, B1, B3, B2  }


// WS2812 RGB LED strip input and number of LEDs
#define RGB_DI_PIN D2
#define RGBLED_NUM 38
//#define RGBLED_SPLIT {19, 19}
#define RGBLIGHT_SPLIT

#define RGBLIGHT_ANIMATIONS

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3
