#include "louckousse.h"

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case NAVMT:
            case FUNMT:
            case NUMMT:
            case SYMMT:
                if (clockwise) {
                    tap_code16(C(KC_LEFT));
                } else {
                    tap_code16(C(KC_RGHT));
                }
                break;
            default:
                if (clockwise) {
                    tap_code16(C(KC_Z));
                } else {
                    tap_code16(C(S(KC_Z)));
                }
                break;
        }
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case NAVMT:
            case FUNMT:
            case NUMMT:
            case SYMMT:
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
                break;
            default:
                if (((keyboard_report->mods & MOD_BIT(KC_LSFT)))) {
                    if (!clockwise) {
                        rgblight_increase_hue();
                    } else {
                        rgblight_decrease_hue();
                    }
                } else if ((keyboard_report->mods & MOD_BIT(KC_LCTL))) {
                    if (!clockwise) {
                        rgblight_increase_sat();
                    } else {
                        rgblight_decrease_sat();
                    }
                } else if ((keyboard_report->mods & MOD_BIT(KC_LALT))) {
                    if (!clockwise) {
                        rgblight_increase_val();
                    } else {
                        rgblight_decrease_val();
                    }
                } else {
                    if (clockwise) {
                        if (user_config.osIsLinux) {
                            tap_code16(C(A(KC_LEFT)));
                        } else {
                            tap_code16(C(G(KC_LEFT)));
                        }
                    } else {
                        if (user_config.osIsLinux) {
                            tap_code16(C(A(KC_RIGHT)));
                        } else {
                            tap_code16(C(G(KC_RIGHT)));
                        }
                    }
                }
        }
    }
}
