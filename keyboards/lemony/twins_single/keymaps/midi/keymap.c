#include QMK_KEYBOARD_H

enum layers {
  _DEFAULT,
};

//! KEYMAPS --------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT] = LAYOUT_twins_single(
  MI_C_2 , MI_Cs_2, MI_D_2 , MI_Ds_2, _______, MI_OCTU,
  MI_Gs_1, MI_A_1 , MI_As_1, MI_B_1 , _______, MI_OCTD,
  MI_E_1 , MI_F_1 , MI_Fs_1, MI_G_1 , _______, _______, _______,
  MI_C_1 , MI_Cs_1, MI_D_1 , MI_Ds_1, _______, MI_SUS, _______
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
      oled_write_P(PSTR("MIDI"), false);
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

