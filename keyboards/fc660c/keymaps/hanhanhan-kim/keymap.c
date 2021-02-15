/*
Copyright 2017 Balz Guenat

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

enum custom_keycodes {
    SFT_PSCR = SAFE_RANGE,
    ALT_PSCR,
    TERMINAL_LIN,
    END_ZOOM_CALL_LIN,
    END_ZOOM_CALL_WIN,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SFT_PSCR:
        if (record->event.pressed) {
          // ROI screenshot on linux:
          SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_PSCREEN) SS_UP(X_LSFT));
        } else {
            // when keycode SFT_PSCR is released
        }
        break;

    case ALT_PSCR:
        if (record->event.pressed) {
          // App-specific screenshot on linux:
          SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_PSCREEN) SS_UP(X_LALT));
        } else {
            // when keycode ALT_PSCR is released
        }
        break;

    case TERMINAL_LIN:
        if (record->event.pressed) {
          // Open up terminal on linux:
          SEND_STRING(SS_DOWN(X_LCTL) SS_LALT("t") SS_UP(X_LCTL));
        } else {
            // when keycode TERMINAL_LIN is released
        }
        break;

    case END_ZOOM_CALL_LIN:
        if (record->event.pressed) {
          // End Zoom call on Linux:
          SEND_STRING(SS_LALT("q") SS_TAP(X_ENTER));
        }
        break;

    case END_ZOOM_CALL_WIN:
        if (record->event.pressed) {
          // End Zoom call on Windows:
          SEND_STRING(SS_LALT("q") SS_TAP(X_TAB) SS_TAP(X_ENTER));
        }
        break;

    }
    return true;
};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  // FC660C uses B6 as the Caps Lock LED
  setPinOutput(B6); 
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        // writePin sets the pin high for 1 and low for 0.
        // In this example the pins are inverted, setting
        // it low/0 turns it on, and high/1 turns the LED off.
        // This behavior depends on whether the LED is between the pin
        // and VCC or the pin and GND.
        // writePin(B0, !led_state.num_lock);
        // writePin(B1, !led_state.caps_lock);
        // writePin(B2, !led_state.scroll_lock);
        // writePin(B3, !led_state.compose);
        // writePin(B4, !led_state.kana);
        writePin(B6, !layer_state_is(1));
    }
    return res;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
        KC_GRAVE, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_HOME,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,       KC_END,
        TG(1),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     KC_ENT,
        OSM(MOD_LSFT),KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_ESCAPE,        KC_UP,
        KC_LCTL,KC_LGUI,KC_LALT,          KC_SPC,                       SFT_PSCR,KC_CAPS,KC_DEL,               KC_LEFT,KC_DOWN,KC_RGHT
    ),
  [1] = LAYOUT(
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
        TG(1)  ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_MEDIA_PLAY_PAUSE,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                               KC__VOLUP,
        _______,_______,_______,                _______,                _______,_______,_______,                  KC_MEDIA_PREV_TRACK,KC__VOLDOWN,KC_MEDIA_NEXT_TRACK
    )
};
