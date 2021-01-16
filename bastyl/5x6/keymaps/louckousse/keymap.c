/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "louckousse.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [CMT] = LAYOUT_bastyl_pretty_wrapper(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  ______________COLEMAK_DH_MT_L1_____________,                    ______________COLEMAK_DH_MT_R1_____________,  KC_CIRC,
        KC_ESC,  ______________COLEMAK_DH_MT_L2_____________,                    ______________COLEMAK_DH_MT_R2_____________,  KC_QUOT,
        KC_CAPS, ______________COLEMAK_DH_MT_L3_____________,                    ______________COLEMAK_DH_MT_R3_____________,  KC_GRV,
                                   KC_ESC,  GO_GAME,  GO_SC2,                    PRINT,   KC_OS, KC_TAB,
                                            FUN_ENT, NAV_DEL,                    SYM_BSP, NUM_SPC
    ),

    [FUNMT] = LAYOUT_bastyl_pretty_wrapper(
        RESET,   ___________________BLANK___________________,                    ___________________BLANK___________________, RESET,
        XXXXXXX, __________________FUN_L1___________________,                    ___________________BLANK___________________, XXXXXXX,
        XXXXXXX, __________________FUN_L2___________________,                    ___________________MOD_R___________________, XXXXXXX,
        XXXXXXX, __________________FUN_L3___________________,                    _______, _______, _______, KC_ALGR, _______, XXXXXXX,
                                   _______, _______, _______,                    _______, _______, _______,
                                            _______, _______,                    _______, _______
    ),

    [NAVMT] = LAYOUT_bastyl_pretty_wrapper(
        RESET,   ___________________BLANK___________________,                    ___________________BLANK___________________, RESET,
        XXXXXXX, __________________NAV_L1___________________,                    KC_CIRC, GO_GAME, KC_OS,   GO_SC2,  _______, XXXXXXX,
        XXXXXXX, __________________NAV_L2___________________,                    KC_QUOT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
        XXXXXXX, __________________NAV_L3___________________,                    KC_GRV,  _______, _______, KC_ALGR, _______, XXXXXXX,
                                   _______, _______, _______,                    _______, _______, KC_ENT,
                                            _______, _______,                    KC_BSPC, KC_SPC
    ),

    [SYMMT] = LAYOUT_bastyl_pretty_wrapper(
        RESET,   ___________________BLANK___________________,                    ___________________BLANK___________________, RESET,
        XXXXXXX, __________________SYM_L1___________________,                    ________________NUMBER_L1__________________, XXXXXXX,
        XXXXXXX, __________________SYM_L2___________________,                    ________________NUMBER_L2__________________, XXXXXXX,
        XXXXXXX, __________________SYM_L3___________________,                    ________________NUMBER_L3__________________, XXXXXXX,
                                   _______, _______, _______,                    _______, _______, _______,
                                            _______, _______,                    _______, _______
    ),

    [NUMMT] = LAYOUT_bastyl_pretty_wrapper(
        RESET,   ___________________BLANK___________________,                    ___________________BLANK___________________, RESET,
        XXXXXXX, ___________________BLANK___________________,                    ________________NUMBER_L1__________________, XXXXXXX,
        XXXXXXX, ___________________MOD_L___________________,                    ________________NUMBER_L2__________________, XXXXXXX,
        XXXXXXX, _______, KC_ALGR, _______, _______, _______,                    ________________NUMBER_L3__________________, XXXXXXX,
                                   _______, _______, _______,                    _______, _______, _______,
                                            _______, _______,                    _______, _______
    ),
};
