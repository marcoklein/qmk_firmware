#pragma once

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

/** Home Row Mods **/

// milliseconds to differentiate between tab and hold
#define TAPPING_TERM 200 // default 200

// prevent normal rollover of alphas from accedentally triggering mods
#define IGNORE_MOD_TAP_INTERRUPT

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// you may change this to a "TAPPING_FORCE_HOLD_PER_KEY" option
#define TAPPING_FORCE_HOLD

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif


#define BOOTMAGIC_KEY_SALT KC_TAB
#define BOOTMAGIC_KEY_EEPROM_CLEAR KC_C

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"