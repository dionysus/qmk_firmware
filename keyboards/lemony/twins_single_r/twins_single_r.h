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
#include "quantum.h"

#define ___ KC_NO

#define LAYOUT_twins( \
        R05, R04, R03, R02, R01, R00,\
        R15, R14, R13, R12, R11, R10,\
    R26, R25, R24, R23, R22, R21, R20,\
    R36, R35, R34, R33, R32, R31, R30 \
) \
{ \
    { R00, R01, R02, R03, R04, R05, ___ }, \
    { R10, R11, R12, R13, R14, R15, ___ }, \
    { R20, R21, R22, R23, R24, R25, R26 }, \
    { R30, R31, R32, R33, R34, R35, R36 }  \
}
