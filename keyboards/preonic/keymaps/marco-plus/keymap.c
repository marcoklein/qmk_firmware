/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

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
  BACKLIT = SAFE_RANGE,
  GAME,
  COLEMAK,
  COL_EXP,
  L_NAV_R
};

#define LSPACE LT(_RAISE, KC_SPACE)
#define RSPACE LT(_RAISE, KC_SPACE)
#define MBSPC  LT(_LOWER, KC_BSPACE)
#define MENTER LT(_LOWER, KC_ENTER)

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

float colemak_sound[][2] = SONG(COLEMAK_SOUND);
float game_sound[][2] = SONG(GUITAR_SOUND);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * BK = Backspace
 * SP = Space
 * CR = Enter (Carriage Return)
 * 
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |GUI(A)|ALT(R)|CTL(S)|SFT(T)|   G  |   M  |SFT(N)|CTL(E)|ALT(I)|GUI(O)|  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GAME | Ctrl | Alt  | GUI  |LSPACE|MBSPC |MENTER|RSPACE| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_preonic_grid(
  KC_GRV , KC_1  , KC_2   , KC_3   ,  KC_4  ,    KC_5 ,   KC_6 , KC_7   , KC_8    ,    KC_9 , KC_0    , KC_BSPC ,
  KC_TAB , KC_Q  , KC_W   , KC_F   ,  KC_P  ,    KC_B ,   KC_J , KC_L   , KC_U    ,    KC_Y , KC_SCLN , KC_DEL  ,
  KC_ESC , MOD_A , MOD_R  , MOD_S  ,  MOD_T ,    KC_G ,   KC_M , MOD_N  , MOD_E   , MOD_I   , MOD_O   , KC_QUOT ,
  KC_LSFT, KC_Z  , KC_X   , KC_C   ,  KC_D  ,    KC_V ,   KC_K , KC_H   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
  COL_EXP,KC_LCTL, KC_LALT, KC_LGUI, LSPACE , MBSPC   , MENTER , RSPACE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |ADJUST|      |      |ADJUST| Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,  KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______,
  _______, _______, _______, _______, ADJUST,  _______, _______, ADJUST, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise (SPACE is raise)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |ADJUST|ADJUST|      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_MINS, KC_EQL,   KC_LBRC, KC_RBRC, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, ADJUST, ADJUST, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Backli| Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  BACKLIT, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
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

[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_7   , KC_8   , KC_9   , _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_4   , KC_5   , KC_6   , _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_1   , KC_2   , KC_3   , _______, _______,
  _______, _______, _______, _______, L_NAV_R, _______, _______, _______, KC_0   , _______, _______, _______, _______,
),

[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_7   , KC_8   , KC_9   , _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_4   , KC_5   , KC_6   , _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_1   , KC_2   , KC_3   , _______, _______,
  _______, _______, _______, _______, L_NAV_R, _______, _______, _______, KC_0   , _______, _______, _______, _______,
),

[_NAV_RAISE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_AMPR, KC_ASTR, KC_TILD, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_DLR , KC_PERC, KC_CIRC, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_EXLM, KC_AT  , KC_HASH, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_EXLM, _______, _______, _______, _______,
),

// [_NAV] = LAYOUT_preonic_grid(
//   _______,_______,_______,_______,_______,_______, _______, _______, _______, _______, _______, _______, _______,
//   _______,_______,_______,_______,_______,_______, _______, _______, _______, _______, _______, _______, _______,
//   _______,_______,_______,_______,_______,_______, _______, _______, _______, _______, _______, _______, _______,
//   _______,_______,_______,_______,_______,_______, _______, _______, _______, _______, _______, _______, _______,
//   _______,_______,_______,_______,_______,_______, _______, _______, _______, _______, _______, _______, _______,
// ),

/* Game
 * 
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |    R |    S |    T |   G  |   M  |    N |    E |    I |    O |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |COLMAK| Ctrl | Alt  | GUI  |LSPACE| Shift|Shift |RSPACE| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_preonic_grid(
  KC_GRV , KC_1  , KC_2   , KC_3   ,  KC_4  ,    KC_5 ,   KC_6 , KC_7   , KC_8    ,    KC_9 , KC_0    , KC_BSPC ,
  KC_TAB , KC_Q  , KC_W   , KC_F   ,  KC_P  ,    KC_B ,   KC_J , KC_L   , KC_U    ,    KC_Y , KC_SCLN , KC_DEL  ,
  KC_ESC , KC_A  , KC_R   , KC_S   ,  KC_T  ,    KC_G ,   KC_M , KC_N   , KC_E    , KC_I    , KC_O    , KC_QUOT ,
  KC_LSFT, KC_Z  , KC_X   , KC_C   ,  KC_D  ,    KC_V ,   KC_K , KC_H   , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
  COLEMAK,KC_LCTL, KC_LALT, KC_LGUI, LSPACE , KC_LSFT, KC_RSFT , KC_SPACE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
)

}; // keymap function end

/*
 * Handle custom key inputs like LOWER and RAISE.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
    case BACKLIT:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE

          // PLAY_SONG(SONG(COLEMAK_SOUND));
          //play_note(NOTE_C4, 1);
        #endif
        //register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef __AVR__
        writePinLow(E6);
        #endif
      } else {

        //unregister_code(KC_RSFT);
        #ifdef __AVR__
        writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
};
