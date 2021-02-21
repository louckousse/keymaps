#include QMK_KEYBOARD_H
#include <string.h>
#include <stdio.h>
#include "louckousse.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

// WPM-responsive animation stuff here
#define IDLE_FRAMES 5
#define IDLE_SPEED 25 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 45 // above this wpm value typing animation to trigger

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
#define ANIM_SIZE 636 // number of bytes in array, minimize for adequate firmware size, max is 1024
#define LINE_SIZE 128

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 0;

// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.
#define FRAME_SIZE 636
static const uint16_t PROGMEM diff_regions_boundaries[9] = {58, 58, 58, 84, 92, 100, 120, 152, 174};
static const uint16_t PROGMEM diff_regions[174] = {2, 8, 9, 15, 16, 22, 23, 25, 26, 32, 58, 79, 125, 128, 132, 159, 177, 186, 190, 192, 201, 202, 203, 205, 206, 216, 219, 253, 258, 261, 262, 285, 286, 289, 304, 308, 315, 320, 321, 347, 365, 380, 386, 389, 390, 413, 414, 451, 493, 508, 512, 543, 621, 625, 626, 631, 632, 636, 58, 69, 71, 74, 75, 79, 177, 181, 183, 187, 190, 192, 201, 202, 203, 205, 206, 216, 304, 308, 315, 320, 323, 330, 334, 338, 51, 53, 69, 76, 177, 183, 304, 307, 69, 70, 71, 77, 177, 181, 304, 307, 51, 53, 69, 76, 177, 183, 185, 188, 206, 217, 304, 307, 310, 321, 322, 323, 336, 345, 441, 451, 51, 53, 69, 76, 86, 90, 95, 97, 177, 183, 185, 188, 206, 210, 214, 218, 219, 227, 304, 307, 310, 321, 322, 323, 346, 355, 416, 417, 441, 451, 477, 480, 51, 53, 69, 76, 177, 183, 206, 217, 304, 307, 315, 319, 336, 345, 433, 441, 448, 452, 565, 572, 576, 584};
static const uint16_t PROGMEM diff_bytes_boundaries[9] = {336, 336, 336, 397, 415, 429, 492, 570, 639};
static const char PROGMEM diff_bytes[639] = {126, 126, 24, 60, 102, 66, 12, 28, 112, 112, 28, 12, 116, 116, 20, 20, 124, 104, 124, 124, 112, 120, 44, 36, 124, 124, 128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 4, 4, 4, 8, 48, 64, 128, 128, 128, 128, 192, 96, 48, 24, 12, 132, 198, 98, 35, 51, 17, 145, 113, 241, 113, 145, 17, 51, 35, 98, 198, 132, 12, 24, 48, 96, 192, 24, 100, 130, 2, 2, 2, 2, 2, 1, 128, 128, 128, 48, 48, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 196, 4, 196, 4, 196, 2, 194, 2, 194, 1, 1, 1, 1, 252, 15, 1, 248, 14, 31, 109, 140, 148, 148, 164, 166, 249, 224, 255, 224, 249, 166, 164, 148, 148, 140, 109, 31, 14, 248, 1, 15, 252, 192, 56, 4, 3, 12, 12, 12, 13, 1, 64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8, 8, 8, 4, 4, 8, 8, 16, 16, 16, 16, 16, 17, 15, 1, 1, 170, 170, 255, 255, 195, 191, 127, 3, 127, 191, 195, 255, 255, 170, 170, 31, 120, 192, 15, 56, 124, 219, 152, 20, 20, 18, 50, 207, 3, 255, 3, 207, 50, 18, 20, 20, 152, 219, 124, 56, 15, 192, 120, 31, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8, 8, 8, 8, 7, 2, 130, 135, 31, 7, 159, 7, 28, 7, 159, 7, 159, 7, 2, 130, 32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98, 102, 68, 68, 71, 71, 71, 68, 68, 102, 98, 35, 49, 16, 24, 12, 6, 3, 1, 7, 8, 8, 23, 15, 1, 2, 1, 15, 15, 2, 5, 8, 0, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 4, 2, 2, 24, 96, 128, 0, 60, 194, 1, 1, 4, 4, 2, 1, 0, 0, 0, 96, 96, 129, 130, 130, 132, 8, 16, 32, 64, 128, 0, 128, 112, 25, 6, 24, 24, 24, 27, 3, 34, 36, 20, 18, 18, 18, 11, 5, 5, 9, 9, 128, 128, 8, 4, 2, 1, 1, 2, 12, 30, 225, 0, 0, 1, 1, 128, 112, 12, 8, 4, 2, 2, 2, 4, 56, 28, 226, 1, 1, 128, 112, 12, 128, 128, 8, 4, 2, 1, 1, 2, 12, 30, 225, 0, 0, 1, 1, 129, 128, 128, 0, 1, 225, 26, 6, 9, 49, 53, 1, 138, 124, 128, 112, 12, 24, 6, 5, 152, 153, 132, 195, 124, 65, 65, 64, 32, 4, 4, 4, 4, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 8, 4, 2, 1, 1, 2, 12, 248, 248, 248, 248, 128, 128, 30, 225, 0, 0, 1, 1, 129, 128, 128, 0, 1, 1, 2, 67, 135, 7, 1, 184, 188, 190, 159, 95, 95, 79, 76, 128, 112, 12, 24, 6, 5, 152, 153, 132, 67, 124, 65, 65, 64, 32, 61, 124, 252, 252, 252, 252, 252, 60, 12, 63, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 128, 128, 8, 4, 2, 1, 1, 2, 12, 30, 225, 0, 0, 1, 1, 0, 1, 225, 26, 6, 9, 49, 53, 1, 138, 124, 128, 112, 12, 0, 0, 0, 1, 4, 4, 4, 4, 2, 2, 2, 1, 1, 122, 122, 121, 121, 121, 121, 57, 49, 136, 136, 135, 128, 48, 120, 124, 254, 255, 63, 7, 255, 255, 127, 127, 63, 62, 28, 24};

// S/O to @pierrechevalier83 for the light bongo implementation
void write_frame(const uint16_t* regions, const uint16_t regions_len, const char* diff, const uint16_t diff_len) {
    uint16_t diff_index = 0;
    for (uint16_t region_index = 0; region_index < regions_len; region_index += 2) {
        uint16_t start = pgm_read_word_near(regions + region_index);
        uint16_t end = pgm_read_word_near(regions + region_index + 1);
        oled_write_raw_range_P(diff + diff_index,start , end);
        diff_index += end - start;
    }
}

void write_frame_diff(const uint16_t region_begin, const uint16_t region_end, const uint16_t bytes_begin) {
    uint16_t diff_index = 0;
    for (uint16_t region_index = region_begin; region_index < region_end; region_index += 2) {
        uint16_t start = pgm_read_word_near(&diff_regions[region_index]);
        uint16_t end = pgm_read_word_near(&diff_regions[region_index + 1]);
        oled_write_raw_range_P(&diff_bytes[bytes_begin + diff_index], start, end);
        diff_index += end - start;
    }
}

void write_base_frame(void) {
    oled_clear();
    const uint16_t region_begin = 0;
    const uint16_t region_end = pgm_read_word_near(&diff_regions_boundaries[0]);
    const uint16_t bytes_begin = 0;
    write_frame_diff(region_begin, region_end, bytes_begin);
}

void write_frame_at_index(int index) {
    write_base_frame();
    const uint16_t region_begin = pgm_read_word_near(&diff_regions_boundaries[index]);
    const uint16_t region_end = pgm_read_word_near(&diff_regions_boundaries[index + 1]);
    const uint16_t bytes_begin = pgm_read_word_near(&diff_bytes_boundaries[index]);
    write_frame_diff(region_begin, region_end, bytes_begin);
}

static void render_anim(void) {
  void animation_phase(void) {
    if(get_current_wpm() <=IDLE_SPEED){
        current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
        int index = abs(IDLE_FRAMES - 1 - current_idle_frame);
        write_frame_at_index(index);
     }
     if(get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED){
         int index = IDLE_FRAMES;
         write_frame_at_index(index);
     }
     if(get_current_wpm() >= TAP_SPEED){
         current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
         int index = IDLE_FRAMES + 1 + abs(TAP_FRAMES - 1 - current_tap_frame);
         write_frame_at_index(index);
     }
  }

  if(get_current_wpm() != 0) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress

        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

/* ---------- LUNA ANIMATION -------- */

/* Graphical Luna dog animation display, requires WPM_ENABLE.
   Luna is 4x3 on OLED and its optimized for Kyria.
   Modified from @HellSingCoder's Luna dog
   (https://github.com/HellSingCoder/qmk_firmware/tree/master/keyboards/sofle/keymaps/HellSingCoder)

   Based on filterpaper code
   https://github.com/filterpaper/qmk_firmware/blob/filterspace/users/filterpaper/luna.c
*/

// Animation frame defaults
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 40
#define LUNA_SIZE 96 // 96-byte arrays for the little dog
#define LUNA_FRAMES 2
#define LUNA_FRAME_DURATION 200 // Number of ms per frame

uint32_t luna_anim_timer = 0;
uint32_t luna_anim_sleep = 0;
uint8_t luna_current_frame = 0;
static long int luna_oled_timeout = 50000;

static void render_luna_sit(void) {
    static const char PROGMEM sit[LUNA_FRAMES][3][LUNA_SIZE/3] = {
        {
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x1c,
            0x02,0x05,0x02,0x24,0x04,0x04,0x02,0xa9,0x1e,0xe0,0x00,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x10,0x08,0x68,0x10,0x08,0x04,0x03,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x02,0x06,0x82,0x7c,0x03,0x00,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x04,0x0c,0x10,0x10,0x20,0x20,0x20,0x28,
            0x3e,0x1c,0x20,0x20,0x3e,0x0f,0x11,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        },
        {
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x1c,
            0x02,0x05,0x02,0x24,0x04,0x04,0x02,0xa9,0x1e,0xe0,0x00,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0xe0,0x90,0x08,0x18,0x60,0x10,0x08,0x04,0x03,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x02,0x0e,0x82,0x7c,0x03,0x00,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x04,0x0c,0x10,0x10,0x20,0x20,0x20,0x28,
            0x3e,0x1c,0x20,0x20,0x3e,0x0f,0x11,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        }
    };
    oled_set_cursor(7,5);
    luna_current_frame = (luna_current_frame + 1) % LUNA_FRAMES;
    oled_write_raw_P(sit[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(7,6);
    oled_write_raw_P(sit[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(7,7);
    oled_write_raw_P(sit[abs(1 - luna_current_frame)][2], LUNA_SIZE/3);
}

static void render_luna_walk(void) {
    static const char PROGMEM walk[LUNA_FRAMES][3][LUNA_SIZE/3] = {
        {
            {0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x20,0x10,0x90,0x90,0x90,0xa0,0xc0,0x80,0x80,
            0x80,0x70,0x08,0x14,0x08,0x90,0x10,0x10,0x08,0xa4,0x78,0x80,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x07,0x08,0xfc,0x01,0x00,0x00,0x00,0x00,0x80,0x00,0x00,
            0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x18,0xea,0x10,0x0f,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1c,0x20,0x20,0x3c,0x0f,0x11,0x1f,0x03,
            0x06,0x18,0x20,0x20,0x3c,0x0c,0x12,0x1e,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        },
        {
            {0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x20,0x20,0x20,0x40,0x80,0x00,0x00,0x00,
            0x00,0xe0,0x10,0x28,0x10,0x20,0x20,0x20,0x10,0x48,0xf0,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x1f,0x20,0xf8,0x02,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
            0x03,0x00,0x00,0x00,0x00,0x01,0x00,0x10,0x30,0xd5,0x20,0x1f,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x20,0x30,0x0c,0x02,0x05,0x09,0x12,0x1e,
            0x02,0x1c,0x14,0x08,0x10,0x20,0x2c,0x32,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        }
    };
    oled_set_cursor(7,5);
    luna_current_frame = (luna_current_frame + 1) % LUNA_FRAMES;
    oled_write_raw_P(walk[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(7,6);
    oled_write_raw_P(walk[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(7,7);
    oled_write_raw_P(walk[abs(1 - luna_current_frame)][2], LUNA_SIZE / 3);
}

static void render_luna_run(void) {
    static const char PROGMEM run[LUNA_FRAMES][3][LUNA_SIZE/3] = {
        {
            {0x00,0x00,0x00,0x00,0xe0,0x10,0x08,0x08,0xc8,0xb0,0x80,0x80,0x80,0x80,0x80,0x80,
            0x80,0x40,0x40,0x3c,0x14,0x04,0x08,0x90,0x18,0x04,0x08,0xb0,0x40,0x80,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x01,0x02,0xc4,0xa4,0xfc,0x00,0x00,0x00,0x00,0x80,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc8,0x58,0x28,0x2a,0x10,0x0f,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x0e,0x09,0x04,0x04,0x04,0x04,0x02,0x03,0x02,0x01,0x01,
            0x02,0x02,0x04,0x08,0x10,0x26,0x2b,0x32,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x00}
        },
        {
            {0x00,0x00,0x00,0xe0,0x10,0x10,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
            0x80,0x80,0x78,0x28,0x08,0x10,0x20,0x30,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x03,0x04,0x08,0x10,0x11,0xf9,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x10,0xb0,0x50,0x55,0x20,0x1f,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x0c,0x10,0x20,0x28,0x37,
            0x02,0x1e,0x20,0x20,0x18,0x0c,0x14,0x1e,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        }
    };
    luna_current_frame = (luna_current_frame + 1) % LUNA_FRAMES;
    oled_set_cursor(7,5);
    oled_write_raw_P(run[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(7,6);
    oled_write_raw_P(run[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(7,7);
    oled_write_raw_P(run[abs(1 - luna_current_frame)][2], LUNA_SIZE / 3);
}

static void render_luna_bark(void) {
    static const char PROGMEM bark[LUNA_FRAMES][3][LUNA_SIZE/3] = {
        {
            {0x00,0xc0,0x20,0x10,0xd0,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x40,
            0x3c,0x14,0x04,0x08,0x90,0x18,0x04,0x08,0xb0,0x40,0x80,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x03,0x04,0x08,0x10,0x11,0xf9,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x80,0xc8,0x48,0x28,0x2a,0x10,0x0f,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x0c,0x10,0x20,0x28,0x37,0x02,0x02,
            0x04,0x08,0x10,0x26,0x2b,0x32,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        },
        {
            {0x00,0xe0,0x10,0x10,0xf0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x40,
            0x40,0x2c,0x14,0x04,0x08,0x90,0x18,0x04,0x08,0xb0,0x40,0x80,0x00,0x00,0x00,0x00},
            {0x00,0x03,0x04,0x08,0x10,0x11,0xf9,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0x48,0x28,0x2a,0x10,0x0f,0x20,0x4a,0x09,0x10},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x0c,0x10,0x20,0x28,0x37,0x02,0x02,
            0x04,0x08,0x10,0x26,0x2b,0x32,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
        }
    };
    luna_current_frame = (luna_current_frame + 1) % LUNA_FRAMES;
    oled_set_cursor(7,5);
    oled_write_raw_P(bark[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(7,6);
    oled_write_raw_P(bark[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(7,7);
    oled_write_raw_P(bark[abs(1 - luna_current_frame)][2], LUNA_SIZE / 3);
}

static void render_luna_sneak(void) {
    static const char PROGMEM sneak[LUNA_FRAMES][3][LUNA_SIZE/3] = {
        {
            {0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x40,0x40,0x40,0x80,0x00,0x00,0x00,0x00,
            0x00,0x00,0xc0,0x40,0x40,0x80,0x00,0x80,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x1e,0x21,0xf0,0x04,0x02,0x02,0x02,0x02,0x03,0x02,0x02,0x04,
            0x04,0x04,0x03,0x01,0x00,0x00,0x09,0x01,0x80,0x80,0xab,0x04,0xf8,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1c,0x20,0x20,0x3c,0x0f,0x11,0x1f,0x02,0x06,
            0x18,0x20,0x20,0x38,0x08,0x10,0x18,0x04,0x04,0x02,0x02,0x01,0x00,0x00,0x00,0x00}
        },
        {
            {0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,0x40,0x40,0x80,0x00,0x00,0x00,0x00,0x00,
            0x00,0x00,0xe0,0xa0,0x20,0x40,0x80,0xc0,0x20,0x40,0x80,0x00,0x00,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x3e,0x41,0xf0,0x04,0x02,0x02,0x02,0x03,0x02,0x02,0x02,0x04,
            0x04,0x02,0x01,0x00,0x00,0x00,0x04,0x00,0x40,0x40,0x55,0x82,0x7c,0x00,0x00,0x00},
            {0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x20,0x30,0x0c,0x02,0x05,0x09,0x12,0x1e,0x04,
            0x18,0x10,0x08,0x10,0x20,0x28,0x34,0x06,0x02,0x01,0x01,0x00,0x00,0x00,0x00,0x00}
        }
    };
    luna_current_frame = (luna_current_frame + 1) % LUNA_FRAMES;
    oled_set_cursor(7,5);
    oled_write_raw_P(sneak[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(7,6);
    oled_write_raw_P(sneak[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(7,7);
    oled_write_raw_P(sneak[abs(1 - luna_current_frame)][2], LUNA_SIZE / 3);
}

void animate_luna(void) {

    void animation_phase(void) {
        if (get_mods() & (MOD_MASK_SHIFT)) { render_luna_bark(); }
        else if (get_mods() & (MOD_MASK_CAG)) { render_luna_sneak(); }
        else if (get_current_wpm() <= MIN_WALK_SPEED) { render_luna_sit(); }
        else if (get_current_wpm() <= MIN_RUN_SPEED) { render_luna_walk(); }
        else { render_luna_run(); }
    }

    // Animate on WPM, turn off OLED on idle
    if (get_current_wpm() != 000 || host_keyboard_led_state().caps_lock || get_mods() & (MOD_MASK_CSAG)) {
        oled_on();
        if (timer_elapsed32(luna_anim_timer) >LUNA_FRAME_DURATION) {
            luna_anim_timer = timer_read32();
            animation_phase();
        }
        luna_anim_sleep = timer_read32();
    } else {
        if (timer_elapsed32(luna_anim_sleep) > luna_oled_timeout) {
            oled_off();
        } else {
            if (timer_elapsed32(luna_anim_timer) >LUNA_FRAME_DURATION) {
                luna_anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
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
        render_anim();
        oled_set_cursor(0,7);
        sprintf(wpm_str, "          %03d", get_current_wpm());
        oled_write(wpm_str, false);
    }
}
