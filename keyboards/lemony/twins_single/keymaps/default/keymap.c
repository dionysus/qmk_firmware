#include QMK_KEYBOARD_H
#include "shortcuts.h"
#include "functions.h"
#ifdef OLED_DRIVER_ENABLE
#include "oled.h"
#endif

enum layers {
  _DEFAULT,
  _SYMBOL,
  _RECT,
  _DEBUG,
  _GAME,
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

#define NUMBER  TT(_NUMBER)
#define SYMBOL  MO(_SYMBOL)
#define RECT    MO(_RECT)
#define FN      MO(_FN)

//! KEYMAPS --------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT] = LAYOUT_twins_single(
    KC_ESC , KC_7   , KC_8   , KC_9   , KC_PSLS, KC_BSPC,
    _______, KC_4   , KC_5   , KC_6   , KC_PAST, KC_DEL ,
    SCRNCPY, KC_1   , KC_2   , KC_3   , KC_PMNS, KC_TAB , ENC_L  ,
    SYMBOL , KC_0   , KC_0   , KC_DOT , KC_PPLS, KC_PEQL, KC_ENT
  ),

  [_SYMBOL] = LAYOUT_twins_single(
    _______, KC_AMPR, KC_ASTR, _______, _______, _______,
    _______, KC_DLR , KC_PERC, KC_CIRC, _______, _______,
    _______, KC_EXLM, KC_AT  , KC_HASH, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_PEQL
  ),

  [_RECT] = LAYOUT_twins_single(
    RECT_UL, RECT_UR, RECT_3L, RECT_3C, RECT_3R, _______,
    RECT_LL, RECT_LR, RECT_3F, RECT_3C, RECT_3E, _______,
    RECT_L , RECT_R , _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______
  ),

  [_DEBUG] = LAYOUT_twins_single(
    VS_STOP, _______, _______, _______, _______, _______,
    VS_CONT, VS_STOV, _______, _______, _______, _______,
    VS_STOT, VS_STIN, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______
  ),

  [_GAME] = LAYOUT_twins_single(
    KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,
    KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______,
    KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, KC_SPC
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

  void encoder_update_user(uint8_t index, bool clockwise) {
    //* SET AND APPLY CURRENT LAYER
    // if (index == 0) {
    //   if (clockwise) {
    //     CURR_LAYER = (CURR_LAYER + 1) % NUM_LAYERS;
    //   } else {
    //     CURR_LAYER = (CURR_LAYER - 1) % NUM_LAYERS;
    //   }
    //   layer_move(CURR_LAYER);
    // }
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
        case _DEBUG:    oled_write_P(PSTR("DBUG"), false);
          break;
        case _GAME:     oled_write_P(PSTR("GAME"), false);
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
        CURR_LAYER = increment_layer(CURR_LAYER, NUM_LAYERS);
      }
      break;
    #endif
  }
  return true;
}

