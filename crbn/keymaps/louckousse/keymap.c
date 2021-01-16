/* Copyright 2020 louckousse
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

#include QMK_KEYBOARD_H
#include "louckousse.h"


#define NAV_ENT LT(NAVMT, KC_ENT)
#define FUN_DEL LT(FUNMT,KC_DEL)
#define NUM_BSP LT(NUMMT,KC_BSPC)
#define SYM_SPC LT(SYMMT,KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

        [CMT] = LAYOUT_crbn_pretty_wrapper(
                KC_TAB,  ______________COLEMAK_DH_MT_L1_____________, ______________COLEMAK_DH_MT_R1_____________, KC_CIRC,
                KC_ESC,  ______________COLEMAK_DH_MT_L2_____________, ______________COLEMAK_DH_MT_R2_____________, KC_QUOT,
                KC_LSFT, ______________COLEMAK_DH_MT_L3_____________, ______________COLEMAK_DH_MT_R3_____________, KC_ENT,
                KC_LCTL, KC_LALT, KC_LGUI, KC_ESC,  FUN_DEL, NAV_ENT, SYM_SPC, NUM_BSP, KC_TAB, KC_UP,   KC_RGHT, KC_5
            ),

        [FUNMT] = LAYOUT_crbn_pretty_wrapper(
                RESET,   __________________FUN_L1___________________, ___________________BLANK___________________, _______,
                _______, __________________FUN_L2___________________, ___________________MOD_R___________________, _______,
                _______, __________________FUN_L3___________________, _______, _______, _______, KC_ALGR, _______, _______,
                _______, ___________________BLANK___________________, ___________________BLANK___________________, _______
            ),

        [NAVMT] = LAYOUT_crbn_pretty_wrapper(
                _______, __________________NAV_L1___________________, ___________________BLANK___________________, _______,
                _______, __________________NAV_L2___________________, ___________________MOD_R___________________, _______,
                _______, __________________NAV_L3___________________, _______, _______, KC_OS,   KC_ALGR, _______, _______,
                _______, ___________________BLANK___________________, ___________________BLANK___________________, _______
            ),

        [SYMMT] = LAYOUT_crbn_pretty_wrapper(
                _______, __________________SYM_L1___________________, ________________NUMBER_L1__________________, _______,
                _______, __________________SYM_L2___________________, ________________NUMBER_L2__________________, _______,
                _______, __________________SYM_L3___________________, ________________NUMBER_L3__________________, _______,
                _______, ___________________BLANK___________________, ___________________BLANK___________________, _______
            ),

        [NUMMT] = LAYOUT_crbn_pretty_wrapper(
                _______, ___________________BLANK___________________, ________________NUMBER_L1__________________, _______,
                _______, ___________________MOD_L___________________, ________________NUMBER_L2__________________, _______,
                _______, _______, KC_ALGR, _______, _______, _______, ________________NUMBER_L3__________________, _______,
                _______, ___________________BLANK___________________, ___________________BLANK___________________, _______
            ),
};
