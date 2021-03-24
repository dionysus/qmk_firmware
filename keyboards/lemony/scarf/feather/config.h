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

/* cATTACK! default pinout */
#define MATRIX_ROW_PINS { D2, F0, C6, D7, D3 } //top-bot
#define MATRIX_COL_PINS { F7, F6, F5, F4, F1, B5, B6, B7, D6, C7 } //left-right

#define AdafruitBleResetPin D4
#define AdafruitBleCSPin B4
#define AdafruitBleIRQPin E6

#define OLED_TIMEOUT 0
#define OLED_SCROLL_TIMEOUT	0
