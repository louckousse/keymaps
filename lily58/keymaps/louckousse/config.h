/*
This is the c configuration file for the keymap

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define EE_HANDS

#define USE_SERIAL_PD2

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_HUE_STEP 5
#define RGBLIGHT_SAT_STEP 5
#define RGBLIGHT_VAL_STEP 5

#undef RGB_DI_PIN
#define RGB_DI_PIN D4
#define RGBLED_SPLIT { 10, 10 }
#define RGBLED_NUM 20

#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODERS_PAD_A_RIGHT { F5 }
#define ENCODERS_PAD_B_RIGHT { F4 }

#define ENCODER_RESOLUTION 2
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT  // looks like it takes too much size

// mod tap
#define IGNORE_MOD_TAP_INTERRUPT  // Prevent normal rollover on alphas from accidentally triggering mods
#define TAPPING_FORCE_HOLD        // Enable rapid switch from tap to hold, disables double tap hold auto-repeat
#define PERMISSIVE_HOLD           // Apply the modifier on keys that are tapped during a short hold of a modtap
#define TAPPING_TERM 200
