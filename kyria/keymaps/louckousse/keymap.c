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
#include QMK_KEYBOARD_H
#include "louckousse.h"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [CMT] = LAYOUT_kyria_pretty_wrapper(
      XXXXXXX, ______________COLEMAK_DH_MT_L1_____________,                                     ______________COLEMAK_DH_MT_R1_____________,  KC_CIRC,
      XXXXXXX, ______________COLEMAK_DH_MT_L2_____________,                                     ______________COLEMAK_DH_MT_R2_____________,  KC_QUOT,
      XXXXXXX, ______________COLEMAK_DH_MT_L3_____________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ______________COLEMAK_DH_MT_R3_____________,  KC_GRV,
                                 XXXXXXX, XXXXXXX, MSE_ESC, FUN_ENT, NAV_DEL, SYM_BSP, NUM_SPC, KC_MINS, XXXXXXX, XXXXXXX
    ),

    [MSE] = LAYOUT_kyria_pretty_wrapper(
      XXXXXXX, ________________MOUSE_KEY_L1_______________,                                     ___________________BLANK___________________, XXXXXXX,
      XXXXXXX, ________________MOUSE_KEY_L2_______________,                                     ___________________MOD_R___________________, XXXXXXX,
      XXXXXXX, ________________MOUSE_KEY_L3_______________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, KC_ALGR, _______, XXXXXXX,
                                 XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
    ),

    [FUNMT] = LAYOUT_kyria_pretty_wrapper(
      XXXXXXX, __________________FUN_L1___________________,                                     ___________________BLANK___________________, XXXXXXX,
      XXXXXXX, __________________FUN_L2___________________,                                     ___________________MOD_R___________________, XXXXXXX,
      XXXXXXX, __________________FUN_L3___________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, KC_ALGR, _______, XXXXXXX,
                                 XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
    ),

    [NAVMT] = LAYOUT_kyria_pretty_wrapper(
      XXXXXXX, __________________NAV_L1___________________,                                     ___________________BLANK___________________, XXXXXXX,
      XXXXXXX, __________________NAV_L2___________________,                                     ___________________MOD_R___________________, XXXXXXX,
      XXXXXXX, __________________NAV_L3___________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_OS,   KC_ALGR, GO_CMK,  XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_SPC,  KC_TAB,  XXXXXXX, XXXXXXX
    ),

    [SYMMT] = LAYOUT_kyria_pretty_wrapper(
      XXXXXXX, __________________SYM_L1___________________,                                     ________________NUMBER_L1__________________, XXXXXXX,
      XXXXXXX, __________________SYM_L2___________________,                                     ________________NUMBER_L2__________________, XXXXXXX,
      XXXXXXX, __________________SYM_L3___________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ________________NUMBER_L3__________________, XXXXXXX,
                                 XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
    ),

    [NUMMT] = LAYOUT_kyria_pretty_wrapper(
      XXXXXXX, ___________________BLANK___________________,                                     ________________NUMBER_L1__________________, XXXXXXX,
      XXXXXXX, ___________________MOD_L___________________,                                     ________________NUMBER_L2__________________, XXXXXXX,
      XXXXXXX, _______, KC_ALGR, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ________________NUMBER_L3__________________,  XXXXXXX,
                                 XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
    ),

    [CMK] = LAYOUT_kyria_pretty_wrapper(
      KC_TAB,  ______________COLEMAK_DH_L1________________,                                     ______________COLEMAK_DH_R1________________, KC_CIRC,
      KC_ESC,  ______________COLEMAK_DH_L2________________,                                     ______________COLEMAK_DH_R2________________, KC_QUOT,
      KC_CAPS, ______________COLEMAK_DH_L3________________, KC_RALT, GO_BASE, PRINT,   KC_OS,   ______________COLEMAK_DH_R3________________, KC_GRV,
                                 KC_MPLY, ALT_BO,  CTRL_MN, ST_ENT,  RSE_DEL, LWR_BSP, ST_SPC,  KC_RCTL, ALT_BE,  KC_LGUI
    ),
};
