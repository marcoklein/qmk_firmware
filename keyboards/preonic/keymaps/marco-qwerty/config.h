#pragma once

/** Home Row Mods **/

// milliseconds to differentiate between tab and hold
#define TAPPING_TERM 200 // default 200

// prevent normal rollover of alphas from accedentally triggering mods
#define IGNORE_MOD_TAP_INTERRUPT

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// TODO change this to a "TAPPING_FORCE_HOLD_PER_KEY" option
#define TAPPING_FORCE_HOLD

/** Audio **/

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

#define MIDI_BASIC
