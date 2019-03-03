// Below layout is based upon /u/That-Canadian's planck layout
#include "6pack.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0

#define _FUNC 15

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,--------------------.
 * |   1  |  2   |  3   |  
 * |------+------+------|
 * |   4  |  5   | RESET| 
 * `--------------------'
 */
[_QWERTY] = LAYOUT( \
    KC_MEDIA_SELECT,    KC_MEDIA_STOP,    KC_AUDIO_MUTE, \
    KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,          LT(_FUNC, KC_MEDIA_PLAY_PAUSE) \
),

[_FUNC] = LAYOUT( \
    RESET,      _______,            _______, \
    _______,    KC_MEDIA_SELECT,    _______ \
),


};

void matrix_init_user(void) {
    
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            register_code(KC_AUDIO_VOL_UP);
            unregister_code(KC_AUDIO_VOL_UP);
        } else {
            register_code(KC_AUDIO_VOL_DOWN);
            unregister_code(KC_AUDIO_VOL_DOWN);
        }
    }
}