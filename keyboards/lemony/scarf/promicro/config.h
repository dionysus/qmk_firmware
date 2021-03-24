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

/* SCARF pro-micro default pinout */
#define MATRIX_ROW_PINS { B4, E6, B2, B3, B5 } //top-bot
#define MATRIX_COL_PINS { D3, D2, D4, C6, D7, B1, F7, F6, F5, F4 } //left-right

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* OLED */
// #define OLED_DISPLAY_ADDRESS 0x3c
// #define OLED_IC OLED_IC_SSD1306
// #define OLED_FONT_H "glcdfont.c"
// #define OLED_TIMEOUT 0

// #endif