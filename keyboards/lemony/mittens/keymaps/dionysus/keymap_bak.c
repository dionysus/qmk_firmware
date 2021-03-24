#include QMK_KEYBOARD_H
#include "oled.h"

enum layers {
  _DEFAULT,
  _SYM,
  _SYMBOL,
  _NUMB,
  _NUM,
  _FN,
  _CUTS,
  _MOV,
  _STANDARD,
  _SYMB
};

// Layer Switching
#define SYM MO(_SYM)
#define SYMB MO(_SYMB)
#define SYMBOL MO(_SYMBOL)
#define NUM MO(_NUM)
#define NUMB TT(_NUMB)
#define FN MO(_FN)
#define CUTS MO(_CUTS)
#define STD TG(_STANDARD)

// Shortcuts
#define SCRNCPY S(C(G(KC_4))) // Mac - Screencap Select to Clipboard
#define VSTERML C(KC_TILD)    // Mac - VSCode - New Terminal
#define VSCMDPT S(G(KC_P))    // Mac - VSCode - Show Palette
#define MCVOLUP KC__VOLUP
#define MCVOLDN KC__VOLDOWN

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT_ortho_50(
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,       KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,       KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT,
        KC_LCTL, KC_LALT, KC_LGUI, FN     , CUTS   , NUMB   ,       KC_MINS, KC_EQL , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,
                                                     KC_SPC ,       SYMBOL
    ),

    [_SYMBOL] = LAYOUT_ortho_50(
        KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL ,
        _______, _______, _______, KC_LCBR, KC_LBRC, KC_LPRN,       KC_RPRN, KC_RBRC, KC_RCBR, _______, KC_PIPE, KC_GRV ,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                                                     _______,       _______
    ),

    [_SYM] = LAYOUT_ortho_50(
        KC_TILD, _______, _______, _______, KC_LBRC, KC_RBRC,       KC_AMPR, KC_ASTR, _______, _______, _______, KC_DEL ,
        _______, _______, _______, _______, KC_LPRN, KC_RPRN,       KC_DLR , KC_PERC, KC_CIRC, _______, KC_PIPE, KC_GRV ,
        _______, _______, _______, _______, KC_LCBR, KC_RCBR,       KC_EXLM, KC_AT  , KC_HASH, _______, KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                                                     _______,       _______
    ),
    
    [_NUMB] = LAYOUT_ortho_50(
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                                                     _______,       _______
    ),
    
    [_NUM] = LAYOUT_ortho_50(
        _______, _______, KC_UP  , _______, _______, _______,       KC_7   , KC_8   , KC_9   , _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,       KC_4   , KC_5   , KC_6   , KC_COMM, _______, _______,
        _______, _______, _______, _______, _______, _______,       KC_1   , KC_2   , KC_3   , KC_DOT , _______, _______,
        _______, _______, _______, _______, _______, _______,       _______, _______, KC_0   , _______, _______, _______,
                                                     _______,       _______
    ),

    [_FN] = LAYOUT_ortho_50(
        RESET  , KC_F1  , _______, _______, _______, OUT_AUTO,      KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        _______, _______, _______, _______, _______, OUT_USB,       KC_F4  , KC_F5  , KC_F6  , _______, _______, _______,
        _______, _______, _______, _______, _______, OUT_BT ,       KC_F1  , KC_F2  , KC_F3  , _______, _______, _______,
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

    [_STANDARD] = LAYOUT_ortho_50(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,       KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LGUI, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,       _______, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
                                                     KC_SPC ,       SYMB
    ),

    [_SYMB] = LAYOUT_ortho_50(
        KC_GRV , _______, _______, _______, KC_LBRC, KC_RBRC,       _______, _______, _______, KC_MINS, KC_EQL , KC_DEL ,
        _______, _______, KC_UP  , _______, KC_LPRN, KC_RPRN,       _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCBR, KC_RCBR,       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        KC_LGUI, KC_LALT, KC_LCTL, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                                                     KC_ENT ,       _______
    ),
};

#ifdef OLED_DRIVER_ENABLE

void render_oled(void) {
    oled_write_raw_P(img_oled, sizeof(img_oled));
}


void render_status(void) {
    oled_set_cursor(0,14); // vertical offset to bottom
    oled_write_P(PSTR("+"), false);
    oled_set_cursor(0,15); // vertical offset to bottom
    oled_write_P(PSTR(">"), false);

    switch (get_highest_layer(layer_state)) {
        case _DEFAULT:
            oled_write_P(PSTR("DFLT"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FUNC"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("NUMS"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYMB"), false);
            break;
        case _CUTS:
            oled_write_P(PSTR("CUTS"), false);
            break;
        case _MOV:
            oled_write_P(PSTR("NAVI"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_P(PSTR("XXXX"), false);
    }

    // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    int cursor_y = 14;
    switch (keycode) {
        case KC_LSFT:
            if (record->event.pressed) {
                oled_set_cursor(1,cursor_y);
                oled_write_P(PSTR("S"), false);
            } else {
                oled_set_cursor(1,cursor_y);
                oled_write_P(PSTR(" "), false);
            }
            break;
        case KC_LCTL:
            if (record->event.pressed) {
                oled_set_cursor(2,cursor_y);
                oled_write_P(PSTR("C"), false);
            } else {
                oled_set_cursor(2,cursor_y);
                oled_write_P(PSTR(" "), false);
            }
            break;
        case KC_LALT:
            if (record->event.pressed) {
                oled_set_cursor(3,cursor_y);
                oled_write_P(PSTR("A"), false);
            } else {
                oled_set_cursor(3,cursor_y);
                oled_write_P(PSTR(" "), false);
            }
            break;
        case KC_LGUI:
            if (record->event.pressed) {
                oled_set_cursor(4,cursor_y);
                oled_write_P(PSTR("C"), false);
            } else {
                oled_set_cursor(4,cursor_y);
                oled_write_P(PSTR(" "), false);
            }
            break;
        default:
            return true; // Process all other keycodes normally
    }
    return true;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display -90 degrees
}

void oled_task_user(void) {
    render_oled();
    render_status();
}

#endif