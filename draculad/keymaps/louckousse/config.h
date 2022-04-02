
#pragma once

#define OLED_DISPLAY_128X64
#define EE_HANDS

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT  // looks like it takes too much size

// mod tap
#define IGNORE_MOD_TAP_INTERRUPT  // Prevent normal rollover on alphas from accidentally triggering mods
#define TAPPING_FORCE_HOLD        // Enable rapid switch from tap to hold, disables double tap hold auto-repeat
#define PERMISSIVE_HOLD           // Apply the modifier on keys that are tapped during a short hold of a modtap
#define TAPPING_TERM 200

// TrackBall
#define POINTING_DEVICE_ROTATION_90
#define TRACKBALL_MATRIX_ROW 6
#define TRACKBALL_MATRIX_COL 1
#define TRACKBALL_ORIENTATION 2

#define RGBLIGHT_HUE_STEP 5
#define RGBLIGHT_SAT_STEP 5
#define RGBLIGHT_VAL_STEP 5
#define RGBLIGHT_SLEEP

#define RGBLIGHT_DISABLE_KEYCODES

#define ENCODER_RESOLUTION 2
