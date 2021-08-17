#include QMK_KEYBOARD_H
#include <string.h>
#include <stdio.h>
#include "louckousse.h"
#include "luna.c"
#include "bongocat.c"

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

static void render_default(void) {
    oled_write_P(PSTR("Layout: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case CMT:
            oled_write_P(PSTR("Mod Tap\n"), false);
            break;
        case CMK:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        default:
            oled_write_P(PSTR("That's weird\n"), false);
    }
}

static void render_layer_status(void) {
    oled_write_P(PSTR("Layer:  "), false);
    switch (get_highest_layer(layer_state)) {
        case NAVMT:
            oled_write_P(PSTR("Navigation\n"), false);
#ifdef TRACKBALL_MATRIX_ROW
            trackball_sethsv(11, 176, 150);
#endif
            break;
        case FUNMT:
            oled_write_P(PSTR("Function\n"), false);
#ifdef TRACKBALL_MATRIX_ROW
            trackball_sethsv(128, 255, 128);
#endif
            break;
        case SYMMT:
            oled_write_P(PSTR("Symbol\n"), false);
#ifdef TRACKBALL_MATRIX_ROW
            trackball_sethsv(234, 128, 150);
#endif
            break;
        case NUMMT:
            oled_write_P(PSTR("Number\n"), false);
#ifdef TRACKBALL_MATRIX_ROW
            trackball_sethsv(191, 255, 150);
#endif
            break;
        default:
            oled_write_P(PSTR("Base\n"), false);
#ifdef TRACKBALL_MATRIX_ROW
            trackball_sethsv(235, 200, 100);
#endif
    }
}

void write_int_to_string(char* ref, uint8_t num) {
    // Words per minute is just assumed to remain under a thousand.
    char num_string[4];
    itoa(num, num_string, 10);
    strcat(ref, num_string);
}

void oled_write_with_int(char* str, uint8_t number) {
    write_int_to_string(str, number);
    oled_write(str, false);
}

static void render_os(void) {
    if (user_config.osIsLinux) {
        oled_write_P(PSTR("OS:     Linux-mint\n"), false);
    } else {
        oled_write_P(PSTR("OS:     Windows 10\n"), false);
    }
}

char wpm_str[10];

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_default();
        render_layer_status();
        render_os();
        animate_luna();
    } else {
        animate_bongocat();
        oled_set_cursor(0, 7);
        uint8_t n  = get_current_wpm();
        wpm_str[3] = '\0';
        wpm_str[2] = '0' + n % 10;
        wpm_str[1] = '0' + (n /= 10) % 10;
        wpm_str[0] = '0' + n / 10;
        oled_write_P(PSTR("          "), false);
        oled_write(wpm_str, false);
    }
}
