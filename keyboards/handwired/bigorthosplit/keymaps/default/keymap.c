#include QMK_KEYBOARD_H
#include "action_layer.h"

#ifdef STENO_ENABLE
#include "keymap_steno.h"
#endif // STENO_ENABLE

extern keymap_config_t keymap_config;

enum bigorthosplit_layers {
  _QWERTY,
#ifdef ALT_LAYOUTS_ENABLE
  _DVORAK,
  _COLEMAK,
  _WORKMAN,
  _DVK2QWE,
  _DVK2CMK,
  _DVK2WMN,
  _CMK2QWE,
  _CMK2DVK,
  _CMK2WMN,
  _WMN2QWE,
  _WMN2DVK,
  _WMN2CMK,
#endif // ALT_LAYOUTS_ENABLE
  _LOWER,
  _ADJUST,
  _BCKLT_ADJ
};

enum bigorthosplit_keycodes {
  QWERTY = SAFE_RANGE,
  EXT_RGB
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LOWER MO(_LOWER)

#define LAYOUT_base( \
    GRV, Q, W, E, R, T, Y, U, I,    O,   P,    LBRC, RBRC, \
         A, S, D, F, G, H, J, K,    L,   SCLN, QUOT, \
         Z, X, C, V, B, N, M, COMM, DOT, SLSH \
  ) \
  LAYOUT( \
  KC_LGUI, GRV,     Q,       W,       E,       R,       T,            Y,       U,       I,       O,       P,       LBRC,    RGU_RBR, \
           KC_LCTL, A,       S,       D,       F,       G,            H,       J,       K,       L,       SCLN,    RCT_QUO, \
           KC_LALT, Z,       X,       C,       V,       B,            N,       M,       COMM,    DOT,     SLSH,    BSL_RAL, \
                                      TAB_RSE, SPC_LSH, ENT_LWR,      ESC_LWR, BSP_RSH, DEL_RSE \
  )
#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_base_wrapper(QWERTY_base),


[_LOWER] = LAYOUT(\
  _______, KC_UNDS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  F12_RGU, \
           EQL_LCT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MIN_RCT, \
           PLS_LAL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
                                      _______, _______, _______,      _______,  _______, _______\
),


[_ADJUST] = LAYOUT(\
  _______, KC_UNDS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  F12_RGU, \
  EQL_LCT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MIN_RCT, \
  PLS_LAL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, _______, _______,      _______,  _______, _______\
),
#if defined(RGBLIGHT) | defined(BACKLIGHT_ENABLE)
[_BCKLT_ADJ] = LAYOUT(\
  XXXXXXX, XXXXXXX, XXXXXXX, BL_INC,  RGB_VAI, RGB_HUD, RGB_HUI, \
           XXXXXXX, XXXXXXX, BL_DEC,  RGB_VAD, RGB_SAD, RGB_SAI, \
           BL_ADJ,  BL_BRTG, BL_TOGG, RGB_TOG, RGB_RMOD,RGB_MOD, \
                                      _______, _______, _______  \
),
#endif // defined(RGBLIGHT) | defined(BACKLIGHT_ENABLE)

#ifdef ALT_LAYOUTS_ENABLE
[_DVORAK] = LAYOUT_base_wrapper(DVORAK_base),
[_COLEMAK] = LAYOUT_base_wrapper(COLEMAK_base),
[_WORKMAN] = LAYOUT_base_wrapper(WORKMAN_base),
[_DVK2QWE] = LAYOUT_base_wrapper(DVK2QWE_base),
[_CMK2QWE] = LAYOUT_base_wrapper(CMK2QWE_base),
[_WMN2QWE] = LAYOUT_base_wrapper(WMN2QWE_base),
[_CMK2DVK] = LAYOUT_base_wrapper(CMK2DVK_base),
[_WMN2DVK] = LAYOUT_base_wrapper(WMN2DVK_base),
[_DVK2CMK] = LAYOUT_base_wrapper(DVK2CMK_base),
[_WMN2CMK] = LAYOUT_base_wrapper(WMN2CMK_base),
[_DVK2WMN] = LAYOUT_base_wrapper(DVK2WMN_base),
[_CMK2WMN] = LAYOUT_base_wrapper(CMK2WMN_base)
#endif // ALT_LAYOUTS_ENABLE
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
