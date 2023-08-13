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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4c59 // LEMONY
#define DEVICE_VER      0x0001
#define MANUFACTURER    lemony.org
#define PRODUCT         TWINS
#define DESCRIPTION     Single Right Board Macropad
#define PRODUCT_ID      0x0002 // TWINS

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 7

#define MATRIX_ROW_PINS { F4, D3, B1, F7 } //top-bot
#define MATRIX_COL_PINS { B3, B5, B4, E6, D7, C6, D4 } //left-right

#define DIODE_DIRECTION COL2ROW
#define TAPPING_TOGGLE 2

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
#define SOFT_SERIAL_PIN D2

/* SPLIT */
#define USE_SERIAL