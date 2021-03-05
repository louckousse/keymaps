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

#define PKRGB
#define RGBLIGHT_LAYERS
