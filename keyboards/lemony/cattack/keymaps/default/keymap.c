#include QMK_KEYBOARD_H

enum layers {
  _DEFAULT,
  _LOWER,
  _NUM,
  _FN
};

#define LOWER MO(_LOWER)
#define NUM MO(_NUM)
#define FN MO(_FN)
#define SCRNCPY S(C(G(KC_4)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT_ortho_4x12(
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
        KC_LCTL, KC_LALT, KC_LGUI, FN     , NUM    , KC_SPC , KC_SPC , LOWER  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
    ),

    [_LOWER] = LAYOUT_ortho_4x12(
        KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , _______, _______, _______, _______, _______, KC_UNDS, KC_DEL ,
        _______, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______, _______, _______, KC_PIPE, KC_GRV ,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),

    [_NUM] = LAYOUT_ortho_4x12(
        _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, KC_7   , KC_8   , KC_9   , KC_MINS, _______,
        _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, KC_4   , KC_5   , KC_6   , KC_PLUS, KC_EQL ,
        _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, KC_1   , KC_2   , KC_3   , KC_SLSH, KC_EQL ,
        _______, _______, _______, _______, _______, _______, _______, KC_0   , KC_DOT , KC_DOT , KC_ASTR, KC_ENT 
    ),

    [_FN] = LAYOUT_ortho_4x12(
        RESET  , _______, _______, _______, _______,OUT_AUTO, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        _______, _______, _______, _______, _______, OUT_USB, _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______,
        _______, _______, _______, SCRNCPY, _______, OUT_BT , _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

