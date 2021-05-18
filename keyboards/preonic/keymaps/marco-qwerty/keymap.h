#pragma once

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _NAV,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
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
#define GUI_A LGUI_T(DE_A)
#define ALT_S LALT_T(DE_R)
#define CTL_D LCTL_T(DE_S)
#define SFT_F LSFT_T(DE_T)

#define SFT_J RSFT_T(DE_N)
#define CTL_K RCTL_T(DE_E)
#define ALT_L LALT_T(DE_I)
#define GUI_SCLN RGUI_T(DE_O)


bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);
void process_caps_word(uint16_t keycode, const keyrecord_t *record);