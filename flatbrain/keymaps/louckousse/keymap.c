#include QMK_KEYBOARD_H

enum layers {
    COLEMAK = 0,
    LOWER,
    RAISE,
    SC2_B,
    SC2_L,
    GAME_B,
    GAME_L,
};

typedef union {
    uint32_t raw;
    struct {
        bool osIsLinux;
    };
} user_config_t;

user_config_t user_config;

enum custom_keycodes {
    KC_GG = SAFE_RANGE,
    KC_GL,
    DSK_NXT,
    DSK_PRV,
    PRINT,
    LOCK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap _COLEMAK: Base Layer (Default Layer)
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |   Tab  | Q    | W    | F    | P    | B    |                              | J    | L    | U    | Y    | Esc  |  ^     |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |   - _  | A    | R    | S    | T    | G    |                              | M    | N    | E    | I    | O    | ' "    |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |  ; :   | Z    | X    | C    | D    | V    |                              | K    | H    | , <  | . >  | / ?  | ` ~    |
     * `----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
     *          | Play |                    | Ctrl | Del  | Enter|  | Bspce| Space| Alt  |                    | Super|
     *          `------'                    `------+------+------'  `-------+------+-----'                    `------'
    */
	[COLEMAK] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                  KC_J,    KC_L,    KC_U,    KC_Y,    KC_ESC,  KC_CIRC,
        KC_MINS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_SCLN, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,
                 KC_MPLY, KC_LCTL, MT(MOD_LSFT, KC_DEL), LT(RAISE, KC_ENT),   LT(LOWER, KC_BSPC), MT(MOD_LSFT, KC_SPC), KC_LALT, KC_LGUI
    ),

    /*
     * Keymap LOWER: Number and navigation Layer
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |      | Home | Up   | End  | Pgup |                              | / ?  | 7 &  | 8 *  | 9 (  | - _  |  SC2   |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |  Sleep |  Tab | Left | Down | Right| Pgdn |                              | = +  | 4 $  | 5 %  | 6 ^  |  +   |  Game  |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |       |      |   <M  |  M>  | <D   | D>   |                              | 0 )  | 1 !  | 2 @  | 3 #  |  *  | Colemak|
     * `--------+------+--------------------+------+------+------.   ,-----+------+------+--------------------+------+--------'
     *          |      |                    |      |      |      |   |      |      |     |                    |      |
     *          `------'                    `------+------+------'   `------+------+-----'                    `------'
    */

	[LOWER] = LAYOUT(
        _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                    KC_SLSH, KC_7,    KC_8,    KC_9, KC_MINS, DF(SC2_B),
        KC_SLEP, KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                    KC_EQL,  KC_4,    KC_5,    KC_6, KC_PLUS, DF(GAME_B),
        _______, _______, KC_MPRV, KC_MNXT, DSK_PRV, DSK_NXT,                    KC_0,    KC_1,    KC_2,    KC_3, KC_ASTR, DF(COLEMAK),
                 _______,                   _______,  _______, _______, _______, _______, _______,                _______
	),

	/*
	 * Keympa RAISE : Code Layer
	 *
	 * ,-------------------------------------------.                              ,-------------------------------------------.
	 * |  Prns  |  $   |  @   |  [ { |  ] } |  \   |                              |  €   |  |   |  _   |  %   |  HUI |  VAI   |
	 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	 * |  Lock  |  #   |  !   |  (   |  )   |  /   |                              |  *  |  &   |   +   |  *   | F11  |  F12   |
	 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	 * |   F1   | F2   | F3   |  {   |  }   | F4   |                              | F5   | F8   | F7   | F8   | F9   | F10    |
	 * `--------+------+--------------------+------+------+------.   ,-----+------+------+--------------------+------+--------'
	 *          | Reset|                    |      |      |      |   |      |      |     |            		 | Lock |
	 *          `------'                    `------+------+------'   `------+------+-----'                   `------'
	 */
	[RAISE] = LAYOUT(
	      PRINT,   KC_DLR,  KC_AT,   KC_LBRC, KC_RBRC, KC_BSLS,                ALGR(KC_5), KC_PIPE, KC_UNDS, KC_PERC, RGB_HUI, RGB_VAI,
	      _______, KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_SLSH,                   KC_ASTR, KC_AMPR, KC_PLUS, KC_ASTR, KC_F11,  KC_F12,
	      KC_F1,   KC_F2,   KC_F3,   KC_LCBR, KC_RCBR, KC_F4,                     KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
	               RESET,                     _______, _______, _______, _______, _______, _______,                   LOCK
	    ),

    [SC2_B] = LAYOUT(
      KC_TAB,  KC_Q,   KC_W,     KC_E,    KC_R,    KC_T,                          KC_GL,   _______, KC_GG,   _______, _______, _______,
      KC_ESC,  KC_A,   KC_S,     KC_D,    KC_F,    KC_G,                          _______, _______, _______, _______, _______, _______,
      KC_LSFT, KC_Z,   KC_X,     KC_C,    KC_V,    KC_B,                          _______, _______, _______, _______, _______, _______,
               _______,             _______, _______, LT(SC2_L, KC_SPC), _______, _______, _______,                   _______
    ),

    [SC2_L] = LAYOUT(
      _______, KC_GRV,  KC_7,     KC_8,    KC_9,    KC_F1,                     _______, _______, _______, _______, _______, _______,
      _______, _______, KC_4,     KC_5,    KC_6,    KC_F2,                     _______, _______, _______, _______, _______, _______,
      _______, KC_LCTL, KC_1,     KC_2,    KC_3,    KC_F3,                     _______, _______, _______, _______, _______, DF(COLEMAK),
               _______,                    _______, _______, _______, _______, _______, _______,                   _______
    ),

    [GAME_B] = LAYOUT(
      KC_TAB,  _______, KC_Q,    KC_W,    KC_E,    KC_R,                        _______, _______, _______, _______, _______, _______,
      KC_ESC,  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,                        _______, _______, _______, _______, _______, _______,
      KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        _______, _______, _______, _______, _______, _______,
               _______,          LT(GAME_L, KC_ENT), KC_LSFT, KC_SPC,  _______, _______, _______,                   _______
    ),

    [GAME_L] = LAYOUT(
      KC_N,    KC_F1,   KC_4,     KC_5,    KC_6,    KC_LALT,                   _______, _______, _______, _______, _______, _______,
      KC_Y,    KC_F2,   KC_1,     KC_2,    KC_3,    KC_J,                      _______, _______, _______, _______, _______, _______,
      KC_P,    KC_F3,   KC_7,     KC_8,    KC_9,    KC_M,                      _______, _______, _______, _______, _______, DF(COLEMAK),
               _______,                    _______, _______, _______, _______, _______, _______,                   _______
    ),

	// /*
	//  * Layer template
	//  *
	//  * ,-------------------------------------------.                              ,-------------------------------------------.
	//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
	//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
	//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
	//  * `--------+------+--------------------+------+------+------.  ,------+------+------+--------------------+------+--------'
	//  *          |      |                    |      |      |      |  |      |      |      |                    |      |
	//  *          `------'                    `------+------+------'  `------+------+------'                    `------'
	//  */
	//     [_LAYERINDEX] = LAYOUT(
	//       _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
	//       _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
	//       _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
	//                _______,                   _______, _______, _______, _______, _______, _______,                   _______
	//     ),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

         // Set current OS indicator to Windows
        SEQ_ONE_KEY(KC_W) {
            user_config.osIsLinux = !user_config.osIsLinux;
            eeconfig_update_user(user_config.raw);
        }

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
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_GG:  // One key copy/paste
            if (record->event.pressed) {
                SEND_STRING("\nGG\n");
            } else {
                tap_code16(KC_F10);
                tap_code16(KC_W);
            }
            break;
        case KC_GL:
            if (record->event.pressed) {
                SEND_STRING("\nGL HF\n");
            }
            break;
        case DSK_PRV:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(C(A(KC_LEFT)));
                } else {
                    tap_code16(C(G(KC_LEFT)));
                }
            }
            break;
        case DSK_NXT:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(C(A(KC_RIGHT)));
                } else {
                    tap_code16(C(G(KC_RIGHT)));
                }
            }
            break;
        case PRINT:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(C(S(KC_PSCR)));
                } else {
                    tap_code16(S(G(KC_S)));
                }
            }
            break;
        case LOCK:
            if (record->event.pressed) {
                if (user_config.osIsLinux) {
                    tap_code16(LCA(KC_L));
                } else {
                    tap_code16(G(KC_L));
                }
            }
            break;
    }
    return true;
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

void render_default(void) {
    oled_write_P(PSTR("Layout: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case COLEMAK: oled_write_P(PSTR("Colemak-DHM\n"), false); break;
        default: oled_write_P(PSTR("That's weird\n"), false);
    }
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("     Flatbrain rev0.0\n\n"), false);
    render_default();
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case LOWER: oled_write_P(PSTR("Lower\n"), false); break;
        case RAISE: oled_write_P(PSTR("Raise\n"), false); break;
        default: oled_write_P(PSTR("Base\n"), false);
    }
}

void oled_task_user(void) {
    render_status();
}
