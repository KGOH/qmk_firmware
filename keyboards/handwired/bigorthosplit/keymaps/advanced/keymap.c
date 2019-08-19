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
  _ISO,
  _LOWER,
  _RAISE,
  _ADJUST,
  _BCKLT_ADJ,
  _THUMB_ALT,
#ifdef TRAINING_HALFES_LOCK
  _LEFT,
  _RIGHT,
#endif //TRAINING_HALFES_LOCK
#ifdef DIPS_ENABLE
  _DIPS,
#endif // DIPS_ENABLE
#ifdef STENO_ENABLE
  _PLOVER
#endif // STENO_ENABLE
};

enum bigorthosplit_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  EXT_PLV,
  EXT_RGB,
#ifdef DIPS_ENABLE
  LAYOUT0,
  LAYOUT1,
  LAYOUT2,
  LAYOUT3,
  DIP_ISO,
  FLIP_TH,
  DIP6,
  DIP7,
  DIP8,
  DIP9,
  DIP10,
  DIP11,
#endif // DIPS_ENABLE
};

#ifdef TRAINING_HALFES_LOCK
static uint8_t lock_timeout = 1;
static uint8_t lock_cooldown = 0;
#endif //TRAINING_HALFES_LOCK
#ifdef DIPS_ENABLE
#ifdef ALT_LAYOUTS_ENABLE
static uint8_t layout_conversion_dip_state = 0;
#endif // ALT_LAYOUTS_ENABLE
#endif // DIPS_ENABLE

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define TG_ISO  TG(_ISO)
#define TG_THMB TG(_THUMB_ALT)
#define BL_ADJ  TG(_BCKLT_ADJ)
#define TG_LWR  TG(_LOWER)
#define TG_RSE  TG(_RAISE)

#define RBR_RGU MT(MOD_RGUI, KC_RBRC)
#define F12_RGU MT(MOD_RGUI, KC_F12)
#define EQL_LCT MT(MOD_LCTL, KC_EQL)
#define APP_LCT MT(MOD_LCTL, KC_APP)
#define EQL_RCT MT(MOD_RCTL, KC_EQL)
#define QUO_RCT MT(MOD_RCTL, KC_QUOT)
#define APP_RCT MT(MOD_RCTL, KC_APP)
#define MIN_RCT MT(MOD_RCTL, KC_MINS)
#define PLS_LAL MT(MOD_LALT, KC_PPLS)
#define BSL_RAL MT(MOD_RALT, KC_BSLS)

#define NBS_LCT MT(MOD_LCTL, KC_NUBS)
#define BSH_LAL MT(MOD_LALT, KC_BSLS)
#define APP_RAL MT(MOD_RALT, KC_APP)

#define BSP_LSH MT(MOD_LSFT, KC_BSPC)
#define BSP_RSH MT(MOD_RSFT, KC_BSPC)
#define SPC_LSH MT(MOD_LSFT, KC_SPC)
#define SPC_RSH MT(MOD_RSFT, KC_SPC)
#define DEL_RSE LT(_RAISE, KC_DEL)
#define TAB_RSE LT(_RAISE, KC_TAB)
#define ENT_LWR LT(_LOWER, KC_ENT)
#define ESC_LWR LT(_LOWER, KC_ESC)

#define RGU_RBR RGUI_T(KC_RBRC)
#define RCT_QUO RCTL_T(KC_QUOT)

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

#ifdef DIPS_ENABLE
[_DIPS] = LAYOUT_DIPS(\
  LAYOUT0, LAYOUT1, LAYOUT2, LAYOUT3, DIP_ISO, FLIP_TH, \
  LAYOUT0, LAYOUT1, LAYOUT2, LAYOUT3, DIP_ISO, FLIP_TH \
),
#endif // DIPS_ENABLE

[_LOWER] = LAYOUT(\
  _______, KC_UNDS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  F12_RGU, \
           EQL_LCT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MIN_RCT, \
           PLS_LAL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
                                      _______, _______, _______,      _______,  _______, _______\
),

[_RAISE] = LAYOUT(\
  _______, KC_NLCK, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,      KC_VOLU, KC_HOME, KC_PSCR, KC_PGUP, KC_SLCK, KC_CAPS, _______, \
           EQL_LCT, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      KC_MUTE, KC_LEFT, KC_UP,   KC_RGHT, KC_INS,  APP_RCT, \
           _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PCMM,      KC_VOLD, KC_END,  KC_DOWN, KC_PGDN, KC_PAUS, _______, \
                                      _______, _______, _______,      _______, _______, _______\
),

[_ADJUST] = SYMM_LAYOUT(\
  RESET,   DEBUG,   KC_ASUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
           KC_ASRP, KC_ASTG, XXXXXXX, XXXXXXX, QWERTY,  PLOVER,  \
           BL_ADJ,  KC_ASDN, XXXXXXX, XXXXXXX, TG_ISO,  TG_THMB, \
                                      _______, SH_TG,   _______  \
),
#if defined(RGBLIGHT) | defined(BACKLIGHT_ENABLE)
[_BCKLT_ADJ] = SYMM_LAYOUT(\
  XXXXXXX, XXXXXXX, XXXXXXX, BL_INC,  RGB_VAI, RGB_HUD, RGB_HUI, \
           XXXXXXX, XXXXXXX, BL_DEC,  RGB_VAD, RGB_SAD, RGB_SAI, \
           BL_ADJ,  BL_BRTG, BL_TOGG, RGB_TOG, RGB_RMOD,RGB_MOD, \
                                      _______, _______, _______  \
),
#endif // defined(RGBLIGHT) | defined(BACKLIGHT_ENABLE)
#ifdef TRAINING_HALFES_LOCK
[_LEFT] = LAYOUT_base(\
  _______, _______, _______, _______, _______, _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
           _______, _______, _______, _______, _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
           _______, _______, _______, _______, _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
),

[_RIGHT] = LAYOUT_base(\
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______, _______, _______, _______, _______, _______, _______, \
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______, _______, _______, _______, _______, _______, \
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______, _______, _______, _______, _______ \
),
#endif // TRAINING_HALFES_LOCK

#ifdef STENO_ENABLE
[_PLOVER] = LAYOUT(
  EXT_PLV, STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,       STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,  EXT_PLV, \
           STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,      STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR, \
           XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,      STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR, \
                                      XXXXXXX, STN_A,   STN_O,        STN_E,   STN_U,   XXXXXXX\
),
#endif // STENO_ENABLE

[_THUMB_ALT] = LAYOUT(\
  _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, \
           _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
           _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
                                      DEL_RSE, BSP_LSH, ESC_LWR,      ENT_LWR, SPC_RSH, TAB_RSE \
),

[_ISO] = LAYOUT(\
  _______, _______,         _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, \
           LCTL_T(KC_NUBS), _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, \
           LALT_T(KC_NUHS), _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, KC_RALT, \
                                              _______, _______, _______,      _______, _______, _______\
),

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

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef DIPS_ENABLE
#ifdef ALT_LAYOUTS_ENABLE
void layout_convert(uint8_t statuses) {
  switch (0b1111 & statuses) {
    case 0b0000:
      set_single_persistent_default_layer(_QWERTY);
      break;
    case 0b0001:
      set_single_persistent_default_layer(_DVORAK);
      break;
    case 0b0010:
      set_single_persistent_default_layer(_COLEMAK);
      break;
    case 0b0011:
      set_single_persistent_default_layer(_WORKMAN);
      break;
    case 0b0100:
      set_single_persistent_default_layer(_DVK2QWE);
      break;
    case 0b0101:
      set_single_persistent_default_layer(_QWERTY);
      break;
    case 0b0110:
      set_single_persistent_default_layer(_DVK2CMK);
      break;
    case 0b0111:
      set_single_persistent_default_layer(_DVK2WMN);
      break;
    case 0b1000:
      set_single_persistent_default_layer(_CMK2QWE);
      break;
    case 0b1001:
      set_single_persistent_default_layer(_CMK2DVK);
      break;
    case 0b1010:
      set_single_persistent_default_layer(_QWERTY);
      break;
    case 0b1011:
      set_single_persistent_default_layer(_CMK2WMN);
      break;
    case 0b1100:
      set_single_persistent_default_layer(_WMN2QWE);
      break;
    case 0b1101:
      set_single_persistent_default_layer(_WMN2DVK);
      break;
    case 0b1110:
      set_single_persistent_default_layer(_WMN2CMK);
      break;
    case 0b1111:
      set_single_persistent_default_layer(_QWERTY);
      break;
   }
}
#endif // ALT_LAYOUTS_ENABLE
#endif // DIPS_ENABLE

void matrix_init_user(void) {
#ifdef DIPS_ENABLE
  layer_on(_DIPS);
#endif // DIPS_ENABLE
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef TRAINING_HALFES_LOCK
  if (!record->event.pressed) {
      lock_cooldown = --lock_cooldown < 0 ? 0 : lock_cooldown;
  }
  if (lock_cooldown == 0) {
      layer_off(_LEFT);
      layer_off(_RIGHT);
  }
#endif // TRAINING_HALFES_LOCK
  switch (keycode) {
#ifdef TRAINING_HALFES_LOCK
    case SPC_RSH:
    case BSP_RSH:
    case DEL_RSE:
    case ESC_LWR:
    case BSL_RAL:
    case RGU_RBR:
    case RCT_QUO:
    if (record->event.pressed) {
        layer_on(_LEFT);
        lock_cooldown = lock_timeout;
    }
    else {
        lock_cooldown = 0;
        layer_off(_LEFT);
    }
    break;
    case BSP_LSH:
    case SPC_LSH:
    case TAB_RSE:
    case ENT_LWR:
    case KC_LCTL:
    case KC_LGUI:
    case KC_LALT:
    if (record->event.pressed) {
        layer_on(_RIGHT);
        lock_cooldown = lock_timeout;
    }
    else {
        lock_cooldown = 0;
        layer_off(_RIGHT);
    }
    break;
#endif // TRAINING_HALFES_LOCK
#ifdef STENO_ENABLE
    case PLOVER:
      if (!record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
      }
      return false;
      break;
#endif // STENO_ENABLE
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
#ifdef DIPS_ENABLE
#ifdef ALT_LAYOUTS_ENABLE
    case LAYOUT0:
      if (record->event.pressed) {
        layout_conversion_dip_state |= 1 << 0;
      } else {
        layout_conversion_dip_state &= ~(1 << 0);
      }
      layout_convert(layout_conversion_dip_state);
      return false;
      break;
    case LAYOUT1:
      if (record->event.pressed) {
        layout_conversion_dip_state |= 1 << 1;
      } else {
        layout_conversion_dip_state &= ~(1 << 1);
      }
      layout_convert(layout_conversion_dip_state);
      return false;
      break;
    case LAYOUT2:
      if (record->event.pressed) {
        layout_conversion_dip_state |= 1 << 2;
      } else {
        layout_conversion_dip_state &= ~(1 << 2);
      }
      layout_convert(layout_conversion_dip_state);
      return false;
      break;
    case LAYOUT3:
      if (record->event.pressed) {
        layout_conversion_dip_state |= 1 << 3;
      } else {
        layout_conversion_dip_state &= ~(1 << 3);
      }
      layout_convert(layout_conversion_dip_state);
      return false;
      break;
#endif // ALT_LAYOUTS_ENABLE
    case DIP_ISO:
      if (record->event.pressed) {
          layer_on(_ISO);
      } else {
          layer_off(_ISO);
      }
      return false;
      break;
    case FLIP_TH:
      if (record->event.pressed) {
          layer_on(_THUMB_ALT);
      } else {
          layer_off(_THUMB_ALT);
      }
      return false;
      break;
#endif // DIPS_ENABLE
  }
  return true;
}
