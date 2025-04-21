/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAV,
  _ADJUST
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

// Per-key tapping terms
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_D:
            return TAPPING_TERM - 50;
        case SFT_K:
            return TAPPING_TERM - 50;
        case CTL_J:
            return TAPPING_TERM + 50;
        case CTL_F:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

// Provide custom macros:
enum custom_keycodes {
    RAND_STR=SAFE_RANGE,
    CAD,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    // Random string
    case RAND_STR:
        if (record->event.pressed) {
          SEND_STRING("OCo85Uc@tLY47");
        }
        break;

    // ctrl + alt + del
    case CAD:
        if (record->event.pressed)
        {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_DOWN(X_DEL) SS_UP(X_DEL) SS_UP(X_LALT) SS_UP(X_LCTL));
        }
        break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_ortho(
        KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,        KC_Y,      KC_U,        KC_I,       KC_O,       KC_P,       KC_BSPC,    CAD,       RGB_TOG,
        KC_ESC,         GUI_A,      ALT_S,      SFT_D,      CTL_F,      KC_G,        KC_H,      CTL_J,       SFT_K,      ALT_L,      GUI_SCLN,   KC_QUOT,    RAND_STR,
        KC_CAPS,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,        KC_N,      KC_M,        KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,     KC_UP,
        KC_MPLY,        KC_LCTL,    KC_LGUI,    KC_LALT,    LOWER,      NAV_SPACE,   NAV_SPACE, RAISE,       _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT
    ),  

    [_LOWER] = LAYOUT_ortho(
        KC_TILD,        KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,     KC_CIRC,   KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,   KC_DEL,     _______,    RGB_MOD,
        KC_DEL,         KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,       KC_F6,     KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,   KC_PIPE,    _______,
        _______,        KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,      KC_F12,    KC_PSCR,    _______,    KC_HOME,    KC_END,    _______,    KC_VOLU,
        _______,        _______,    _______,    _______,    _______,    _______,     _______,   _______,    _______,    _______,    _______,   KC_MPRV,    KC_VOLD,    KC_MNXT
    ),  

    [_RAISE] = LAYOUT_ortho(
        KC_GRV,         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,      KC_7,       KC_8,       KC_9,       KC_0,      KC_DEL,     _______,    RGB_RMOD,
        KC_DEL,         KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,     KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,   KC_BSLS,    _______,
        _______,        KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,    KC_PSCR,    _______,    KC_HOME,    KC_END,    _______,    KC_VOLU,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,   _______,    _______,    _______,    _______,   KC_MPRV,    KC_VOLD,    KC_MNXT
    ),  

    [_ADJUST] = LAYOUT_ortho(
        QK_BOOT,    _______,    _______,    _______,    _______,    _______,   _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    AG_NORM,   AG_SWAP,     CG_SWAP,    CG_NORM,    _______,    _______,    _______,    _______,    
        _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,    _______,    _______,    _______,    _______,    RGB_HUI,    
        EE_CLR,     _______,    _______,    _______,    _______,    _______,   _______,     _______,    _______,    _______,    _______,    RGB_SAD,    RGB_HUD,    RGB_SAI
    ),

    [_NAV] = LAYOUT_ortho(
        _______,    _______,    _______,    _______,    _______,    _______,   KC_BTN1,     KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_BTN2,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,   _______,     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,    _______,    
        _______,    _______,    _______,    _______,    KC_BTN1,    KC_BTN2,   _______,     _______,    _______,    _______,    _______,    _______,    KC_MS_U,    
        _______,    _______,    _______,    _______,    _______,    _______,   _______,     _______,    _______,    _______,    _______,    KC_MS_L,    KC_MS_D,    KC_MS_R
    )
};

//Initialize indicator LEDs
void matrix_init_user(void) {
  setPinOutput(B5);
  writePinLow(B5);
  setPinOutput(B6);
  writePinLow(B6);
  setPinOutput(B7);
  writePinLow(B7);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(B7);
    writePinLow(B6);
    switch (get_highest_layer(state)) {
    case 1:
        writePinHigh(B7);
        break;
    case 2:
        writePinHigh(B6);
        break;
    case 3:
        writePinHigh(B7);
        writePinHigh(B6);
        break;
    }
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool led_update_user(led_t led_state) {
    writePin(B5, led_state.caps_lock);
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;  // returning false overrides the keyboard level function
}

