/* Copyright 2019 Thomas Baart
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
#include "zima.h"
#include <stdio.h>

#ifdef HAPTIC_ENABLE
#    include "haptic.h"
extern haptic_config_t haptic_config;
#endif

static bool is_asleep = false;
static uint32_t oled_timer;

__attribute__((weak)) void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code16(KC_VOLU);
    } else {
        tap_code16(KC_VOLD);
    }
    oled_timer = timer_read32();
#if defined(AUDIO_ENABLE) && defined(AUDIO_CLICKY)
    if (is_audio_on() && is_clicky_on()) clicky_play();
#endif
#ifdef HAPTIC_ENABLE
    if (haptic_config.enable) haptic_play();
#endif
}
