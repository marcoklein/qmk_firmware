#include QMK_KEYBOARD_H

#include "keymap.h"
#include "oled.h"
#include "caps_word.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,   GUI_A,   ALT_R,   CTL_S,   SFT_T,    KC_G,                         KC_M,   SFT_N,   CTL_E,   ALT_I,   GUI_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    CAPS_WORD,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  LSPACE,   MBSPC,     MENTER,  RSPACE, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_BSLS, KC_MINS,  KC_EQL, _______,                      KC_LBRC, KC_RBRC, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  ADJUST, _______,    _______,  ADJUST, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______,  ADJUST,    ADJUST,  _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

// detect interrupts of dual function layer keys
bool layer_key_active = true;

// handle custom input
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  #ifdef OLED_DRIVER_ENABLE
  oled_process_record_user(keycode, record);
  #endif

  caps_word_process_record_user(keycode, record);

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
        layer_on(_RAISE);
      } else {
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
        layer_on(_LOWER);
      } else {
        if (layer_key_active)
          tap_code(KC_BSPACE);
        layer_off(_LOWER);
      }
      return false;

    case MENTER:
      if (record->event.pressed) {
        layer_key_active = true;
        layer_on(_LOWER);
      } else {
        if (layer_key_active)
          tap_code(KC_ENTER);
        layer_off(_LOWER);
      }
      return false;

    // case CAPS_WORD:
    //   if (record->event.pressed) {
    //     caps_word_enable();
    //   }
    //   return false;

  }
  return true; // process key by qmk
};

