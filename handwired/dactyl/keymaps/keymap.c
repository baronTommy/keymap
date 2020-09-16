#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0
#define XXXXXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_dactyl(  // layer 0 : default
    // Left Hand
    XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,
    XXXXXXXXXX,  KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,
    KC_SPACE,    KC_A,        KC_S,        KC_D,        KC_F,        KC_G,
    KC_ESCAPE,   KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,
    XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  KC_LCTRL,    KC_LALT,

                 RESET,       XXXXXXXXXX,
                 XXXXXXXXXX,
    KC_LSFT,     KC_LGUI,     XXXXXXXXXX,

    // Right Hand
    XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,  XXXXXXXXXX,
    KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        XXXXXXXXXX,
    KC_H,        KC_J,        KC_K,        KC_L,        KC_0,        KC_BSPACE,
    KC_N,        KC_M,        KC_UP,       KC_TAB,      KC_DEL,      KC_ENTER,
    KC_LEFT,     KC_DOWN,     KC_RIGHT,    XXXXXXXXXX, XXXXXXXXXX,

    XXXXXXXXXX, XXXXXXXXXX,
    XXXXXXXXXX,
    XXXXXXXXXX, KC_LALT,    KC_LCTRL
    ),
};
