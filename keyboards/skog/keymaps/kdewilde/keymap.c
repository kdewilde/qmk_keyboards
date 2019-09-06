/*
Copyright 2018 Jumail Mundekkat / MxBlue

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
    [_QWERTY] = LAYOUT_WKL_wrapper(
      KC_ESC,  _________________QWERTY_L0_________________, _________________QWERTY_R0_________________, KC_F11,     KC_F12,                  KC_PSCR, TG(_GAMING), KC_PAUS,
      KC_GRV,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_MINS,    KC_EQL,     KC_BSPC,     KC_INS,  KC_HOME, KC_PGUP,
      KC_TAB,  _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, KC_LBRC,    KC_RBRC,    KC_BSLS,     KC_DEL,  KC_END,  KC_PGDN,
      CTLESC,  _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, KC_QUOT,            KC_ENT,
      KC_LSFT, _________________QWERTY_L4_________________, _________________QWERTY_R4_________________,             KC_RSFT,                                      KC_UP,
      KC_LCTL,          KC_LALT,                     SPCFN,                                              KC_RGUI,       LT(_FN, KC_RCTL),     KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FN] = LAYOUT_WKL_wrapper(
      _______, ____________________FN_L0__________________, ____________________FN_R0__________________, _______, _______,                    _______, KC_SLCK, _______,
      _______, ____________________FN_L1__________________, ____________________FN_R1__________________, _______, _______, _______,           KC_MPRV, KC_MNXT, KC_VOLU,
      _______, ____________________FN_L2__________________, ____________________FN_R2__________________, _______, _______, _______,           KC_MPLY, _______, KC_VOLD,
      KC_CAPS, ____________________FN_L3__________________, ____________________FN_R3__________________, _______,      _______,
      _______, ____________________FN_L4__________________, ____________________FN_R4__________________,             _______,                          _______,
      _______,          _______,                   _______,                                              _______,          _______,           _______, _______, _______
    ),
    [_SPACEFN] = LAYOUT_WKL_wrapper(
      _______, _________________SPACEFN_L0________________, _________________SPACEFN_R0________________, _______, _______,                    _______, _______, _______,
      _______, _________________SPACEFN_L1________________, _________________SPACEFN_R1________________, _______, _______, _______,           _______, _______, _______,
      _______, _________________SPACEFN_L2________________, _________________SPACEFN_R2________________, _______, _______, _______,           _______, _______, _______,
      _______, _________________SPACEFN_L3________________, _________________SPACEFN_R3________________, _______,       _______,
      _______, _________________SPACEFN_L4________________, _________________SPACEFN_R4________________,             _______,                          _______,
      _______,          _______,                   _______,                                              _______,          _______,           _______, _______, _______
    ),
    [_GAMING] = LAYOUT_WKL_wrapper(
      _______, _________________GAMING_L0_________________, _________________GAMING_R0_________________, _______, _______,                    _______, _______, _______,
      _______, _________________GAMING_L1_________________, _________________GAMING_R1_________________, _______, _______, _______,           _______, _______, _______,
      _______, _________________GAMING_L2_________________, _________________GAMING_R2_________________, _______, _______, _______,           _______, _______, _______,
      _______, _________________GAMING_L3_________________, _________________GAMING_R3_________________, _______,       _______,
      _______, _________________GAMING_L4_________________, _________________GAMING_R4_________________,             _______,                          _______,
      _______,          _______,                    KC_SPC,                                              _______,          _______,           _______, _______, _______
    ),
    [_BLANK] = LAYOUT_WKL_wrapper(
      _______, ___________________BLANK___________________, ___________________BLANK___________________, _______, _______,                    _______, _______, _______,
      _______, ___________________BLANK___________________, ___________________BLANK___________________, _______, _______, _______,           _______, _______, _______,
      _______, ___________________BLANK___________________, ___________________BLANK___________________, _______, _______, _______,           _______, _______, _______,
      _______, ___________________BLANK___________________, ___________________BLANK___________________, _______,       _______,
      _______, ___________________BLANK___________________, ___________________BLANK___________________,             _______,                          _______,
      _______,          _______,                   _______,                                              _______,          _______,           _______, _______, _______
    )
};

void matrix_init_user(void) {
    rgblight_enable();
    rgblight_sethsv(HSV_LB_CYAN);
}

void matrix_scan_user(void) {

}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _FN:
            rgblight_sethsv (HSV_LB_GOLDENROD);
            break;
        case _GAMING:
            rgblight_sethsv (HSV_LB_RED);
            break;
        default:
            rgblight_sethsv (HSV_LB_CYAN);
            break;
    }
    return state;
}
