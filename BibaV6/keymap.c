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


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _FUNCTIO
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCTIO MO(_FUNCTIO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | GUI  | ALT  |Lower |Space |Space |Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_ENT ,
    FUNCTIO, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_SLSH, KC_LEFT, KC_DOWN,   KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   _  |ISO | |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | CAPS |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD,      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS,   KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_UNDS,   S(KC_NUBS), KC_LBRC, KC_RBRC, _______,
    _______,      KC_CAPSLOCK, _______, _______, _______, _______, _______, _______,   _______,    _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  | Vol+ |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   =  | Vol- | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,     KC_8,   KC_9,   KC_0,    KC_BSPC,
    _______,  _______, _______, _______, _______, _______, _______, KC_4,     KC_5,   KC_6,   KC_PLUS, KC_MINS,
    _______,      _______, _______, _______, _______, _______, _______, KC_1,     KC_2,   KC_3,   KC_VOLU, KC_ENT,
    _______,      _______, _______, _______, _______, _______, _______, _______,  KC_0,   KC_EQL, KC_VOLD, KC_MUTE
),
/* Functio
 * ,-----------------------------------------------------------------------------------.
 * |   F1 |   F2 |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTIO] = LAYOUT_planck_grid(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,     KC_F9,   KC_F10,   KC_F11,    KC_F12,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |Hue + | Hue- |      |qwerty|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Aud on|Audoff|      |      |      |      |      | Sat+ | Sat- |      |Colmak|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Mus on|Musoff|MusMod|      |      |      |      |Brit++|Brit- |      |Dvorak|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice+|Voice-|      |      |             |      |RGBTOG|RGBMOD|      |Plover|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   _______,   _______, _______, _______, _______, _______, RGB_HUI,  RGB_HUD, _______, QWERTY,
    _______, AU_ON,    AU_OFF,   _______, _______,  _______,_______, _______, RGB_SAI, RGB_SAD, _______, COLEMAK,
    _______, MU_ON,  MU_OFF,  MU_MOD,   _______,    _______,_______, _______, RGB_VAI, RGB_VAD, _______, DVORAK,
    _______, MUV_DE, MUV_IN, _______, _______, _______, _______, _______, RGB_TOG,  RGB_MOD, _______, PLOVER
)


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode switched to QWERTY\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;


    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
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
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;

  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

#ifdef RGB_MATRIX_ENABLE

extern led_config_t g_led_config;

void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, red, green, blue);
        }
    }
}

// Set Momentary LED color when holding down layer keys
void rgb_matrix_indicators_kb(void) {
  switch (biton32(layer_state)) {
    case _LOWER:
      rgb_matrix_set_color(0, 50, 50, 50);
      rgb_matrix_set_color(1, 0, 0, 255);
      rgb_matrix_set_color(2, 0, 0, 255);
      rgb_matrix_set_color(3, 0, 0, 255);
      rgb_matrix_set_color(4, 0, 0, 255);
      rgb_matrix_set_color(5, 0, 0, 255);
      rgb_matrix_set_color(6, 0, 0, 255);
      rgb_matrix_set_color(7, 190, 0, 255);
      rgb_matrix_set_color(8, 190, 0, 255);
      rgb_matrix_set_color(9, 190, 0, 255);
      rgb_matrix_set_color(10, 0, 0, 255);
      rgb_matrix_set_color(11, 50, 50, 50);
      rgb_matrix_set_color(12, 50, 50, 50);
      rgb_matrix_set_color(13, 50, 50, 50);
      rgb_matrix_set_color(14, 50, 50, 50);
      rgb_matrix_set_color(15, 50, 50, 50);
      rgb_matrix_set_color(16, 50, 50, 50);
      rgb_matrix_set_color(17, 50, 50, 50);
      rgb_matrix_set_color(18, 50, 50, 50);
      rgb_matrix_set_color(19, 190, 0, 255);
      rgb_matrix_set_color(20, 190, 0, 255);
      rgb_matrix_set_color(21, 190, 0, 255);
      rgb_matrix_set_color(22, 50, 50, 50);
      rgb_matrix_set_color(23, 50, 50, 50);
      rgb_matrix_set_color(24, 50, 50, 50);
      rgb_matrix_set_color(25, 50, 50, 50);
      rgb_matrix_set_color(26, 50, 50, 50);
      rgb_matrix_set_color(27, 50, 50, 50);
      rgb_matrix_set_color(28, 50, 50, 50);
      rgb_matrix_set_color(29, 50, 50, 50);
      rgb_matrix_set_color(30, 50, 50, 50);
      rgb_matrix_set_color(31, 190, 0, 255);
      rgb_matrix_set_color(32, 190, 0, 255);
      rgb_matrix_set_color(33, 190, 0, 255);
      rgb_matrix_set_color(34, 234, 250, 6);
      rgb_matrix_set_color(35, 50, 50, 50);
      rgb_matrix_set_color(36, 50, 50, 50);
      rgb_matrix_set_color(37, 50, 50, 50);
      rgb_matrix_set_color(38, 50, 50, 50);
      rgb_matrix_set_color(39, 50, 50, 50);
      rgb_matrix_set_color(40, 50, 50, 50);
      rgb_matrix_set_color(41, 50, 50, 50);
      rgb_matrix_set_color(42, 50, 50, 50);
      rgb_matrix_set_color(43, 0, 0, 0);
      rgb_matrix_set_color(44, 50, 50, 50);
      rgb_matrix_set_color(45, 190, 0, 255);
      rgb_matrix_set_color(46, 50, 50, 50);
      rgb_matrix_set_color(47, 234, 250, 6);
      rgb_matrix_set_color(48, 50, 50, 50);
       break;
    case _RAISE:
      rgb_matrix_set_color(0, 255, 111, 0);
      rgb_matrix_set_color(1, 0, 255, 0);
      rgb_matrix_set_color(2, 0, 255, 0);
      rgb_matrix_set_color(3, 0, 255, 0);
      rgb_matrix_set_color(4, 0, 255, 0);
      rgb_matrix_set_color(5, 0, 255, 0);
      rgb_matrix_set_color(6, 0, 255, 0);
      rgb_matrix_set_color(7, 0, 255, 0);
      rgb_matrix_set_color(8, 0, 255, 0);
      rgb_matrix_set_color(9, 255, 0, 255);
      rgb_matrix_set_color(10, 255, 0, 255);
      rgb_matrix_set_color(11, 255, 111, 0);
      rgb_matrix_set_color(12, 255, 111, 0);
      rgb_matrix_set_color(13, 255, 0, 0);
      rgb_matrix_set_color(14, 255, 0, 0);
      rgb_matrix_set_color(15, 255, 0, 0);
      rgb_matrix_set_color(16, 255, 0, 0);
      rgb_matrix_set_color(17, 255, 0, 0);
      rgb_matrix_set_color(18, 255, 0, 0);
      rgb_matrix_set_color(19, 0, 255, 0);
      rgb_matrix_set_color(20, 0, 255, 0);
      rgb_matrix_set_color(21, 255, 0, 255);
      rgb_matrix_set_color(22, 255, 0, 255);
      rgb_matrix_set_color(23, 255, 111, 0);
      rgb_matrix_set_color(24, 255, 111, 0);
      rgb_matrix_set_color(25, 255, 0, 0);
      rgb_matrix_set_color(26, 255, 0, 0);
      rgb_matrix_set_color(27, 255, 0, 0);
      rgb_matrix_set_color(28, 255, 0, 0);
      rgb_matrix_set_color(29, 255, 0, 0);
      rgb_matrix_set_color(30, 255, 0, 0);
      rgb_matrix_set_color(31, 0, 255, 0);
      rgb_matrix_set_color(32, 0, 255, 0);
      rgb_matrix_set_color(33, 255, 0, 255);
      rgb_matrix_set_color(34, 255, 0, 255);
      rgb_matrix_set_color(35, 255, 111, 0);
      rgb_matrix_set_color(36, 255, 111, 0);
      rgb_matrix_set_color(37, 255, 111, 0);
      rgb_matrix_set_color(38, 255, 111, 0);
      rgb_matrix_set_color(39, 255, 111, 0);
      rgb_matrix_set_color(40, 255, 111, 0);
      rgb_matrix_set_color(41, 0, 0, 0);
      rgb_matrix_set_color(42, 0, 0, 0);
      rgb_matrix_set_color(43, 0, 0, 0);
      rgb_matrix_set_color(44, 255, 111, 0);
      rgb_matrix_set_color(45, 255, 111, 0);
      rgb_matrix_set_color(46, 255, 111, 0);
      rgb_matrix_set_color(47, 255, 111, 0);
      rgb_matrix_set_color(48, 255, 111, 0);
      break;
    case _ADJUST:
      rgb_matrix_set_color(0, 50, 50, 50);
      rgb_matrix_set_color(1, 255, 0, 0);
      rgb_matrix_set_color(2, 50, 50, 50);
      rgb_matrix_set_color(3, 50, 50, 50);
      rgb_matrix_set_color(4, 50, 50, 50);
      //rgb_matrix_set_color(5, 50, 50, 50);
      //rgb_matrix_set_color(6, 50, 50, 50);
      rgb_matrix_set_color(7, 50, 50, 50);
      rgb_matrix_set_color(8, 0, 255, 188);
      rgb_matrix_set_color(9, 0, 255, 188);
      rgb_matrix_set_color(10, 50, 50, 50);
      rgb_matrix_set_color(11, 255, 0, 0);
      rgb_matrix_set_color(12, 50, 50, 50);
      rgb_matrix_set_color(13, 7, 190, 255);
      rgb_matrix_set_color(14, 7, 190, 255);
      rgb_matrix_set_color(15, 50, 50, 50);
      rgb_matrix_set_color(16, 50, 50, 50);
      //rgb_matrix_set_color(17, 50, 50, 50);
      //rgb_matrix_set_color(18, 50, 50, 50);
      rgb_matrix_set_color(19, 50, 50, 50);
      rgb_matrix_set_color(20, 0, 255, 85);
      rgb_matrix_set_color(21, 0, 255, 85);
      rgb_matrix_set_color(22, 50, 50, 50);
      rgb_matrix_set_color(23, 255, 0, 0);
      rgb_matrix_set_color(24, 50, 50, 50);
      rgb_matrix_set_color(25, 7, 190, 255);
      rgb_matrix_set_color(26, 7, 190, 255);
      rgb_matrix_set_color(27, 7, 190, 255);
      rgb_matrix_set_color(28, 50, 50, 50);
      //rgb_matrix_set_color(29, 50, 50, 50);
      //rgb_matrix_set_color(30, 50, 50, 50);
      rgb_matrix_set_color(31, 50, 50, 50);
      rgb_matrix_set_color(32, 111, 255, 0);
      rgb_matrix_set_color(33, 111, 255, 0);
      rgb_matrix_set_color(34, 50, 50, 50);
      rgb_matrix_set_color(35, 255, 0, 0);
      rgb_matrix_set_color(36, 50, 50, 50);
      rgb_matrix_set_color(37, 7, 190, 255);
      rgb_matrix_set_color(38, 7, 190, 255);
      rgb_matrix_set_color(39, 50, 50, 50);
      rgb_matrix_set_color(40, 50, 50, 50);
      //rgb_matrix_set_color(41, 50, 50, 50);
      //rgb_matrix_set_color(42, 50, 50, 50);
      //rgb_matrix_set_color(43, 50, 50, 50);
      rgb_matrix_set_color(44, 50, 50, 50);
      rgb_matrix_set_color(45, 205, 255, 0);
      rgb_matrix_set_color(46, 205, 255, 0);
      rgb_matrix_set_color(47, 50, 50, 50);
      rgb_matrix_set_color(48, 255, 0, 0);
      break;case _FUNCTIO:
      rgb_matrix_set_color(0, 244, 130, 66);
      rgb_matrix_set_color(1, 244, 140, 66);
      rgb_matrix_set_color(2, 244, 150, 66);
      rgb_matrix_set_color(3, 244, 160, 66);
      rgb_matrix_set_color(4, 244, 170, 66);
      rgb_matrix_set_color(5, 244, 180, 66);
      rgb_matrix_set_color(6, 244, 190, 66);
      rgb_matrix_set_color(7, 244, 200, 66);
      rgb_matrix_set_color(8, 244, 210, 66);
      rgb_matrix_set_color(9, 244, 220, 66);
      rgb_matrix_set_color(10, 244, 230, 66);
      rgb_matrix_set_color(11, 244, 240, 66);
      rgb_matrix_set_color(12, 66, 245, 96);
      rgb_matrix_set_color(13, 50, 50, 50);
      rgb_matrix_set_color(14, 50, 50, 50);
      rgb_matrix_set_color(15, 50, 50, 50);
      rgb_matrix_set_color(16, 50, 50, 50);
      rgb_matrix_set_color(17, 50, 50, 50);
      rgb_matrix_set_color(18, 50, 50, 50);
      rgb_matrix_set_color(19, 50, 50, 50);
      rgb_matrix_set_color(20, 50, 50, 50);
      rgb_matrix_set_color(21, 50, 50, 50);
      rgb_matrix_set_color(22, 50, 50, 50);
      rgb_matrix_set_color(23, 66, 245, 96);
      rgb_matrix_set_color(24, 66, 245, 96);
      rgb_matrix_set_color(25, 50, 50, 50);
      rgb_matrix_set_color(26, 50, 50, 50);
      rgb_matrix_set_color(27, 50, 50, 50);
      rgb_matrix_set_color(28, 50, 50, 50);
      rgb_matrix_set_color(29, 50, 50, 50);
      rgb_matrix_set_color(30, 50, 50, 50);
      rgb_matrix_set_color(31, 50, 50, 50);
      rgb_matrix_set_color(32, 50, 50, 50);
      rgb_matrix_set_color(33, 50, 50, 50);
      rgb_matrix_set_color(34, 50, 50, 50);
      rgb_matrix_set_color(35, 66, 245, 96);
      rgb_matrix_set_color(36, 66, 245, 96);
      rgb_matrix_set_color(37, 66, 245, 96);
      rgb_matrix_set_color(38, 66, 245, 96);
      rgb_matrix_set_color(39, 66, 245, 96);
      rgb_matrix_set_color(40, 66, 245, 96);
      rgb_matrix_set_color(41, 66, 245, 96);
      rgb_matrix_set_color(42, 66, 245, 96);
      rgb_matrix_set_color(43, 0, 0, 0);
      rgb_matrix_set_color(44, 66, 245, 96);
      rgb_matrix_set_color(45, 66, 245, 96);
      rgb_matrix_set_color(46, 66, 245, 96);
      rgb_matrix_set_color(47, 66, 245, 96);
      rgb_matrix_set_color(48, 66, 245, 96);
       break;
    default:
      switch (biton32(default_layer_state)) {
        case _QWERTY:
          rgb_matrix_layer_helper(0x00, 0x00, 0x68); break;
        case _COLEMAK:
          rgb_matrix_layer_helper(0xFF, 0x00, 0xFF); break;
        case _DVORAK:
          rgb_matrix_layer_helper(0x00, 0xFF, 0x00); break;

      }
  }


// Turn off LED in the center of spacebar; 0,0,0 = OFF
  switch (biton32(default_layer_state)) {
    case _QWERTY:
      rgb_matrix_set_color(42, 0, 0, 0); break;
    case _COLEMAK:
      rgb_matrix_set_color(42, 0, 0, 0); break;
    case _DVORAK:
      rgb_matrix_set_color(42, 0, 0, 0); break;
  }

}

#endif //RGB_MATRIX_INIT
