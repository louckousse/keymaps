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
                                 XXXXXXX, XXXXXXX, KC_ESC,  FUN_ENT, NAV_DEL, SYM_BSP, NUM_SPC, KC_TAB,  XXXXXXX, XXXXXXX
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
      XXXXXXX, __________________NAV_L3___________________, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GO_SC2,  GO_GAME, KC_OS,   KC_ALGR, _______, XXXXXXX,
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

    [SC2_B] = LAYOUT(
      KC_TAB,  KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                                        KC_GL,   _______, KC_GG,   _______, _______, _______,
      KC_ESC,  KC_A,   KC_S,     KC_D,    KC_F,    KC_G,                                        _______, _______, _______, _______, _______, _______,
      KC_LSFT, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, KC_TAB,  KC_2,    KC_5,  MO(SC2_L), _______, _______, _______, _______, _______
    ),

    [SC2_L] = LAYOUT(
      _______, KC_GRV,  KC_7,     KC_8,    KC_9,    KC_F1,                                       _______, _______, _______, _______, _______, _______,
      _______, _______, KC_4,     KC_5,    KC_6,    KC_F2,                                       _______, _______, _______, _______, _______, _______,
      _______, KC_LCTL, KC_1,     KC_2,    KC_3,    KC_F3,   _______, _______, _______, _______, _______, _______, _______, _______, GO_BASE, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [GAME_B] = LAYOUT(
      KC_TAB,  _______, KC_Q,    KC_W,    KC_E,    KC_R,                                        _______, _______, _______, _______, _______, _______,
      KC_ESC,  KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                                        _______, _______, _______, _______, _______, _______,
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_C,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, KC_C, LT(GAME_L, KC_ENT), KC_LSFT, KC_SPC,  _______, _______, _______, _______, _______
    ),

    [GAME_L] = LAYOUT(
      KC_N,    KC_F1,   KC_4,     KC_5,    KC_6,    KC_LALT,                                     _______, _______, _______, _______, _______, _______,
      KC_Y,    KC_F2,   KC_1,     KC_2,    KC_3,    KC_J,                                        _______, _______, _______, _______, _______, _______,
      KC_P,    KC_F3,   KC_7,     KC_8,    KC_9,    KC_M,    _______, _______, XXXXXXX, _______, _______, _______, _______, _______, GO_BASE, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};
