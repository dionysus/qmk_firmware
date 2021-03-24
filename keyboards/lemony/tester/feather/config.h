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
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS { C7 } //top-bot
#define MATRIX_COL_PINS { D6 } //left-right

#define AdafruitBleResetPin D4
#define AdafruitBleCSPin B4
#define AdafruitBleIRQPin E6

#define ENCODERS_PAD_A { F7 }
#define ENCODERS_PAD_B { F6 }
#define ENCODER_RESOLUTION 4
