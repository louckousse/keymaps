/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define OLED_DISPLAY_128X64

#define RGBLIGHT_HUE_STEP 5
#define RGBLIGHT_SAT_STEP 5
#define RGBLIGHT_VAL_STEP 5
#define RGBLIGHT_SLEEP
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD

#define RGBLIGHT_DISABLE_KEYCODES

// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION 2


// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT  // looks like it takes too much size

// mod tap
#define IGNORE_MOD_TAP_INTERRUPT  // Prevent normal rollover on alphas from accidentally triggering mods
#define TAPPING_FORCE_HOLD        // Enable rapid switch from tap to hold, disables double tap hold auto-repeat
#define PERMISSIVE_HOLD           // Apply the modifier on keys that are tapped during a short hold of a modtap
#define TAPPING_TERM 200
