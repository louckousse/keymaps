/*
Copyright 2021 @mangoiv

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

#include QMK_KEYBOARD_H
#include "louckousse.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [CMT] = LAYOUT_draculad_pretty_wrapper(
        ______________COLEMAK_DH_MT_L1_____________,             ______________COLEMAK_DH_MT_R1_____________,
        ______________COLEMAK_DH_MT_L2_____________,             ______________COLEMAK_DH_MT_R2_____________,
        ______________COLEMAK_DH_MT_L3_____________,             ______________COLEMAK_DH_MT_R3_____________,
                                            KC_MPLY,             XXXXXXX,
                                MSE_ESC, FUN_ENT, NAV_DEL, SYM_BSP, NUM_SPC, KC_MINS
    ),

    [MSE] = LAYOUT_draculad_pretty_wrapper(
        ________________MOUSE_KEY_L1_______________,             ___________________BLANK___________________,
        ________________MOUSE_KEY_L2_______________,             ___________________MOD_R___________________,
        ________________MOUSE_KEY_L3_______________,             _______, _______, _______, KC_ALGR, _______,
                                            _______,              XXXXXXX,
                                _______, _______, _______, _______, _______, _______
    ),

    [FUNMT] = LAYOUT_draculad_pretty_wrapper(
        __________________FUN_L1___________________,             ___________________BLANK___________________,
        __________________FUN_L2___________________,             ___________________MOD_R___________________,
        __________________FUN_L3___________________,             _______, _______, _______, KC_ALGR, _______,
                                            _______,              XXXXXXX,
                                _______, _______, _______, _______, _______, _______
    ),

    [NAVMT] = LAYOUT_draculad_pretty_wrapper(
        __________________NAV_L1___________________,              ___________________BLANK___________________,
        __________________NAV_L2___________________,              ___________________MOD_R___________________,
        __________________NAV_L3___________________,              _______, _______, KC_OS,   KC_ALGR,  GO_CMK,
                                            _______,              XXXXXXX,
                                XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_SPC,  KC_TAB
    ),

    [SYMMT] = LAYOUT_draculad_pretty_wrapper(
        __________________SYM_L1___________________,              ________________NUMBER_L1__________________,
        __________________SYM_L2___________________,              ________________NUMBER_L2__________________,
        __________________SYM_L3___________________,              ________________NUMBER_L3__________________,
                                            _______,              XXXXXXX,
                                _______, _______, _______, _______, _______, _______
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
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
        if (!clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
