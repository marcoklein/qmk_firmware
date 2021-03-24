#include QMK_KEYBOARD_H
#include "muse.h"

#include "keymap.h"

float colemak_sound[][2] = SONG(COLEMAK_SOUND);
float game_sound[][2] = SONG(GUITAR_SOUND);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV , KC_1  , KC_2   , KC_3   ,  KC_4  ,    KC_5 ,   KC_6 , KC_7   , KC_8    ,    KC_9 , KC_0    , KC_BSPC ,
  KC_TAB , KC_Q  , KC_W   , KC_F   ,  KC_P  ,    KC_B ,   KC_J , KC_L   , KC_U    ,    KC_Y , KC_SCLN , KC_DEL  ,
  KC_ESC , MOD_A , MOD_R  , MOD_S  ,  MOD_T ,    KC_G ,   KC_M , MOD_N  , MOD_E   , MOD_I   , MOD_O   , KC_QUOT ,
CAPS_WORD, KC_Z  , KC_X   , KC_C   ,  KC_D  ,    KC_V ,   KC_K , KC_H   , KC_COMM , KC_DOT  , KC_SLSH , XXXXXXX ,
  COL_EXP,KC_LCTL, KC_LALT, KC_LGUI, LSPACE , MBSPC   , MENTER , RSPACE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),

[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,  KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______,
  _______, _______, _______, _______, ADJUST,  _______, _______, ADJUST, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_MINS, KC_EQL,   KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, ADJUST, ADJUST, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______,  _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_COLEMAK_EXP] = LAYOUT_preonic_grid(
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,   KC_6 , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
  KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,   KC_J , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_DEL ,
  KC_ESC , MOD_A  , MOD_R  , MOD_S  , MOD_T  , KC_G   ,   KC_M , MOD_N  , MOD_E  , MOD_I  , MOD_O  , KC_QUOT,
  XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,   KC_K , KC_H   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
  GAME   , XXXXXXX, XXXXXXX, XXXXXXX, LSPACE , MBSPC  , MENTER , RSPACE , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

// [_NAV] = LAYOUT_preonic_grid(
//   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, KC_7   , KC_8   , KC_9   , _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, KC_4   , KC_5   , KC_6   , _______, _______,
//   _______, _______, _______, _______, _______, _______, _______, _______, KC_1   , KC_2   , KC_3   , _______, _______,
//   _______, _______, _______, _______, L_NAV_R, _______, _______, _______, KC_0   , _______, _______, _______, _______,
// ),

// no home row mods
[_GAME] = LAYOUT_preonic_grid(
  KC_GRV , KC_1  , KC_2   , KC_3   ,  KC_4  ,    KC_5 ,   KC_6 , KC_7   , KC_8    ,    KC_9 , KC_0    , KC_BSPC ,
  KC_TAB , KC_Q  , KC_W   , KC_F   ,  KC_P  ,    KC_B ,   KC_J , KC_L   , KC_U    ,    KC_Y , KC_SCLN , KC_DEL  ,
  KC_ESC , KC_A  , KC_R   , KC_S   ,  KC_T  ,    KC_G ,   KC_M , KC_N   , KC_E    , KC_I    , KC_O    , KC_QUOT ,
  KC_LSFT, KC_Z  , KC_X   , KC_C   ,  KC_D  ,    KC_V ,   KC_K , KC_H   , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
  COLEMAK,KC_LCTL, KC_LALT, KC_LGUI, LSPACE , KC_LSFT, KC_RSFT , KC_SPACE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
)

}; // keymap function end

// detect interrupts of dual function layer keys
bool layer_key_active = true;
uint8_t mods_on_layer_activation = 0;

// handle custom input
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  process_caps_word(keycode, record);

  if (record->event.pressed)
  {
    layer_key_active = false;
  }
  switch (keycode) {

    /* layer codes */
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(colemak_sound);
        #endif
        default_layer_set(1U << _COLEMAK);
      }
      return false;
    case COL_EXP:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(game_sound);
        #endif
        default_layer_set(1U << _COLEMAK_EXP);
      }
      return false;
    case GAME:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(game_sound);
        #endif
        default_layer_set(1U << _GAME);
      }
      return false;

    /* custom key codes */

    case LSPACE:
    case RSPACE:
      if (record->event.pressed) {
        layer_key_active = true;
        mods_on_layer_activation = get_mods();
        layer_on(_RAISE);
      } else if (!record->event.pressed) {
        if (layer_key_active) {
          // send key only if no other key has been pressed while holding down this key
          tap_code(KC_SPACE);
        }
        layer_off(_RAISE);
      }
      return false;

    case MBSPC:
      if (record->event.pressed) {
        layer_key_active = true;
        mods_on_layer_activation = get_mods();
        layer_on(_LOWER);
      } else if (!record->event.pressed) {
        if (layer_key_active)
          tap_code(KC_BSPACE);
        layer_off(_LOWER);
      }
      return false;

    case MENTER:
      if (record->event.pressed) {
        layer_key_active = true;
        mods_on_layer_activation = get_mods();
        layer_on(_LOWER);
      } else if (!record->event.pressed) {
        if (layer_key_active)
          tap_code(KC_ENTER);
        layer_off(_LOWER);
      }
      return false;

    case CAPS_WORD:
      if (record->event.pressed) {
        caps_word_enable();
      }
      return false;

  }
  return true; // process key by qmk
};

// Enables the capitalization of complete words

void caps_word_enable(void) {
  caps_word_on = true;
  if (!(host_keyboard_led_state().caps_lock)) {
    tap_code(KC_CAPS);
  }
}

void caps_word_disable(void) {
  caps_word_on = false;
  if (host_keyboard_led_state().caps_lock) {
    tap_code(KC_CAPS);
  }
}

void process_caps_word(uint16_t keycode, const keyrecord_t *record) {
  if (caps_word_on) {
    switch (keycode) {
      case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        // no tap yet
        if (record->tap.count == 0) {
          return;
        }
        // base keycode of layer tap
        keycode = keycode & 0xFF;
        break;
      default:
        break;
    }

    switch (keycode) {
      // shifted keys
      case KC_A ... KC_Z:
        if (record->event.pressed) {
          caps_word_enable();
        }
      // keys that should not get shifted
      case KC_MINS:
      case KC_BSPC:
      case KC_UNDS:
      case CAPS_WORD:
        if (record->event.pressed && (get_mods() != MOD_LSFT) && (get_mods() != 0)) {
          // chording mods disables word caps
          caps_word_disable();
        }
        break;
      default:
        if (record->event.pressed) {
          caps_word_disable();
        }
        break;
    }
  }
}