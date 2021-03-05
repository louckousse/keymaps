/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

enum custom { KC_OSS };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [CMT] = LAYOUT_tbk_wrapper(
      XXXXXXX, ______________COLEMAK_DH_MT_L1_____________,  ______________COLEMAK_DH_MT_R1_____________, XXXXXXX,
      XXXXXXX, ______________COLEMAK_DH_MT_L2_____________,  ______________COLEMAK_DH_MT_R2_____________, XXXXXXX,
      XXXXXXX, ______________COLEMAK_DH_MT_L3_____________,  ______________COLEMAK_DH_MT_R3_____________, XXXXXXX,
                                 KC_ESC,  FUN_ENT, NAV_DEL,  SYM_BSP, NUM_SPC, KC_TAB
  ),

  [FUNMT] = LAYOUT_tbk_wrapper(
      RESET,   __________________FUN_L1___________________,  ___________________BLANK___________________, XXXXXXX,
      XXXXXXX, __________________FUN_L2___________________,  ___________________MOD_R___________________, XXXXXXX,
      XXXXXXX, __________________FUN_L3___________________,  _______, _______, _______, KC_ALGR, _______, XXXXXXX,
                                 _______, _______, _______,  _______, _______, _______
  ),

  [NAVMT] = LAYOUT_tbk_wrapper(
      XXXXXXX, __________________NAV_L1___________________,  ___________________BLANK___________________, XXXXXXX,
      XXXXXXX, __________________NAV_L2___________________,  ___________________MOD_R___________________, XXXXXXX,
      XXXXXXX, __________________NAV_L3___________________,  _______, _______, KC_OS,   KC_ALGR, _______, XXXXXXX,
                                 _______, _______, _______,  _______, _______, _______
  ),

  [SYMMT] = LAYOUT_tbk_wrapper(
      XXXXXXX, __________________SYM_L1___________________,  ________________NUMBER_L1__________________, XXXXXXX,
      XXXXXXX, __________________SYM_L2___________________,  ________________NUMBER_L2__________________, XXXXXXX,
      XXXXXXX, __________________SYM_L3___________________,  ________________NUMBER_L3__________________, XXXXXXX,
                                 _______, _______, _______,  _______, _______, _______
  ),

  [NUMMT] = LAYOUT_tbk_wrapper(
      XXXXXXX, ___________________BLANK___________________,  ________________NUMBER_L1__________________, XXXXXXX,
      XXXXXXX, ___________________MOD_L___________________,  ________________NUMBER_L2__________________, XXXXXXX,
      XXXXXXX, _______, KC_ALGR, _______, _______, _______,  ________________NUMBER_L3__________________, XXXXXXX,
                                 _______, _______, _______,  _______, _______, _______
  )
};
