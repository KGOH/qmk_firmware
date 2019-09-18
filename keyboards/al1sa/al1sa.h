#ifndef AL1SA_H
#define AL1SA_H

#ifdef KEYBOARD_al1sa_rev1
  #include "rev1.h"
#endif

#define QWERTY_base  KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, \
                             KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
                             KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH


#define DVORAK_base  KC_GRV, KC_QUOT, KC_COMM, KC_DOT,KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_LBRC, KC_RBRC, \
                             KC_A,    KC_O,    KC_E,  KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH, \
                             KC_SCLN, KC_Q,    KC_J,  KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z
#define COLEMAK_base KC_GRV, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U,    KC_Y,   KC_SCLN, KC_LBRC, KC_RBRC, \
                             KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E,    KC_I,   KC_O,    KC_QUOT, \
                             KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH
#define WORKMAN_base KC_GRV, KC_Q, KC_D, KC_R, KC_W, KC_B, KC_J, KC_F, KC_U,    KC_P,   KC_SCLN, KC_LBRC, KC_RBRC, \
                             KC_A, KC_S, KC_H, KC_T, KC_G, KC_Y, KC_N, KC_E,    KC_O,   KC_I,    KC_QUOT, \
                             KC_Z, KC_X, KC_M, KC_C, KC_V, KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH

#endif // AL1SA_H
