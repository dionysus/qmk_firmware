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
#define MATRIX_ROW_PINS { F4, D3, B1, F7 } //top-bot
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5, B3 } //left-right
#define MATRIX_ROW_PINS_RIGHT { F4, D3, B1, F7 } //top-bot
#define MATRIX_COL_PINS_RIGHT { B3, B5, B4, E6, D7, C6, D4 } //left-right

#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B6 }
#define ENCODERS_PAD_A_RIGHT { B2 }
#define ENCODERS_PAD_B_RIGHT { B6 }
#define ENCODER_RESOLUTION 4

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define SOFT_SERIAL_PIN D2

/* SPLIT */
#define USE_SERIAL

/* OLED */