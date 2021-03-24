#include QMK_KEYBOARD_H
// #include "oled.h"

enum layers {
  _DEFAULT,
  _NUMBER,
  _SYMBOL,
};

#define NUMBER TT(_NUMBER)
#define SYMBOL MO(_SYMBOL)

// Define Shortcut Keys
#define SCRNCPY S(C(G(KC_4))) // Mac - Screencap Select to Clipboard
#define VSTERML C(KC_TILD)    // Mac - VSCode - New Terminal

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_DEFAULT] = LAYOUT_twins(
		KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
		KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______,      _______, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT,
		KC_LGUI, KC_LALT, KC_LCTL, KC_1   , KC_2   , NUMBER , KC_SPC ,      SYMBOL , KC_MINS, KC_EQL , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
	),
	[_NUMBER] = LAYOUT_twins(
		_______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
		_______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
		_______, _______, _______, SCRNCPY, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______
	),
	[_SYMBOL] = LAYOUT_twins(
		KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL ,
		_______, _______, _______, KC_LCBR, KC_LBRC, KC_LPRN,                        KC_RPRN, KC_RBRC, KC_RCBR, _______, KC_PIPE, KC_GRV ,
		_______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, KC_BSLS, _______,
		_______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______
	),
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
	switch (get_highest_layer(layer_state)) {
		case _DEFAULT:
			if (index == 0) {
				(clockwise) ? tap_code(KC_DOWN) : tap_code(KC_UP);
			}
			if (index == 1) {
				(clockwise) ? tap_code(KC__VOLUP) : tap_code(KC__VOLDOWN);
			}
			break;

		case _SYMBOL:
			if (index == 0) {
				(clockwise) ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
			}
			break;
			// if (index == 1) {
			// 	(clockwise) ? tap_code(KC_DOWN) : tap_code(KC_UP);
			// }
		default:
			break;
	};
}
#endif