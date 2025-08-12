#include QMK_KEYBOARD_H

enum layers {
    _DEFAULT,
};

//! KEYMAPS --------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // [0] = LAYOUT(KC_A, KC_B, KC_C, KC_D, KC_0, KC_1,
    //     KC_E, KC_F, KC_G, KC_H, KC_2, KC_3,
    //     KC_I, KC_J, KC_K, KC_L, KC_4, KC_5,
    //     KC_M, KC_N, KC_O, KC_P, KC_6, KC_7, KC_8),

    [0] = LAYOUT(MI_C1, MI_E1, MI_Gs1, MI_C2, MI_OCTD, MI_OCTU, MI_Cs1, MI_F1, MI_A1, MI_Cs2, KC_2, KC_3, MI_D1, MI_Fs1, MI_As1, MI_D2, KC_4, KC_5, MI_Ds1, MI_G1, MI_B1, MI_Ds2, KC_6, KC_7, KC_8),

    // [0] = LAYOUT(
    //   MI_C2, MI_Cs2, MI_D2, MI_Ds2, _______, _______,
    //   MI_Gs1, MI_A1, MI_As1, MI_B1, _______, _______,
    //   MI_E1, MI_F1, MI_Fs1, MI_G1, _______, _______,
    //   MI_C1, MI_Cs1, MI_D1, MI_Ds1, _______, _______, _______),

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