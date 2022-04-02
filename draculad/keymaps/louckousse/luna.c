uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

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
    oled_set_cursor(3,11);
    luna_current_frame = (luna_current_frame + 1) % LUNA_FRAMES;
    oled_write_raw_P(sit[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(3,12);
    oled_write_raw_P(sit[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(3,13);
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
    oled_set_cursor(3,11);
    luna_current_frame = (luna_current_frame + 1) % LUNA_FRAMES;
    oled_write_raw_P(walk[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(3,12);
    oled_write_raw_P(walk[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(3,13);
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
    oled_set_cursor(3,11);
    oled_write_raw_P(run[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(3,12);
    oled_write_raw_P(run[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(3,13);
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
    oled_set_cursor(3,11);
    oled_write_raw_P(bark[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(3,12);
    oled_write_raw_P(bark[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(3,13);
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
    oled_set_cursor(3,11);
    oled_write_raw_P(sneak[abs(1 - luna_current_frame)][0], LUNA_SIZE/3);
    oled_set_cursor(3,12);
    oled_write_raw_P(sneak[abs(1 - luna_current_frame)][1], LUNA_SIZE/3);
    oled_set_cursor(3,13);
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
