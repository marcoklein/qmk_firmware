#pragma once

#include QMK_KEYBOARD_H
// #include "muse.h"

enum preonic_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAME,
  _COLEMAK_EXP,
  _NAV,
  _NAV_RAISE
};

enum preonic_keycodes {
  GAME = SAFE_RANGE,
  COLEMAK,
  COL_EXP,
  L_NAV_R,
  LSPACE,
  RSPACE,
  MBSPC,
  MENTER,
  CAPS_WORD
};

#define ADJUST MO(_ADJUST)

// home row mods
#define MOD_A LGUI_T(KC_A)
#define MOD_R LALT_T(KC_R)
#define MOD_S LCTL_T(KC_S)
#define MOD_T LSFT_T(KC_T)

#define MOD_N RSFT_T(KC_N)
#define MOD_E RCTL_T(KC_E)
#define MOD_I LALT_T(KC_I)
#define MOD_O RGUI_T(KC_O)


bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);
void process_caps_word(uint16_t keycode, const keyrecord_t *record);