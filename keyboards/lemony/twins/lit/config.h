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
// #define MATRIX_COL_PINS { B3, D4, C6, D7, E6, B4, B5 } //left-right
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4, B3 } //left-right
#define MATRIX_ROW_PINS_RIGHT { F4, D3, B1, F7 } //top-bot
#define MATRIX_COL_PINS_RIGHT {  B5, B4, E6, D7, C6, D4, B3 } //left-right
// #define MATRIX_COL_PINS_RIGHT {  B3, D4, C6, D7, E6, B4, B5 } //left-right

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

#ifdef RGB_MATRIX_ENABLE
  /* LED */
  // The pin connected to the data pin of the LEDs
  // #define RGBLIGHT_SPLIT
  #define RGB_DI_PIN F5
  // The number of LEDs connected
  // #define DRIVER_LED_TOTAL 50
  // #define RGBLED_NUM 25    // Number of LEDs (each hand)
  // #define RGBLIGHT_SPLIT
  #define RGBLIGHT_LIMIT_VAL 120
  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS RGBLIGHT_LIMIT_VAL // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
  #define RGBLED_NUM_LEFT   25
  #define RGBLED_NUM_RIGHT  25
  #undef  RGBLED_NUM
  #define RGBLED_NUM        (RGBLED_NUM_LEFT+RGBLED_NUM_RIGHT)
  #define RGBLED_SPLIT      { RGBLED_NUM_LEFT, RGBLED_NUM_RIGHT }
  #define RGB_MATRIX_SPLIT RGBLED_SPLIT
  #define DRIVER_LED_TOTAL  RGBLED_NUM
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  // #define RGBLIGHT_ANIMATIONS
  #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
  // #define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
  // #define RGB_DISABLE_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
  // #define RGB_DISABLE_WHEN_USB_SUSPENDED false // turn off effects when suspended
  // #define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
  #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
  // #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_CROSS// Sets the default mode, if none has been set
  // #define RGB_SPLIT_MASTER
  #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP// Sets the default mode, if none has been set
  // #define RGB_MATRIX_STARTUP_HUE 0 // Sets the default hue value, if none has been set
  // #define RGB_MATRIX_STARTUP_SAT 255 // Sets the default saturation value, if none has been set
  #define RGB_MATRIX_STARTUP_VAL 60 // Sets the default brightness value, if none has been set
  #define RGB_MATRIX_STARTUP_SPD 16 // Sets the default animation speed, if none has been set
  // #define RGB_MATRIX_DISABLE_KEYCODES // disabl

  #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #define DISABLE_RGB_MATRIX_BREATHING
  #define DISABLE_RGB_MATRIX_CYCLE_ALL
  // #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  // #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
  #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
  #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
  #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #define DISABLE_RGB_MATRIX_DUAL_BEACON
  #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
  #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  #define DISABLE_RGB_MATRIX_RAINDROPS
  #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
  // #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
  // #define DISABLE_RGB_MATRIX_DIGITAL_RAIN
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  // #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  #define DISABLE_RGB_MATRIX_SPLASH
  #define DISABLE_RGB_MATRIX_MULTISPLASH
  #define DISABLE_RGB_MATRIX_SOLID_SPLASH
  #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif