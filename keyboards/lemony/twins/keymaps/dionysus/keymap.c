#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE
#include "oled.h"
#endif

enum layers {
  _DEFAULT,
  _WINDOWS,
  _NUMBER,
  _SYMBOL,
  _FN,
};

enum my_keycodes {
  ENC_L = SAFE_RANGE,   // Encoder Left push button
  ENC_R,                // Encoder Right push button
  TOG_OS,               // Toggle OS
  SC_SNIP,              // SC screen copy
};

int OS = 0; // 0 = mac, 1 = win

//! CUSTOM KEYPRESS ------------------------------------------------------------

  // LAYERS
  #define NUMBER TT(_NUMBER)
  #define SYMBOL MO(_SYMBOL)
  #define FN MO(_FN)
  #define MODSDEF TG(_WINDOWS) // unSwap CTRL + CMD
  // SHORTCUTS
  #define SCRNCPY S(C(G(KC_4))) // Mac - Screencap Select to Clipboard
  #define VSTERML C(KC_TILD)    // Mac - VSCode - New Terminal

//! KEYMAPS --------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DEFAULT] = LAYOUT_twins(
    KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , ENC_L  ,      ENC_R  , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT,
    KC_LGUI, KC_LALT, KC_LCTL, FN     , KC_DEL , NUMBER , KC_SPC ,      SYMBOL , KC_MINS, KC_EQL , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  ),
  [_WINDOWS] = LAYOUT_twins(
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______
  ),
  [_NUMBER] = LAYOUT_twins(
    _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
    _______, _______, _______, _______, _______, _______,                        _______, KC_4   , KC_5   , KC_6   , _______, _______,
    _______, _______, _______, SC_SNIP, _______, _______, _______,      _______, _______, KC_1   , KC_2   , KC_3   , _______, _______,
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, KC_0   , _______, _______, _______, _______
  ),
  [_SYMBOL] = LAYOUT_twins(
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL ,
    _______, _______, _______, KC_LCBR, KC_LBRC, KC_LPRN,                        KC_RPRN, KC_RBRC, KC_RCBR, _______, KC_PIPE, KC_GRV ,
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______
  ),
  [_FN] = LAYOUT_twins(
  	_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
  	_______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
  	_______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
  	TOG_OS , _______, MODSDEF, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, RGB_MOD
  ),
  // 	[BLANK] = LAYOUT_twins(
  // 	_______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
  // 	_______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
  // 	_______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
  // 	_______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______
  // ),
};




//! ENCODERS -------------------------------------------------------------------

#ifdef ENCODER_ENABLE

  // defining Encoder Layers
  int ENC_LAYER_L = 0;
  int ENC_LAYER_R = 0;
  int enc_layers_L = 4;
  int enc_layers_R = 3;

  // define shortcuts ----------------------------------------------------------

  void sc_tabs(bool clockwise) {
    // switch tabs (chrome, VS,...)
    if (OS == 0){ // MAC
      if (clockwise) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        tap_code(KC_RIGHT);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
      } else {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        tap_code(KC_LEFT);
        unregister_code(KC_LALT);
        unregister_code(KC_LGUI);
      }
    }
    else if (OS == 1){ // WIN
      if (clockwise) {
        register_code(KC_LCTL);
        tap_code(KC_PGDN);
        unregister_code(KC_LCTL);
      } else {
        register_code(KC_LCTL);
        tap_code(KC_PGUP);
        unregister_code(KC_LCTL);
      }
    }
  };

  void sc_zoom(bool clockwise) {
    // zoom in/out (photoshop, chrome,...)
    if (OS == 0){ // MAC
      if (clockwise) {
        register_code(KC_LGUI);
        tap_code(KC_EQL);
        unregister_code(KC_LGUI);
      } else {
        register_code(KC_LGUI);
        tap_code(KC_MINUS);
        unregister_code(KC_LGUI);
      }
    }
    else if (OS == 1){ // WIN
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
  }

  void sc_ps_brush(bool clockwise) {
    (clockwise) ? tap_code(KC_RBRC) : tap_code(KC_LBRC);
  }

  // defining Encoder actions (rotation) ---------------------------------------

  void encoder_update_user(uint8_t index, bool clockwise) {
    //! LEFT ENCODER
    if (index == 0) {
      switch (ENC_LAYER_L) {
        case 0: // UPDN
          if (index == 0) (clockwise) ? tap_code(KC_DOWN) : tap_code(KC_UP);
          break;
        case 1: // TABS
          sc_tabs(clockwise);
          break;
        case 2: // PAGE
          if (index == 0) (clockwise) ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
          break;
        case 3: // ZOOM IN/OUT
          sc_zoom(clockwise);
          break;
      }
    }
    
    //! RIGHT ENCODER
    if (index == 1) {
      switch (ENC_LAYER_R){
        case 0: // LEFT/RIGHT
          (clockwise) ? tap_code(KC_RIGHT) : tap_code(KC_LEFT);
          break;
        case 1: // VOLUME
          if (OS == 0){
            (clockwise) ? tap_code(KC__VOLUP) : tap_code(KC__VOLDOWN);
          }
          if (OS == 1){
            (clockwise) ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
          }
          break;
        case 2: // PS - BRUSH
          sc_ps_brush(clockwise);
          break;
      };
    }
  }

#endif

//! OLED -----------------------------------------------------------------------

#ifdef OLED_DRIVER_ENABLE

  void render_status(void) {
    // cursor (w:0-4, h:0-15)

    #ifdef ENCODER_ENABLE

      //! Encoder LEFT
      int start = 6;

      oled_set_cursor(0,start++); // vertical offset to bottom
      oled_write_P(PSTR("<"), false);
      switch (ENC_LAYER_L) {
        case 0:		oled_write_P(PSTR("UPDN"), false);
          break;
        case 1:		oled_write_P(PSTR("TABS"), false);
          break;
        case 2:		oled_write_P(PSTR("PAGE"), false);
          break;
        case 3:		oled_write_P(PSTR("ZOOM"), false);
          break;
        default:	oled_write_P(PSTR("XXXX"), false);
      }
      
      //! Encoder RIGHT
      oled_set_cursor(0,start++); // vertical offset to bottom
      oled_write_P(PSTR(">"), false);
      switch (ENC_LAYER_R) {
        case 0:		oled_write_P(PSTR("L/R "), false);
          break;
        case 1:		oled_write_P(PSTR("VOL "), false);
          break;
        case 2:		oled_write_P(PSTR("BRSH"), false);
          break;
        default:	oled_write_P(PSTR("XXXX"), false);
      }

    #endif

    //! LAYERS
    oled_set_cursor(0,start++); // vertical offset to bottom
    oled_write_P(PSTR("-"), false);
    switch (get_highest_layer(layer_state)) {
      case _DEFAULT:  oled_write_P(PSTR("MAC "), false);
        break;
      case _WINDOWS:   oled_write_P(PSTR("WIN "), false);
        break;
      case _NUMBER:   oled_write_P(PSTR("NUMS"), false);
        break;
      case _SYMBOL:   oled_write_P(PSTR("SYMB"), false);
        break;
      case _FN:       oled_write_P(PSTR("FUNC"), false);
        break;
      default:        oled_write_P(PSTR("XXXX"), false);
    }

  }

  oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
      return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
    }
    return rotation;
  }

  // OLED - Render
  void oled_task_user(void) {
    if (is_keyboard_master()) {
      // render_oled();
      render_status();
    }
  }
#endif

//! CUSTOM KEYPRESS ------------------------------------------------------------

void sc_snip (void) {
  // screen copy functions
  if (OS == 0){ // MAC
    // ⌘ + shift + ctrl + 4
    register_code(KC_LSFT);
    register_code(KC_LCTL);
    register_code(KC_LGUI);
    tap_code(KC_4);
    unregister_code(KC_LSFT);
    unregister_code(KC_LCTL);
    unregister_code(KC_LGUI);
  }
  else if (OS == 1){ // WIN
    // win + shift + s
    register_code(KC_LSFT);
    register_code(KC_LGUI);
    tap_code(KC_S);
    unregister_code(KC_LSFT);
    unregister_code(KC_LGUI);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // ENCODER BUTTON PRESS
    #ifdef ENCODER_ENABLE
    case ENC_L:
      if (record->event.pressed) {
        ENC_LAYER_L = (ENC_LAYER_L + 1) % enc_layers_L;
      }
      break;
    case ENC_R:
      if (record->event.pressed) {
        ENC_LAYER_R = (ENC_LAYER_R + 1) % enc_layers_R;
      }
      break;
    #endif

    // CUSTOM KEY
    case TOG_OS:
      if (record->event.pressed) {
        OS = (OS + 1) % 2; // toggle between OS
        if (OS == 1){
          layer_on(_WINDOWS);
        } else if ( OS == 0) {
          layer_off(_WINDOWS);
        }
      }
      break;

    case SC_SNIP:
      if (record->event.pressed) sc_snip();
      break;
  }
  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
  while (rgblight_get_val() >= 60) {
    rgblight_decrease_val_noeeprom();
  }
  // rgblight_sethsv_noeeprom(0, 0, 60);
}