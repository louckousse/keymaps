#include QMK_KEYBOARD_H

#define _BL 0
#define _FL 1
#define _GL 2

//Tap dance enums
enum {
  X_SFT = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _BL: (Base Layer) Default Layer
     * ,----------------------------------------------------------------.
     * |~ `| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp  |DEL |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |psrn|
     * |----------------------------------------------------------------|
     * |ESC    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |home|
     * |----------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
     * |----------------------------------------------------------------|
     * |Ctrl|Fn  |Alt |         Space         |Alt|Ctrl|LDR| <-|Dow|->  |
     * `----------------------------------------------------------------'
     */
    [_BL] = LAYOUT_65_ansi(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, C(S(KC_PSCR)),
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_HOME,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(X_SFT), KC_UP, KC_END,
        KC_LCTL, KC_LGUI, KC_LALT, LT(_FL, KC_SPC), KC_RALT, KC_RCTL, KC_LEAD, KC_LEFT, KC_DOWN, KC_RGHT
        ),

    /* Keymap _FL: Function Layer
     * ,----------------------------------------------------------------.
     * |ESC| F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
     * |----------------------------------------------------------------|
     * |     |Ply|V+ |Mut|   |   |   |   |INS|   |PRN|   |   |     | RST|
     * |----------------------------------------------------------------|
     * |      | <M|V- |M> |   | GL|   |   |   |lck|   |   |        |DBUG|
     * |----------------------------------------------------------------|
     * |        |   |   |   |    |   |   |Mnu|   |   |   |     |PGU|    |
     * |----------------------------------------------------------------|
     * |    |    |    |                       |   |   |    |HME|PGD|END |
     * `----------------------------------------------------------------'
     */
    [_FL] = LAYOUT_65_ansi(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS,
        _______, KC_MPLY, KC_VOLU, KC_MUTE, _______, _______, _______, _______, KC_INS, _______, KC_PSCR, _______, _______, _______, RESET,
        _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, TO(_GL), _______, _______, KC_SYSTEM_SLEEP, LCA(KC_L), _______, _______, _______, DEBUG,
        _______, _______, _______, _______, _______, _______, _______, KC_PAUS, _______, _______, _______, _______, KC_PGUP, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END),

    /* Keymap _GL: (Game Layer) Default Layer
     * ,----------------------------------------------------------------.
     * |~ `| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp  |DEL |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |psrn|
     * |----------------------------------------------------------------|
     * |ESC    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |home|
     * |----------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
     * |----------------------------------------------------------------|
     * |Ctrl|Win |Alt |        Space          |Alt|Ctrl|LDR| <-|Dow|->  |
     * `----------------------------------------------------------------'
     */
    [_GL] = LAYOUT_65_ansi(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, C(S(KC_PSCR)),
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_HOME,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_END,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RCTL, TO(_BL), KC_LEFT, KC_DOWN, KC_RGHT
        ),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_T) { SEND_STRING(SS_LCTRL(SS_LSFT("t"))); }

        SEQ_TWO_KEYS(KC_E, KC_S) { SEND_STRING(":sunglasses:"); }

        SEQ_TWO_KEYS(KC_E, KC_O) { SEND_STRING(":okay_hand:"); }

        SEQ_TWO_KEYS(KC_G, KC_A) { SEND_STRING("git add ."SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_D) { SEND_STRING("git diff"SS_TAP(X_ENT)); }

        SEQ_THREE_KEYS(KC_G, KC_D, KC_S) { SEND_STRING("git diff --staged"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_L) { SEND_STRING("git l"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_F) { SEND_STRING("git fp"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_O) { SEND_STRING("git checkout"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_P) { SEND_STRING("git pull"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_S) { SEND_STRING("git status"SS_TAP(X_ENT)); }

        SEQ_TWO_KEYS(KC_G, KC_C) {
            SEND_STRING("git commit -m "SS_DOWN(X_RALT)"''"SS_UP(X_RALT)SS_TAP(X_LEFT));
        }

        SEQ_THREE_KEYS(KC_G, KC_C, KC_A) { SEND_STRING("git amend"SS_TAP(X_ENT)); }

        SEQ_ONE_KEY(KC_1) {
            // ¯\_(ツ)_/¯
            send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
        }

        SEQ_ONE_KEY(KC_2) {
            // ಠ_ಠ
            send_unicode_string("ಠ_ಠ");
        }

        SEQ_TWO_KEYS(KC_P, KC_O) {
            SEND_STRING(SS_LCTRL(SS_LALT("t"))"po"SS_TAP(X_ENT));
        }
    }
}

void tap_key(uint16_t keycode)
{
  register_code  (keycode);
  unregister_code(keycode);
}

void caps(qk_tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1) {
    tap_key(KC_CAPS);
  }
  else {
    set_oneshot_mods(MOD_LSFT);
    register_code   (KC_LSFT);              // on hold down
  }
}

void caps_reset(qk_tap_dance_state_t *state, void *user_data)
{
  unregister_code(KC_LSFT);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [X_SFT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,caps, caps_reset)
};
