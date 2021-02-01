#include QMK_KEYBOARD_H
#include <stdio.h>
// extern haptic_config_t haptic_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_MUTE, TG(1),   TG(2),
        KC_7,   KC_8,   KC_9,
        KC_4,   KC_5,   KC_6,
        KC_1,   KC_2,   KC_3
    ),
    [1] = LAYOUT( /* Layer 1 */
        RESET,   _______, XXXXXXX,
        AU_ON,   AU_OFF,  XXXXXXX,
        CK_TOGG, XXXXXXX, CK_UP,
        CK_RST,  XXXXXXX, CK_DOWN
    ),
    [2] = LAYOUT( /* Layer 2*/
        RGB_TOG, RGB_MOD, _______,
        RGB_HUI, RGB_SAI, RGB_VAI,
        RGB_HUD, RGB_SAD, RGB_VAD,
        HPT_TOG, HPT_FBK, HPT_CONT
    )
};


void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code16(KC_VOLU);
    } else {
        tap_code16(KC_VOLD);
    }
    if (is_audio_on() && is_clicky_on()) clicky_play();
}
