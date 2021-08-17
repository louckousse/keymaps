#include "louckousse.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
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
        switch (get_highest_layer(layer_state)) {
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
    return true;
}
