/* Copyright 2020 GhostSeven
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

// // Provide custom macros:
// enum custom_keycodes {
//     ROI_PSCR=SAFE_RANGE,
// };

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {

//   switch (keycode) {
//   // ROI PrintScreen on Linux:
//     case ROI_PSCR:
//         if (record->event.pressed) {
//           SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_PSCR) SS_UP(X_LSFT));
//         }
//         break;
//   }
//   return true;
// };


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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Play | LCtrl| LGUI | LAlt | Lower| Space| Space| Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
    KC_ESC,  GUI_A,   ALT_S,   SFT_D,   CTL_F,   KC_G,      KC_H,        CTL_J,   SFT_K,   ALT_L,   GUI_SCLN, KC_QUOT,
    KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,        KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
    KC_MPLY, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   NAV_SPACE, NAV_SPACE,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Pscr |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,  KC_PLUS,  KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,  _______,  KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  KC_MPRV,  KC_VOLD, KC_VOLU, KC_MNXT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Pscr |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, _______, KC_HOME,  KC_END, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Adjust
* ,-----------------------------------------------------------------------------------.
 * |RESET |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |AGNorm|AGSwap|CGSwap|CGNorm|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |EEPROM|      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
    QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, CG_SWAP, CG_NORM,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    EE_CLR , _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
),

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |LeftCl|MouseL|MouseD|MouseU|MouseR|RiteCl|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_L, KC_MS_D,  KC_MS_U, KC_MS_R, KC_BTN2,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } 
    return false; // returning false overrides the keyboard level function
}

void matrix_init_user(void) {

}
