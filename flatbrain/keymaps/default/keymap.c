#include QMK_KEYBOARD_H

enum layers {
    QWERTY = 0,
    COLEMAK,
    LOWER,
    RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keymap _QWERTY: Base Layer (Default Layer)
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |   Tab  | Q    | W    | E    | R    | T    |                              | Y    | U    | I    | O    | P    | `~     |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |   Esc  | A    | S    | D    | F    | G    |                              | H    | J    | K    | L    | ; :  | ' "    |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * | Shift  | Z    | X    | C    | V    | B    |                              | N    | M    | , <  | . >  | / ?  | CTRL   |
     * `----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
     *          | Super|                    | Alt  | Del  | Back |  | Space| Enter| Alt  |                    | Lead |
     *          `------'                    `------+------+-----'  `-------+------+-----'                     `------'
    */
	[QWERTY] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        SFT_T(KC_CAPS), KC_Z, KC_X, KC_C,   KC_V,    KC_B,                                  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,
                 KC_LGUI,          KC_LALT, LT(RAISE, KC_DEL), LT(LOWER, KC_BSPC), LT(LOWER, KC_SPC), LT(RAISE, KC_ENT), KC_RALT,KC_LEAD
    ),

    /*
     * Keymap _COLEMAK: Base Layer (Default Layer)
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |   Tab  | Q    | W    | F    | P    | B    |                              | J    | L    | U    | Y    | ; :  | `~     |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |   Esc  | A    | R    | S    | T    | G    |                              | M    | N    | E    | I    | O    | ' "    |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * | Shift  | Z    | X    | C    | D    | V    |                              | K    | H    | , <  | . >  | / ?  | CTRL   |
     * `----------------------+------+------+------+------+------.  ,------+------+------+------+------+----------------------'
     *          | Super|                    | Alt  | Del  | Back |  | Space| Enter| Alt  |                    | Super|
     *          `------'                    `------+------+------'  `-------+------+-----'                    `------'
    */
	[COLEMAK] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_GRV,
        KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        SFT_T(KC_CAPS), KC_Z, KC_X, KC_C,   KC_D,    KC_V,                                  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,
                 KC_LGUI,          KC_LALT, LT(RAISE, KC_DEL), LT(LOWER, KC_BSPC), LT(LOWER, KC_SPC), LT(RAISE, KC_ENT), KC_RALT,KC_LGUI
    ),

    /*
     * Keymap LOWER: Number and navigation Layer
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |  = +   | / ?  | 7 &  | 8 *  | 9 (  | - _  |                              |      | Home | Up   | End  | Pg up|        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        | . >  | 4 $  | 5 %  | 6 ^  | +    |                              |      | Left | Down | Right| Pgdwn|        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        | 0 )  | 1 !  | 2 @  | 3 #  | *    |                              | Vol d| Vol u| Play | Mute | PSCR |        |
     * `--------+------+--------------------+------+------+------.   ,-----+------+------+--------------------+------+--------'
     *          | Alt  |                    | Enter|      |      |   |      |      |     |                    | Clmk |
     *          `------'                    `------+------+------'   `------+------+-----'                    `------'
    */

	[LOWER] = LAYOUT(
        KC_EQL,  KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS,                   _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,
        _______, KC_DOT,  KC_4,    KC_5,    KC_6,    KC_PPLS,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
        _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_PAST,                   KC_VOLD, KC_VOLU, KC_MPLY, KC_MUTE, KC_PSCR, _______,
                 KC_LALT,                   KC_ENT,  _______, _______, _______, _______, _______,                   DF(COLEMAK)
	),

	/*
	 * Keympa RAISE : Code Layer
	 *
	 * ,-------------------------------------------.                              ,-------------------------------------------.
	 * | ` ~    | !    | @    | #    | $    | %    |                              | \ |  | &    | *    | SAI  | HUI  | VAI    |
	 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	 * |        |      | [ {  | ] }  | (    | )    |                              | [ {  | ] }  | \ |  | SAD  | HUD  | VAD    |
	 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
	 * |   F1   | F2   | F3   | F4   | F5   | F6   |                              | F7   | F8   | F9   | F10  | F11  | F12    |
	 * `--------+------+--------------------+------+------+------.   ,-----+------+------+--------------------+------+--------'
	 *          | Reset|                    |      |      |      |   |      |      |     |            		 |      |
	 *          `------'                    `------+------+------'   `------+------+-----'                   `------'
	 */
	[RAISE] = LAYOUT(
	      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_BSLS, KC_AMPR, KC_ASTR, RGB_SAI, RGB_HUI, RGB_VAI,
	      _______, _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN,                   KC_LBRC, KC_RBRC, KC_BSLS, RGB_SAD, RGB_HUD, RGB_VAD,
	      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
	               -,                     _______, _______, _______, _______, _______ , _______,                  _______
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

#ifdef OLED_DRIVER_ENABLE
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
        case QWERTY: oled_write_P(PSTR("Qwerty\n"), false); break;
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

#endif
