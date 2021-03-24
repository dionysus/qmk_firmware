#include QMK_KEYBOARD_H

enum layers {
  _DEFAULT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT_arrow(
        KC_1   ,
        KC_2   , KC_3 , KC_4  
    ),
};

//! OLED -----------------------------------------------------------------------

#ifdef OLED_DRIVER_ENABLE

  void render_status(void) {
    // cursor (w:0-4, h:0-15)

    int start = 0;
    //! LAYERS 
    oled_set_cursor(0,start++); // vertical offset to bottom
    oled_write_P(PSTR("ZOM | ESC | ERS | DEL"), false);
    oled_set_cursor(0,start++);
    oled_write_P(PSTR("BRS | SFT | CPY | PST"), false);
    oled_set_cursor(0,start++);
    oled_write_P(PSTR("UND | CTL | ALT | SPC"), false);
    oled_set_cursor(0,start++); // vertical offset to bottom
    oled_write_P(PSTR("#"), false);
    switch (get_highest_layer(layer_state)) {
      case _DEFAULT:  oled_write_P(PSTR("PHOTOSHOP"), false);
        break;
      default:        oled_write_P(PSTR("XXXX"), false);
    }

  }

  oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
  }

  // OLED - Render
  void oled_task_user(void) {
    render_status();
  }
#endif


//! ENCODERS -------------------------------------------------------------------

#ifdef ENCODER_ENABLE

  // define shortcuts ----------------------------------------------------------

  void sc_unredo(bool clockwise) {
    // switch tabs (chrome, VS,...)
    if (clockwise) {
      register_code(KC_LSFT);
      register_code(KC_LCTL);
      tap_code(KC_Z);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
    } else {
      register_code(KC_LCTL);
      tap_code(KC_Z);
      unregister_code(KC_LCTL);
    }
  };

  void sc_zoom(bool clockwise) {
    // zoom in/out (photoshop, chrome,...)
    if (clockwise) {
      register_code(KC_LCTL);
      tap_code(KC_EQL);
      unregister_code(KC_LCTL);
    } else {
      register_code(KC_LCTL);
      tap_code(KC_MINUS);
      unregister_code(KC_LCTL);
    }
  }

  void sc_ps_brush(bool clockwise) {
    (clockwise) ? tap_code(KC_RBRC) : tap_code(KC_LBRC);
  }

  // defining Encoder actions (rotation) ---------------------------------------

  void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      sc_zoom(clockwise);
    }
    if (index == 1) {
      sc_ps_brush(clockwise);
    }
    if (index == 2) {
      sc_unredo(clockwise);
    }
  }

#endif