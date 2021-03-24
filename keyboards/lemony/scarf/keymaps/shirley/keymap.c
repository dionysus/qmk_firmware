#include QMK_KEYBOARD_H

enum layers {
  _DEFAULT,
  _FN,
};

#define FN MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT_ortho_50(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_QUOT,
        KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
        KC_LCTL, KC_LALT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_SPC , FN     , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH
    ),

    [_FN] = LAYOUT_ortho_50(
        KC_GRV , _______, _______, _______, _______, RESET  ,                   _______, _______, _______, KC_LBRC, KC_RBRC, KC_MINS,
        _______, _______, KC_UP  , _______, _______, _______,                   _______, S(KC_MINS), _______, _______, _______, KC_PPLS,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   _______, _______, _______, _______, KC_PIPE, KC_EQL ,
        KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_BSLS
    ),
};

#ifdef OLED_DRIVER_ENABLE

void render_dumbo(void) {
  static const char PROGMEM img_dumbo[] = { 

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0xc0, 0x60, 0x20, 0x00, 0xa0, 0x00, 0x00, 
    0xc0, 0x00, 0x20, 0xe0, 0x20, 0x00, 0x60, 0xc0, 0x40, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x34, 0x42, 0x31, 0x10, 0x88, 0x80, 0x80, 0x83, 0x98, 0xa0, 0x06, 0x00, 0x00, 
    0xea, 0x00, 0x00, 0x05, 0xa0, 0x94, 0x82, 0x81, 0x80, 0x80, 0x10, 0x31, 0x42, 0x34, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x0a, 0x10, 0x00, 0x84, 0x48, 0x09, 0x53, 0x03, 0x40, 0x80, 0x81, 0x50, 
    0x60, 0x50, 0x81, 0x80, 0x40, 0x03, 0x53, 0x09, 0x48, 0x84, 0x10, 0x20, 0x0a, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x02, 
    0x02, 0x02, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

    };
  oled_write_raw_P(img_dumbo, sizeof(img_dumbo));
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
    render_dumbo();
    render_status();
}

#endif