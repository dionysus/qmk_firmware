#include QMK_KEYBOARD_H
#include "helpers.c"
#include "oled.c"

enum layers {
  _DEFAULT,
  _COPIER,
  _RECT,
  _MISSION,
  _DEBUG,
  _END
};
int CURR_LAYER = 0;
int NUM_LAYERS = _END - _DEFAULT;

enum my_keycodes {
  YT_TS_PASTE = SAFE_RANGE,
};

//! SHORTCUTS ------------------------------------------------------------------

// COPIER
#define COPY G(KC_C)
#define PASTE G(KC_V)
#define YT_COPY A(KC_T)

// RECT 
#define RECT_L C(A(KC_LEFT))
#define RECT_R C(A(KC_RIGHT)) 
#define RECT_U C(A(KC_UP)) 
#define RECT_D C(A(KC_DOWN)) 

// MISSION
#define MISSION_CONTROL C(KC_UP)
#define MISSION_L C(KC_LEFT)
#define MISSION_R C(KC_RIGHT)
#define MISSION_APP C(KC_DOWN)

// VS DEBUG
#define DEBUG_CONTINUE KC_F5
#define DEBUG_STEP_INTO KC_F11
#define DEBUG_STEP_OUT S(KC_F11)
#define DEBUG_STOP S(KC_F5)
// #define VS_DEBUG_STEP_OVER

//! LAYERS ---------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT_arrow(
        KC_UP ,
        KC_LEFT , KC_DOWN , KC_RIGHT  
    ),
    [_COPIER] = LAYOUT_arrow(
        COPY ,
        YT_COPY , PASTE , YT_TS_PASTE
    ),
    [_RECT] = LAYOUT_arrow(
        RECT_U   ,
        RECT_L   , RECT_D , RECT_R  
    ),
    [_MISSION] = LAYOUT_arrow(
        MISSION_CONTROL   ,
        MISSION_L   , MISSION_APP , MISSION_R  
    ),
    [_DEBUG] = LAYOUT_arrow(
      DEBUG_STEP_OUT,
      DEBUG_STOP, DEBUG_STEP_INTO, DEBUG_CONTINUE
    )
};

//! CUSTOM KEY SHORTCUTS ----------------------------------------------------------

// int pnum_100 = 0;
// int pnum_10 = 0;
// int pnum_1 = 0;
int pnum = 0;

void yt_timestamp(void) {
  // PASTE timecode
  register_code(KC_LGUI);
  tap_code(KC_V);
  unregister_code(KC_LGUI);
  tap_code(KC_SPC);
  if (pnum >= 0){
    register_code(KC_LSFT);
    tap_code(KC_P);
    unregister_code(KC_LSFT);
    tap_nums(pnum);
    tap_code(KC_SPC);
    tap_code(KC_MINUS);
    tap_code(KC_SPC);
    pnum++;
  } else {
    tap_code(KC_MINUS);
    tap_code(KC_SPC);
  }

}

//* SET CUSTOM KEY
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case YT_TS_PASTE:
      if (record->event.pressed) {
        yt_timestamp();
      }
      break;
  }
  return true;
}

//! ENCODER SHORTCUTS ----------------------------------------------------------

void rect_resizer(bool clockwise) {
  if (clockwise) {
    register_code(KC_LALT);
    register_code(KC_LCTL);
    tap_code(KC_EQUAL);
    unregister_code(KC_LCTL);
    unregister_code(KC_LALT);
  } else {
    register_code(KC_LALT);
    register_code(KC_LCTL);
    tap_code(KC_MINUS);
    unregister_code(KC_LCTL);
    unregister_code(KC_LALT);
  }
}

int corners = 0;
void rect_corners(bool clockwise) {
  if (clockwise) {
    corners = (corners + 1) % 4;
  } else {
    if (corners == 0) {
      corners = 4;
    } else {
      corners = (corners - 1) % 4;
    }
  }

  register_code(KC_LALT);
  register_code(KC_LCTL);
  switch (corners) {
    case 0: tap_code(KC_U); break;
    case 1: tap_code(KC_I); break;
    case 2: tap_code(KC_K); break;
    case 3: tap_code(KC_J); break;
  }
  unregister_code(KC_LCTL);
  unregister_code(KC_LALT);
}

int thirds = 0;
void rect_thirds(bool clockwise) {
  if (clockwise) {
    thirds = (thirds + 1) % 5;
  } else {
    if (thirds == 0) {
      thirds = 5;
    } else {
      thirds = (thirds - 1) % 5;
    }
  }

  register_code(KC_LALT);
  register_code(KC_LCTL);
  switch (thirds) {
    case 0: tap_code(KC_D); break;
    case 1: tap_code(KC_E); break;
    case 2: tap_code(KC_F); break;
    case 3: tap_code(KC_T); break;
    case 4: tap_code(KC_G); break;
  }
  unregister_code(KC_LCTL);
  unregister_code(KC_LALT);
}


//! ENCODER ACTIONS ------------------------------------------------------------

void encoder_update_user(uint8_t index, bool clockwise) {

  // 0 1 S
  // 2 X S
  // X X X
  //* SET AND APPLY CURRENT LAYER
  if (index == 1) {
    if (clockwise) {
      if (CURR_LAYER == _END - 1) {
        CURR_LAYER = _DEFAULT;
      } else {
        CURR_LAYER++;
      }
    } else {
      if (CURR_LAYER == _DEFAULT) {
        CURR_LAYER = _END - 1;
      } else {
        CURR_LAYER--;
      }
    }
    layer_move(CURR_LAYER);
  }

  if (CURR_LAYER == _COPIER) {
    // 0 1 *
    // 2 X *
    // X X X
    // if (index == 0) ;
    if (index == 2) {
      if (clockwise) {
        if (pnum < 999) pnum++;
      } else {
        if (pnum >= 0) pnum--;
      }
    }
  }

  if (CURR_LAYER == _RECT) {
    // 0 1 *
    // 2 X *
    // X X X
    if (index == 2) rect_thirds(clockwise);
    if (index == 0) rect_corners(clockwise);
  }

  if (CURR_LAYER == _DEBUG) {
    // 0 1 *
    // 2 X *
    // X X X
    if (index == 0) rect_corners(clockwise);
    if (index == 2) {
      if (clockwise) tap_code(KC_F10);
    }
  }
}

//! OLED -----------------------------------------------------------------------

void render_status(void) {
  // cursor (w:0-4, h:0-15)

  int start = 0;
  //! LAYERS 
  oled_set_cursor(0,start++); // vertical offset to bottom
  oled_write_P(PSTR(">"), false);
  switch (get_highest_layer(layer_state)) {
    case _DEFAULT:
      oled_write_P(PSTR("DEF "), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("-----"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("  ^  "), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("< V >"), false);
      break;
    case _COPIER:
      oled_write_P(PSTR("COPY"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("-----"), false);
      oled_write_P(PSTR("#"), false);
      display_nums(pnum);
      oled_write_P(PSTR("-----"), false);
      oled_write_P(PSTR("  C  "), false);
      oled_write_P(PSTR("Y P >"), false);
      break;
    case _RECT:
      oled_write_P(PSTR("RECT"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("-----"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("-CRNR"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("-THRD"), false);
      break;
    case _MISSION:
      oled_write_P(PSTR("MSSN"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("-----"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("  M  "), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("< A >"), false);
      break;
    case _DEBUG:
      oled_write_P(PSTR("DBUG"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("-----"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("-XXXX"), false);
      oled_set_cursor(0,start++);
      oled_write_P(PSTR("-OVER"), false);
      break;
    default:
      oled_write_P(PSTR("XXXX"), false);
  }

  // PRINT TEMPLATE
  // O O S
  // O X S
  // X X X
  start = 7;
  oled_set_cursor(0,start++);
  oled_write_P(PSTR("O O S"), false);
  oled_set_cursor(0,start++);
  oled_write_P(PSTR("O X S"), false);
  oled_set_cursor(0,start++);
  oled_write_P(PSTR("X X X"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

// OLED - Render
void oled_task_user(void) {
  render_status();
}
