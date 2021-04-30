#include QMK_KEYBOARD_H
#include "shortcuts.h"
#ifdef OLED_DRIVER_ENABLE
#include "oled.h"
#endif

enum layers {
  _DEFAULT,
  _SYMBOL,
  _RECT,
  _DEBUG,
  _END
};
int CURR_LAYER = 0;
int NUM_LAYERS = _END - _DEFAULT;

enum my_keycodes {
  ENC_L = SAFE_RANGE,   // Encoder Left push button
  TOG_OS,
};
int OS = 0; // 0 = mac, 1 = win

//! LAYERS ------------------------------------------------------------

#define NUMBER TT(_NUMBER)
#define SYMBOL MO(_SYMBOL)
#define RECT   MO(_RECT)
#define FN MO(_FN)

//! KEYMAPS --------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_DEFAULT] = LAYOUT_twins_single(
    _______, _______, KC_P7  , KC_P8  , KC_P9  , KC_PSLS,
    _______, _______, KC_P4  , KC_P5  , KC_P6  , KC_PAST,
    SCRNCPY, _______, KC_P1  , KC_P2  , KC_P3  , KC_PMNS, ENC_L  ,
    SYMBOL , RECT   , KC_P0  , KC_PDOT, KC_BSPC, KC_PPLS, KC_PEQL
  ),

  [_SYMBOL] = LAYOUT_twins_single(
    _______, _______, KC_AMPR, KC_ASTR, _______, _______,
    _______, _______, KC_DLR , KC_PERC, KC_CIRC, _______,
    _______, _______, KC_EXLM, KC_AT  , KC_HASH, _______, _______,
    _______ , _______, _______, _______, _______, _______, _______
  ),

  [_RECT] = LAYOUT_twins_single(
  	RECT_UL, RECT_UR, RECT_3L, RECT_3C, RECT_3R, _______,
  	RECT_LL, RECT_LR, RECT_3F, RECT_3C, RECT_3E, _______,
  	RECT_L , RECT_R , _______, _______, _______, _______, _______,
  	_______ , _______, _______, _______, _______, _______, _______
  ),

  [_DEBUG] = LAYOUT_twins_single(
    VS_STOP, _______, _______, _______, _______, _______,
    VS_CONT, VS_STOV, _______, _______, _______, _______,
    VS_STOT, VS_STIN, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______
  ),

  // [BLANK] = LAYOUT_twins_single(
  //   _______, _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______, _______, _______,
  //   _______, _______, _______, _______, _______, _______, _______
  // ),

};




//! ENCODERS -------------------------------------------------------------------

#ifdef ENCODER_ENABLE

  // defining Encoder Layers
  int ENC_LAYER_L = 0;
  int enc_layers_L = 4;

  // define shortcuts ----------------------------------------------------------


  // defining Encoder actions (rotation) ---------------------------------------

  void encoder_update_user(uint8_t index, bool clockwise) {
    //* SET AND APPLY CURRENT LAYER
    if (index == 0) {
        if (clockwise) {
        if (CURR_LAYER == _END - 1) {
            CURR_LAYER = _DEFAULT;
        } else {
            CURR_LAYER++;
        }
        } else {
        if (CURR_LAYER == _DEFAULT) {
            CURR_LAYER = _END - 1;
        } else {
            CURR_LAYER--;
        }
        }
        layer_move(CURR_LAYER);
    }
  }
#endif

//! OLED -----------------------------------------------------------------------

#ifdef OLED_DRIVER_ENABLE

  void render_status(void) {
    // cursor (w:0-4, h:0-15)

    #ifdef ENCODER_ENABLE

      //! LAYERS
      int start = 6;

      oled_set_cursor(0,start++); // vertical offset to bottom
      oled_write_P(PSTR("<"), false);
      switch (CURR_LAYER + _DEFAULT) {
        case _DEFAULT:  oled_write_P(PSTR("NUMS"), false);
          break;
        case _SYMBOL:   oled_write_P(PSTR("SYMS"), false);
          break;
        case _RECT:     oled_write_P(PSTR("RECT"), false);
          break;
        default:        oled_write_P(PSTR("XXXX"), false);
      }

    #endif

  }

  oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
  }

  // OLED - Render
  void oled_task_user(void) {
    render_status();
  }
#endif

//! CUSTOM KEYPRESS ------------------------------------------------------------


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // ENCODER BUTTON PRESS
    #ifdef ENCODER_ENABLE
    case ENC_L:
      if (record->event.pressed) {
        ENC_LAYER_L = (ENC_LAYER_L + 1) % enc_layers_L;
      }
      break;
    #endif

  }
  return true;
}

