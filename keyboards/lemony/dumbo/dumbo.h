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

#define LAYOUT_DUMBO( \
      A1, A2, A3, A4, A5, A6, A7, A8, F1, F8, G1, G8, H1, H8, \
      B1, B2, B3, B4, B5, B6, B7, B8, F2, F7, G2, G7, H2, H7, \
      C1, C2, C3, C4, C5, C6, C7, C8, F3, F6, G3, G6, H3, \
      D1, D2, D3, D4, D5, D6, D7, D8, F4, F5, G4, G5, H4, H6, \
      E1, E2, E3, E4, E5, E6, E7, H5, E8 \
) { \
    {A1, A2, A3, A4, A5, A6, A7, A8}, \
    {B1, B2, B3, B4, B5, B6, B7, B8}, \
    {C1, C2, C3, C4, C5, C6, C7, C8}, \
    {D1, D2, D3, D4, D5, D6, D7, D8}, \
    {E1, E2, E3, E4, E5, E6, E7, E8}, \
    {F1, F2, F3, F4, F5, F6, F7, F8}, \
    {G1, G2, G3, G4, G5, G6, G7, G8}, \
    {H1, H2, H3, H4, H5, H6, H7, H8} \
}
