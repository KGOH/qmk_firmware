#include QMK_KEYBOARD_H
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum al1sa_layers {
  _QWERTY,
  _FN
};

enum al1sa_keycodes {
  QWERTY = SAFE_RANGE
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define FN_T(kc) LT(_FN, kc)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
 KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1 , \
 KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1 , \
 KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1 , \
 KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1 , \
 KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1 , \
 KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1 , \
 KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1 , \
 KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1 , \
 KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,        \
 KC_1, KC_1, KC_1, KC_1,                                      \
 KC_1, KC_1, KC_1, KC_1,                                      \
 KC_1, KC_1, KC_1,                                            \
 KC_1, KC_1, KC_1, KC_1,                                      \
 KC_1, KC_1                                                   \
),

[_FN] = LAYOUT(\
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , \
 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , \
 _______, _______, _______, _______, _______, _______, _______, _______, _______,           \
 _______, _______, _______, _______,                                                        \
 _______, _______, _______, _______,                                                        \
 _______, _______, _______,                                                                 \
 _______, _______, _______, _______,                                                        \
 _______, _______                                                                           \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

void keyboard_post_init_user (void) {
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
