/* Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
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
          SEND_STRING("OCo85Uc@tLY40");
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

enum torn_layers { _QWERTY, 
                   _LOWER, 
                   _RAISE, 
                   _NAV,
                   _ADJUST };

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

// Random:
#define ALT_BSPC LALT_T(KC_BSPC)
// #define S_BSPC LSFT_T(KC_BSPC)
// #define R_DEL LT(_RAISE, KC_DEL)
// #define G_ENT LGUI_T(KC_ENT)
// #define L_SPC LT(_LOWER, KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.    ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |    |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |    |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Caps |   Z  |   X  |   C  |   V  |   B  |    |   N  |   M  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               |Ctrl+  |Lower |Space|Alt  |    |Enter |Space |Raise |      |
 *               |Alt+Del|      | Nav |     |    |      | Nav  |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_QWERTY] = LAYOUT_split_3x6_4(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,      KC_Y,      KC_U,      KC_I,    KC_O,    KC_P,     KC_BSPC,
    KC_ESC,  GUI_A,   ALT_S,   SFT_D,   CTL_F,      KC_G,      KC_H,      CTL_J,     SFT_K,   ALT_L,   GUI_SCLN, KC_QUOT,
    KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,      KC_N,      KC_M,      KC_COMM, KC_DOT,  KC_SLSH,  _______,
                      CAD,     LOWER,   NAV_SPACE,  ALT_BSPC,  KC_ENT,   NAV_SPACE,  RAISE,   RAND_STR
),

/* Lower
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |  ~   |   !  |   @  |   #  |   $  |   %  |    |   ^  |   &  |   *  |   (  |   )  |  Del |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |  Del |  F1  |  F2  |  F3  |  F4  |  F5  |    |  F6  |   _  |   +  |   {  |   }  |   |  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Caps |  F7  |  F8  |  F9  |  F10 |  F11 |    |  F12 | Pscr |      | Home|  End |       |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ |      |      |      |    |      |      |      | ____ |
 *               |      |      |     |      |     |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_LOWER] = LAYOUT_split_3x6_4(
    KC_TILD, KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,    KC_F6,    KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR,  KC_PIPE,
    KC_CAPS, KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,   KC_PSCR,  _______, KC_HOME, KC_END,  _______,
                      KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS
),

/* Raise
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |    |   6  |   7  |   8  |   9  |  0   |  Del |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |  Del |  F1  |  F2  |  F3  |  F4  |  F5  |    |  F6  |   -  |   =  |   [  |   ]  |   \  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Caps |  F7  |  F8  |  F9  |  F10 |  F11 |    |  F12 | Pscr |      | Home|  End |       |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ |      |      |      |    |      |      |      | ____ |
 *               |      |      |      |      |    |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_RAISE] = LAYOUT_split_3x6_4(
    KC_GRV,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_5,       KC_F6,   KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,  KC_PSCR,  _______, KC_HOME, KC_END, _______,
                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ |      |      |      |    |      |      |      | ____ |
 *               |      |      |      |      |    |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_ADJUST] = LAYOUT_split_3x6_4(
    QK_BOOT, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, AG_NORM, AG_SWAP,   CG_SWAP, CG_NORM, _______, _______, _______, _______,
    EE_CLR , _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Navigation
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 *               | ____ |      |      |      |    |      |      |      | ____ |
 *               |      |      |      |      |    |      |      |      |      |
 *               `---------------------------'    `---------------------------'
 */
[_NAV] = LAYOUT_split_3x6_4(
    _______, _______, _______, KC_BTN2, KC_BTN1, _______,   KC_BTN1, KC_MS_L, KC_MS_D,  KC_MS_U, KC_MS_R, KC_BTN2,
    _______, _______, _______, _______, _______, _______,   _______, KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)

};

// Custom per-key tapping terms
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_D:
          return TAPPING_TERM - 25;
        case SFT_K:
          return TAPPING_TERM - 25;
        case GUI_A:
          return TAPPING_TERM + 25;
        case GUI_SCLN:
          return TAPPING_TERM + 25;
        default:
          return TAPPING_TERM;
    }
}

// Define ADJUST layer as combo of LOWER and RAISE and assign LEDs
layer_state_t layer_state_set_user(layer_state_t state) {
    torn_set_led(0, IS_LAYER_ON_STATE(state, _RAISE));
    torn_set_led(1, IS_LAYER_ON_STATE(state, _LOWER));
    torn_set_led(2, IS_LAYER_ON_STATE(state, _NAV));
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


// const uint16_t PROGMEM encoder_keymaps[][2][2] = {
//     [_QWERTY] =  { { C(S(KC_TAB)), C(KC_TAB) },     { KC_PGDN,      KC_PGUP } },
//     [_LOWER]  =  { { C(KC_LEFT),   C(KC_RGHT) },    { KC__VOLDOWN,  KC__VOLUP } },
//     [_RAISE]  =  { { KC_TRNS,      KC_TRNS },       { G(KC_TAB),    G(S(KC_TAB)) } },
//     [_ADJUST] =  { { KC_TRNS,      KC_TRNS },       { KC_TRNS,      KC_TRNS } },
// };

// Define encoder functions:
static bool tabbing = false;
static uint16_t tabtimer;
#define TABBING_TIMER 750

bool encoder_update_user(uint8_t index, bool clockwise) {

  // Left encoder
  if (index == 0) {
      if (clockwise) {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }
        tap_code(KC_TAB);
      } else {
        tabtimer = timer_read();
        if(!tabbing) {
          register_code(KC_LALT);
          tabbing = true;
        }

        register_code(KC_LSFT);
        tap_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
  // Right encoder
  } else if (index == 1) {
      if (clockwise) {
          tap_code16(C(KC_TAB));
        } else {
          tap_code16(S(C(KC_TAB)));
        } 
  }
  return true;
}

void matrix_scan_user(void) {
  if(tabbing) {
    if (timer_elapsed(tabtimer) > TABBING_TIMER) {
      unregister_code(KC_LALT);
      tabbing = false;
    }
  }
}


// void matrix_init_user(void) {

// }