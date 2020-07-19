/* Copyright 2019 KgOfHedgehogs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2
};

//// Defines the keycodes used by our macros in process_record_user
//enum custom_keycodes {
//    QWERTY = SAFE_RANGE
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_P7,   KC_P8,   KC_P9,
          KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,     KC_P4,   KC_P5,   KC_P6,
             KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  KC_UP,   KC_P1,   KC_P2,   KC_P3,
        KC_LCTL,  KC_LGUI,  KC_LALT,         KC_BSPC,        TT(_FN1),         KC_SPC,          KC_RALT,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT
    ),
    [_FN1] = LAYOUT(
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PLUS, S(KC_P7),S(KC_P8),S(KC_P9),
          RGB_MOD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,    KC_INS,     S(KC_P4),S(KC_P5),S(KC_P6),
             _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  S(KC_P1),S(KC_P2),S(KC_P3),
        _______,  _______,  _______,         KC_DEL,         _______,          TT(_FN2),        RESET,     KC_PSCR, KC_SLCK, KC_PAUS, KC_RGHT, S(KC_P0),S(KC_PDOT)
   ),
    [_FN2] = LAYOUT(
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PLUS, S(KC_P7),S(KC_P8),S(KC_P9),
          RGB_MOD,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,    KC_INS,     S(KC_P4),S(KC_P5),S(KC_P6),
             _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  S(KC_P1),S(KC_P2),S(KC_P3),
        _______,  _______,  _______,         KC_DEL,         _______,          _______,         RESET,     KC_PSCR, KC_SLCK, KC_PAUS, KC_RGHT, S(KC_P0),S(KC_PDOT)
   ),
};

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
*/
/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    //debug_mouse=true;
}
*/

static bool indicators = true;
static uint8_t R = 0x00;
static uint8_t G = 0x00;
static uint8_t B = 0x00;

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        indicators = false;
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case 2:
        indicators = false;
        rgblight_setrgb (0xFF,  0xFF, 0x00);
        break;
    case 3:
        indicators = false;
        rgblight_setrgb (0xFF,  0x00, 0xFF);
        break;
    default:
        indicators = true;
        rgblight_setrgb (R, G, B);
        break;
    }
    return state;
}

bool led_init_user(led_t led_state) {
    R = led_state.caps_lock ? 0xFF : 0x00;
    G = led_state.scroll_lock ? 0xFF : 0x00;
    B = led_state.num_lock ? 0xFF : 0x00;
    if (indicators) {
        rgblight_setrgb (R, G, B);
    }
    return true;
}

bool led_update_user(led_t led_state) {
    R = led_state.caps_lock ? 0xFF : 0x00;
    G = led_state.scroll_lock ? 0xFF : 0x00;
    B = led_state.num_lock ? 0xFF : 0x00;
    if (indicators) {
        rgblight_setrgb (R, G, B);
    }
    return true;
}
