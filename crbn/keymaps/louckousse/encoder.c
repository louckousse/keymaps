#include "louckousse.h"

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
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
    if (index == 1) tap_code(KC_0);
    if (index == 2) tap_code(KC_1);
    if (index == 3) tap_code(KC_2);
    else tap_code(KC_3);
}
