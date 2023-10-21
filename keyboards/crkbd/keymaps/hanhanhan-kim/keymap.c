/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers { _QWERTY, 
              _LOWER, 
              _RAISE, 
              _NAV,
              };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAV_SPACE LT(_NAV, KC_SPC)

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// I never use this, but whatever:
#define ALT_BSPC LALT_T(KC_BSPC)

// OLED: Animation stuff
#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 40 //Switch to fast animation when over words per minute

#ifdef OLED_ENABLE
#include "crab.c"
#endif

// OLED: Corne logo
void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    0};
    oled_write_P(crkbd_logo, false);
}

// Normal keyboard keymapping:

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                             ,---------------------------------------------------------.
     KC_TAB,   KC_Q,   KC_W,    KC_E,     KC_R,     KC_T,                                   KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,      KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                             |---------+--------+--------+--------+----------+---------|
     KC_ESC,   GUI_A,  ALT_S,   SFT_D,    CTL_F,    KC_G,                                   KC_H,   CTL_J,    SFT_K,   ALT_L,  GUI_SCLN,   KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                             |---------+--------+--------+--------+----------+---------|
     KC_CAPS,  KC_Z,   KC_X,    KC_C,     KC_V,     KC_B,                                   KC_N,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,   _______,
  //|--------+--------+--------+--------+--------+----------+----------|   |----------+-----------+--------+--------+--------+----------+---------|
                                          LOWER,  NAV_SPACE,  ALT_BSPC,       KC_ENT,   NAV_SPACE,   RAISE
                                      //`------------------------------'    `-------------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
    KC_TILD, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,              KC_CIRC,  KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                KC_F6,    KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR,  KC_PIPE,
    _______, KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,               KC_F12,   KC_PSCR,  _______, KC_HOME, KC_END,  _______,
                              KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
    KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_5,                   KC_F6,   KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,                 KC_F12,  KC_PSCR,  _______, KC_HOME, KC_END, _______,
                              KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS,  KC_TRNS
  ),

  [_NAV] = LAYOUT_split_3x6_3(
    XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,         XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,         XXXXXXX, KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
    XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,         XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
                                  XXXXXXX,   XXXXXXX,  XXXXXXX,         XXXXXXX, XXXXXXX,  XXXXXXX
  ),

};

// Custom per-key tapping terms
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_D:
          return TAPPING_TERM;
        case SFT_K:
          return TAPPING_TERM;
        case GUI_A:
          return TAPPING_TERM + 10;
        case GUI_SCLN:
          return TAPPING_TERM + 10;
        default:
          return TAPPING_TERM;
    }
}


// Slave side will show animation:
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return rotation;
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_render_anim();
  } else {
    oled_render_logo();
  }
  return false;
}
#endif