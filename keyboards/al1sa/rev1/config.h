/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#ifndef REV1_CONFIG_H
#define REV1_CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xC0DE
#define PRODUCT_ID      0x1337
#define DEVICE_VER      0x0001
#define MANUFACTURER    KgOfHedgehogs
#define PRODUCT         Al1sa
#define DESCRIPTION     Custom keyboard pcb with detachable numpad

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 18
#define MATRIX_COLS 10

// wiring of each half
#define MATRIX_ROW_PINS { B0, B1, B2, B3, B4, B5, D2, D3, D4 }
#define MATRIX_COL_PINS { D5, D6, D7, E6, F0, F1, F4, F5, F6, F7 }

/* Use I2C or Serial, not both */
// #define USE_SERIAL
#define USE_I2C

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

// different configs
#define PHYSICAL_LEDS_ENABLE
#define NUM_LOCK_LED_PIN C7
#define CAPS_LOCK_LED_PIN B7
#define SCROLL_LOCK_LED_PIN C6
#define NUM_LOCK_INVERT  //uncomment this if you using n-mosfet
#define CAPS_LOCK_INVERT  //uncomment this if you using n-mosfet
#define SCROLL_LOCK_INVERT  //uncomment this if you using n-mosfet

#ifdef NUM_LOCK_INVERT
#define SET_NUM_LOCK_LED() writePinHigh(NUM_LOCK_LED_PIN)
#define RESET_NUM_LOCK_LED() writePinLow(NUM_LOCK_LED_PIN)
#else
#define SET_NUM_LOCK_LED() writePinLow(NUM_LOCK_LED_PIN)
#define RESET_NUM_LOCK_LED() writePinHigh(NUM_LOCK_LED_PIN)
#endif // NUM_LOCK_INVERT

#ifdef CAPS_LOCK_INVERT
#define SET_CAPS_LOCK_LED() writePinHigh(CAPS_LOCK_LED_PIN)
#define RESET_CAPS_LOCK_LED() writePinLow(CAPS_LOCK_LED_PIN)
#else
#define SET_CAPS_LOCK_LED() writePinLow(CAPS_LOCK_LED_PIN)
#define RESET_CAPS_LOCK_LED() writePinHigh(CAPS_LOCK_LED_PIN)
#endif // CAPS_LOCK_INVERT

#ifdef SCROLL_LOCK_INVERT
#define SET_SCROLL_LOCK_LED() writePinHigh(SCROLL_LOCK_LED_PIN)
#define RESET_SCROLL_LOCK_LED() writePinLow(SCROLL_LOCK_LED_PIN)
#else
#define SET_SCROLL_LOCK_LED() writePinLow(SCROLL_LOCK_LED_PIN)
#define RESET_SCROLL_LOCK_LED() writePinHigh(SCROLL_LOCK_LED_PIN)
#endif // SCROLL_LOCK_INVERT

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PIN B6
#define BACKLIGHT_LEVELS 5
//#define BACKLIGHT_BREATHING //not working with splits right now
#define BREATHING_PERIOD 6
#endif

/* ws2812 RGB LED */
#define RGB_DI_PIN E2
#define RGBLIGHT_TIMER
#define RGBLED_NUM 7    // Number of LEDs
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 100
#define ws2812_PORTREG  PORTE
#define ws2812_DDRREG   DDRE
#define RGBLIGHT_SLEEP
#define RGBLIGHT_SPLIT

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
//
//#define QMK_ESC_OUTPUT D3 // usually COL
//#define QMK_ESC_INPUT F4 // usually ROW
//#define QMK_LED B0
//#define QMK_SPEAKER B6

#endif //REV1_CONFIG_H
