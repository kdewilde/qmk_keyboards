#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _SPACEFN 4
#define _ENTERFN 5
#define _NUMPADFN 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  SPACEFN,
  ENTERFN,
  NUMPADFN,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Brite|Enter |Lower |Raise |Space | Left | Down |  Up  |Right 
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,                  KC_Q,    KC_W,    KC_E,    KC_R,            KC_T,    KC_Y,    KC_U,                     KC_I,    KC_O,    KC_P,    KC_BSPC, \
  LT(_NUMPADFN, KC_ESC),   KC_A,    KC_S,    KC_D,    KC_F,            KC_G,    KC_H,    KC_J,                     KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,            KC_B,    KC_N,    KC_M,                     KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTL,                 KC_LGUI, KC_LALT, KC_LALT, CTL_T(KC_ENT),   LOWER,   RAISE,   LT(_SPACEFN, KC_SPACE),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   {  |   }  |   &  |   *  |   %  |   ^  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |   (  |   )  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |   [  |   ]  |ISO ~ |ISO | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_LBRC, KC_RBRC, KC_AMPR,    KC_ASTR,    KC_PERC, KC_CIRC, KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_LPRN, KC_RPRN, KC_MINS,    KC_PLUS,    KC_EQL,  KC_UNDS, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LCBR, KC_RCBR, S(KC_NUHS), S(KC_NUBS), _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_PLUS,  KC_EQL, KC_UNDS, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |Qwerty| Swap |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = KEYMAP( \
  _______, RESET,   _______, _______,    _______,            _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, _______,    _______,            _______, _______, _______, _______, _______, _______, _______, \
  _______, RGB_TOG, RGB_MOD, RGB_HUI,    RGB_HUD,            RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, \
  _______, _______, _______, LGUI(KC_L), LALT(LCTL(KC_DEL)), _______, _______, M(0),    M(1),    _______, _______, _______ \
),

/* SpaceFn
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |Insert| Home |  Up  |  End | Bksp |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  Del |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SPACEFN] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, KC_INSERT, KC_HOME, KC_UP,   KC_END,  KC_BSPC, _______, \
  _______, _______, _______, _______, _______, _______, _______,   KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,   KC_DEL,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______ \
),

[_ENTERFN] = KEYMAP( \
  LALT(KC_TAB),  LCTL(KC_Q), LCTL(KC_W), _______,    LCTL(KC_R), LCTL(KC_T), _______, _______, _______, LCTL(KC_O),  _______, _______, \
  _______,       LCTL(KC_A), LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), LCTL(KC_G), _______, _______, _______, LCTL(KC_L),  _______, _______, \
  _______,       LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______,    _______, _______, _______, _______,     _______, _______, \
  _______,       _______,    _______,    _______,    _______,    _______,    _______, _______, _______, _______,     _______, _______ \
),

[_NUMPADFN] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______,  KC_7,  KC_8,    KC_9,    _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,  KC_4,  KC_5,    KC_6,    _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,  KC_1,  KC_2,    KC_3,    _______, _______, \
  _______, _______, _______, _______, KC_SPACE, _______, _______, KC_0,  _______, _______, _______, _______
)


};



void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 0:
      if (record->event.pressed) {
        return MACRO( I(60), T(T), T(E), T(S), T(T), T(6), T(7), T(6), T(7), T(EQL), T(ENT), END  );
      }
      break;
    case 1:
      if (record->event.pressed) {
        return MACRO( I(60), T(E), T(R), T(X), T(F), T(I), T(TAB), T(T), T(E), T(S), T(T), T(6), T(7), T(6), T(7), T(EQL), T(ENT),  END  );
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}