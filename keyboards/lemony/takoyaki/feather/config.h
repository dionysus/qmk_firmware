/* Copyright 2019 Sebastian Williams
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
#pragma once
#include "config_common.h"

/* MITTENS feather pinout */
#define MATRIX_ROW_PINS { F7, F1, F6 } //top-bot
#define MATRIX_COL_PINS { D7, F0, F4, F5} //left-right

#define ENCODERS_PAD_A { B7, C6, D3 }
#define ENCODERS_PAD_B { B6, B5, D2 }
#define ENCODER_RESOLUTION 4

#define AdafruitBleResetPin D4
#define AdafruitBleCSPin B4
#define AdafruitBleIRQPin E6

// #define OLED_TIMEOUT 0
// #define OLED_SCROLL_TIMEOUT	0

// RESET with boot + bottom right
// #define BOOTMAGIC_LITE_ROW 3
// #define BOOTMAGIC_LITE_COLUMN 2

#ifndef IS_COMMAND
#define IS_COMMAND()(get_mods() == (MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT)))
#endif

