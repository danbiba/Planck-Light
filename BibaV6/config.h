#pragma once

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_KEYPRESSES // reacts to keypresses (will slow down matrix scan by a lot)
// #define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (not recommened)
// #define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#define RGB_DISABLE_WHEN_USB_SUSPENDED false // turn off effects when suspended
// #define RGB_MATRIX_SKIP_FRAMES 1 // number of frames to skip when displaying animations (0 is full effect) if not defined defaults to 1
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
// #define EECONFIG_RGB_MATRIX (uint32_t *)16
#endif

#define RGBLIGHT_SLEEP

#ifdef AUDIO_ENABLE
     #define STARTUP_SONG SONG(IMPERIAL_MARCH)

    // plays song on mode change
     #define DEFAULT_LAYER_SONGS { SONG(VICTORY_FANFARE_SHORT), \
                                  SONG(ZELDA_PUZZLE), \
                                  SONG(MARIO_THEME) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
