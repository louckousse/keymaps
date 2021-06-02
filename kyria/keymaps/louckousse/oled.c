#include QMK_KEYBOARD_H
#include <string.h>
#include <stdio.h>
#include "louckousse.h"
#include "luna.c"
// #include "bongocat.c"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_default(void) {
    oled_write_P(PSTR("Layout: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case CMT: oled_write_P(PSTR("Mod Tap\n"), false);break;
        case CMK: oled_write_P(PSTR("Colemak\n"), false); break;
        default: oled_write_P(PSTR("That's weird\n"), false);
    }
}

static void render_layer_status(void) {
    oled_write_P(PSTR("Layer:  "), false);
    switch (get_highest_layer(layer_state)) {
        // case SC2_L: oled_write_P(PSTR("Select unit\n"), false); break;
        // case GAME_L: oled_write_P(PSTR("Change weapon"), false); break;
        case NAVMT: oled_write_P(PSTR("Navigation\n"), false); break;
        case FUNMT: oled_write_P(PSTR("Function\n"), false); break;
        case SYMMT: oled_write_P(PSTR("Symbol\n"), false); break;
        case NUMMT: oled_write_P(PSTR("Number\n"), false); break;
        default: oled_write_P(PSTR("Base\n"), false);
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

static void render_hsv(void) {
    char hsv[32] = "HSV:    ";
    write_int_to_string(hsv, rgblight_get_hue());
    strcat(hsv, " ");
    write_int_to_string(hsv, rgblight_get_sat());
    strcat(hsv, " ");
    write_int_to_string(hsv, rgblight_get_val());
    oled_write_ln(hsv, false);
}

char wpm_str[10];

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_default();
        render_layer_status();
        render_os();
        render_hsv();
        animate_luna();
    } else {
        // animate_bongocat();
        oled_set_cursor(0,7);
        sprintf(wpm_str, "          %03d", get_current_wpm());
        oled_write(wpm_str, false);
    }
}
