#include QMK_KEYBOARD_H
#include "oled.h"

// Define Layer Names
enum layers {
  _DEFAULT,
  _SYMBOL,
  _NUMBER,
  _FN,
  _CUTS
};

// Define Layer Switching Keys
#define SYMBOL MO(_SYMBOL)
#define NUMBER TT(_NUMBER)
#define FN MO(_FN)
#define CUTS MO(_CUTS)
#define STD TG(_STANDARD)

// Define Shortcut Keys
#define SCRNCPY S(C(G(KC_4))) // Mac - Screencap Select to Clipboard
#define VSTERML C(KC_TILD)    // Mac - VSCode - New Terminal
#define VSCMDPT S(G(KC_P))    // Mac - VSCode - Show Palette
#define MCVOLUP KC__VOLUP
#define MCVOLDN KC__VOLDOWN

// Define Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT_ortho_50(
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,       KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,       KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT,
        KC_LGUI, KC_LALT, KC_LCTL, FN     , CUTS   , NUMBER ,       KC_MINS, KC_EQL , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,
                                                     KC_SPC ,       SYMBOL
    ),

    // [_SYMBOL] = LAYOUT_ortho_50(
    //     KC_TILD, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
    //     _______, _______, _______, KC_LCBR, KC_LBRC, KC_LPRN,       KC_RPRN, KC_RBRC, KC_RCBR, _______, KC_PIPE, KC_GRV ,
    //     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, KC_BSLS, _______,
    //     _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
    //                                                  _______,       _______
    // ),
    [_SYMBOL] = LAYOUT_ortho_50(
        KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL ,
        _______, _______, _______, KC_LCBR, KC_LBRC, KC_LPRN,       KC_RPRN, KC_RBRC, KC_RCBR, _______, KC_PIPE, KC_GRV ,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                                                     _______,       _______
    ),
    
    [_NUMBER] = LAYOUT_ortho_50(
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, _______, _______, _______, _______, _______,       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                                                     _______,       _______
    ),

    [_FN] = LAYOUT_ortho_50(
        RESET  , KC_F1  , _______, _______, _______, OUT_AUTO,      KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______, _______, _______, _______, _______, OUT_USB,       KC_F4  , KC_F5  , KC_F6  , _______, _______, _______,
        KC_ASTG, _______, _______, _______, _______, OUT_BT ,       KC_F1  , KC_F2  , KC_F3  , _______, _______, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, MCVOLDN, MCVOLUP, _______,
                                                     _______,       _______
    ),

    [_CUTS] = LAYOUT_ortho_50(
        _______, _______, _______, _______, _______, VSTERML,       _______, _______, _______, _______, VSCMDPT, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, SCRNCPY, _______, _______,       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                                                     _______,       _______
    ),
};

// OLED - Settings
#ifdef OLED_DRIVER_ENABLE

// OLED - Display the Layer
void render_status(void) {
    oled_set_cursor(0,14); // vertical offset to bottom
    oled_write_P(PSTR("+"), false);
    oled_set_cursor(0,15); // vertical offset to bottom
    oled_write_P(PSTR(">"), false);

    switch (get_highest_layer(layer_state)) {
        case _DEFAULT:  oled_write_P(PSTR("DFLT"), false);
            break;
        case _FN:       oled_write_P(PSTR("FUNC"), false);
            break;
        case _NUMBER:   oled_write_P(PSTR("NUMS"), false);
            break;
        case _SYMBOL:   oled_write_P(PSTR("SYMB"), false);
            break;
        case _CUTS:     oled_write_P(PSTR("CUTS"), false);
            break;
        default:        oled_write_P(PSTR("XXXX"), false);
    }
}

// OLED - Render
void oled_task_user(void) {
    render_oled();
    render_status();
}

#endif