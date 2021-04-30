#include QMK_KEYBOARD_H

// SHORTCUTS
#define SCRNCPY S(C(G(KC_4))) // Mac - Screencap Select to Clipboard

// VS CODE
#define VS_CONT KC_F5
#define VS_STIN KC_F11
#define VS_STOV KC_F10
#define VS_STOT S(KC_F11)
#define VS_STOP S(KC_F5)

// MAC - RECTANGLE (window manager)
#define RECT_L C(A(KC_LEFT))
#define RECT_R C(A(KC_RIGHT))
#define RECT_U C(A(KC_UP))
#define RECT_D C(A(KC_DOWN))

#define RECT_UL C(A(KC_U))
#define RECT_UR C(A(KC_I))
#define RECT_LL C(A(KC_J))
#define RECT_LR C(A(KC_K))

#define RECT_3L C(A(KC_D))
#define RECT_3C C(A(KC_F))
#define RECT_3R C(A(KC_G))
#define RECT_3F C(A(KC_E))
#define RECT_3E C(A(KC_T))

// MAC - MISSION CONTROL
#define MISSION_CONTROL C(KC_UP)
#define MISSION_L C(KC_LEFT)
#define MISSION_R C(KC_RIGHT)
#define MISSION_APP C(KC_DOWN)
