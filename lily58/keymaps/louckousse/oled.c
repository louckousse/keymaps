#include QMK_KEYBOARD_H
#include <string.h>
#include <stdio.h>
#include "louckousse.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

static void render_default(void) {
    oled_write_P(PSTR("Layout: "), false);
    switch (get_highest_layer(default_layer_state)) {
        case CMT: oled_write_P(PSTR("Mod Tap\n"), false); break;
        case SC2_B: oled_write_P(PSTR("For the swarm"), false); break;
        case GAME_B: oled_write_P(PSTR("SHOOT\n"), false); break;
        default: oled_write_P(PSTR("That's weird\n"), false);
    }
}

static void render_layer_status(void) {
    oled_write_P(PSTR("Layer:  "), false);
    switch (get_highest_layer(layer_state)) {
        case SC2_L: oled_write_P(PSTR("Select unit\n"), false); break;
        case GAME_L: oled_write_P(PSTR("Change weapon"), false); break;
        case NAVMT: oled_write_P(PSTR("Navigation\n"), false); break;
        case FUNMT: oled_write_P(PSTR("Function\n"), false); break;
        case SYMMT: oled_write_P(PSTR("Symbol\n"), false); break;
        case NUMMT: oled_write_P(PSTR("Number\n"), false); break;
        default: oled_write_P(PSTR("Base\n"), false);
    }
}

void write_int_to_string(char* ref, uint8_t wpm) {
    // Words per minute is just assumed to remain under a thousand.
    char wpm_string[4];
    itoa(wpm, wpm_string, 10);
    strcat(ref, wpm_string);
}

void oled_write_with_int(char* str, uint8_t number) {
    write_int_to_string(str, number);
    oled_write_ln(str, false);
}

static void render_os(void) {
    if (user_config.osIsLinux) {
        oled_write_P(PSTR("OS:     Linux-mint\n"), false);
    } else {
        oled_write_P(PSTR("OS:     Windows 10\n"), false);
    }
}

static void render_hsv(void) {
    char hue[32] = "HUE:    ";
    oled_write_with_int(hue, rgblight_get_hue());

    char sat[32] = "SAT:    ";
    oled_write_with_int(sat, rgblight_get_sat());

    char val[32] = "VAL:    ";
    oled_write_with_int(val, rgblight_get_val());
}

const char *read_logo(void);

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_default();
        render_layer_status();
        render_os();
        // render_hsv();
    } else {
        oled_write(read_logo(), false);
    }
}
