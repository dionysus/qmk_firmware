#include QMK_KEYBOARD_H

// Define Layer Names
enum layers {
  _DEFAULT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT_single(
        RESET
    ),
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) (clockwise) ? tap_code(KC_DOWN) : tap_code(KC_UP);
}
#endif