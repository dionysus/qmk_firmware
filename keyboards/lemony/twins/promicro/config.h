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

/* MITTENS pro-micro default pinout */
#define MATRIX_ROW_PINS { D4, F4, F7, B2 } //top-bot
#define MATRIX_COL_PINS { D7, C6, F6, F5, B3, B1, B6} //left-right
#define MATRIX_ROW_PINS_RIGHT { D3, F6, B3, B6 } //top-bot
#define MATRIX_COL_PINS_RIGHT { B2, B1, F7, F5, F4, C6, D7} //left-right

#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { B4 }
#define ENCODERS_PAD_A_RIGHT { B5 }
#define ENCODERS_PAD_B_RIGHT { B4 }
#define ENCODER_RESOLUTION 4

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define SOFT_SERIAL_PIN D2

/* SPLIT */
#define USE_SERIAL

/* OLED */
// #define OLED_DISPLAY_ADDRESS 0x3c
// #define OLED_IC OLED_IC_SSD1306
// #define OLED_FONT_H "glcdfont.c"
// #define OLED_TIMEOUT  10000
