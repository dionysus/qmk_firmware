#include QMK_KEYBOARD_H
#include "helpers.c"
#include "oled.c"

enum layers {
  _DEFAULT,
  _COPIER,
  _END
};
int CURR_LAYER = 0;
int NUM_LAYERS = _END - _DEFAULT;

enum my_keycodes {
  YT_TS_PASTE = SAFE_RANGE,
};

//! SHORTCUTS ------------------------------------------------------------------

// COPIER
#define COPY C(KC_C)
#define PASTE C(KC_V)
#define YT_COPY A(KC_T)

//! LAYERS ---------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT_arrow(
        KC_UP ,
        KC_LEFT , KC_DOWN , KC_RIGHT  
    ),
    [_COPIER] = LAYOUT_arrow(
        COPY ,
        YT_COPY , PASTE , YT_TS_PASTE
    ),
};

//! CUSTOM KEY SHORTCUTS ----------------------------------------------------------

// int pnum_100 = 0;
// int pnum_10 = 0;
// int pnum_1 = 0;
int pnum = 0;

void yt_timestamp(void) {
  // PASTE timecode
  register_code(KC_LCTL);
  tap_code(KC_V);
  unregister_code(KC_LCTL);
  tap_code(KC_SPC);
  if (pnum >= 0){
    register_code(KC_LSFT);
    tap_code(KC_P);
    unregister_code(KC_LSFT);
    tap_nums(pnum);
    tap_code(KC_SPC);
    tap_code(KC_MINUS);
    tap_code(KC_SPC);
    pnum++;
  } else {
    tap_code(KC_MINUS);
    tap_code(KC_SPC);
  }

}

//* SET CUSTOM KEY
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case YT_TS_PASTE:
      if (record->event.pressed) {
        yt_timestamp();
      }
      break;
  }
  return true;
}

//! ENCODER ACTIONS ------------------------------------------------------------

bool encoder_update_user(uint8_t index, bool clockwise) {

  // 0 1 S
  // 2 X S
  // X X X
  //* SET AND APPLY CURRENT LAYER
  if (index == 1) {
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

  if (CURR_LAYER == _COPIER) {
    // 0 1 *
    // 2 X *
    // X X X
    // if (index == 0) ;
    if (index == 2) {
      if (clockwise) {
        if (pnum < 999) pnum++;
      } else {
        if (pnum >= 0) pnum--;
      }
    }
  }
  return true;
}

//! OLED -----------------------------------------------------------------------

void render_status(void) {
  // cursor (w:0-4, h:0-15)

  int start = 0;
  //! LAYERS 
  oled_set_cursor(0,start++); // vertical offset to bottom
  oled_write_P(PSTR(">"), false);
  switch (get_highest_layer(layer_state)) {
    case _DEFAULT:
      oled_write_P(PSTR("DEF "), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("-----"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("  ^  "), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("< V >"), false);
      break;
    case _COPIER:
      oled_write_P(PSTR("COPY"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("-----"), false);
      oled_write_P(PSTR("#"), false);
      display_nums(pnum);
      oled_write_P(PSTR("-----"), false);
      oled_write_P(PSTR("  C  "), false);
      oled_write_P(PSTR("Y P >"), false);
      break;
    default:
      oled_write_P(PSTR("XXXX"), false);
  }

  // PRINT TEMPLATE
  // O O S
  // O X S
  // X X X
  start = 7;
  oled_set_cursor(0,start++);
  oled_write_P(PSTR("O O S"), false);
  oled_set_cursor(0,start++);
  oled_write_P(PSTR("O X S"), false);
  oled_set_cursor(0,start++);
  oled_write_P(PSTR("X X X"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

// OLED - Render
void oled_task_user(void) {
  render_status();
}
