#pragma once

#include QMK_KEYBOARD_H

#include "caps_word.h"

enum corne_layers {
  _COLEMAK,
  _SHIFT,
  _NAV,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAME,
  _COLEMAK_EXP
};

enum corne_keycodes {
  GAME = SAFE_RANGE,
  COLEMAK,
  COL_EXP,
  LSPACE,
  RSPACE,
  MBSPC,
  MENTER,
  CAPS_WORD
};

#define ADJUST MO(_ADJUST)

// home row mods

// _COLEMAK
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define CTL_S LCTL_T(KC_S)
#undef SFT_T
#define SFT_T LSFT_T(KC_T)

#define SFT_N RSFT_T(KC_N)
#define CTL_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

// _LOWER
#define GUI_TILD LGUI_T(KC_TILD)
#define ALT_BSLS LALT_T(KC_BSLS)
#define CTL_MINS LCTL_T(KC_MINS)
#define SFT_EQL LSFT_T(KC_EQL)

#define SFT_LBRC RSFT_T(KC_LBRC)
#define CTL_RBRC RCTL_T(KC_RBCR)
