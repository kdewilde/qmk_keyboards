#include QMK_KEYBOARD_H

#include "kdewilde.h"

#define _QWERTY 0
#define _FN 1
#define _SPACEFN 2
#define _GAMING 3
#define _BLANK 4

#define SPCFN LT(_SPACEFN, KC_SPACE)
#define CTLESC CTL_T(KC_ESC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_HHKB_wrapper(
      KC_GRV,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
      KC_TAB,  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_LBRC, KC_RBRC, KC_BSPC,
      CTLESC,  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_QUOT,          KC_ENT,
      KC_LSFT, _________________QWERTY_L4_________________, _________________QWERTY_R4_________________,          KC_RSFT,          MO(_FN),
               KC_LGUI, KC_LALT,                     SPCFN,                                              KC_RALT, KC_RGUI
	),
    [_FN] = LAYOUT_HHKB_wrapper(      
      _______, ____________________FN_L1__________________, ____________________FN_R1__________________, _______, _______, _______, _______,
      _______, ____________________FN_L2__________________, ____________________FN_R2__________________, _______, _______, _______,
      KC_CAPS, ____________________FN_L3__________________, ____________________FN_R3__________________, _______,          _______,
      _______, ____________________FN_L4__________________, ____________________FN_R4__________________,          _______,          _______,
               _______, _______,                   _______,                                              _______, _______
    ),
    [_SPACEFN] = LAYOUT_HHKB_wrapper(
      _______, _________________SPACEFN_L1________________, _________________SPACEFN_R1________________, _______, _______, _______, _______,
      _______, _________________SPACEFN_L2________________, _________________SPACEFN_R2________________, _______, _______, _______,
      _______, _________________SPACEFN_L3________________, _________________SPACEFN_R3________________, _______,          _______,
      _______, _________________SPACEFN_L4________________, _________________SPACEFN_R4________________,          _______,          _______,
               _______, _______,                   _______,                                              _______, _______
    ),
    [_BLANK] = LAYOUT_HHKB_wrapper(
      _______, ___________________BLANK___________________, ___________________BLANK___________________, _______, _______, _______, _______,
      _______, ___________________BLANK___________________, ___________________BLANK___________________, _______, _______, _______,
      _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,          _______,
      _______, ___________________BLANK___________________, ___________________BLANK___________________,          _______,          _______,
               _______, _______,                   _______,                                              _______, _______
    )
};
