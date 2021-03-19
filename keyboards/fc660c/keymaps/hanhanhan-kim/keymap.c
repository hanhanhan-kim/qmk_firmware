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

// MACROS------------------------------------------------------------------------
enum custom_keycodes {
  
    UNTAB_TAB=SAFE_RANGE,
    SFTPSCR_PSCR,
    END_HOME,
    MOUSE_R_L,

    START_TERMINAL,

    START_SIGNAL,
    START_VSCODE,
    START_CHROME,
    START_SPOTIFY, 
    START_ARDUINO,
    START_TYPORA,
    START_FILES,

    END_ZOOM_CALL_LIN,
    END_ZOOM_CALL_WIN,

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

  // REGULAR MACROS:
    case START_SIGNAL:
        if (record->event.pressed) {
          // Start up Signal on either Windows or Linux:
          writePin(B6, 1); // turn off LED (hacky ...)
          SEND_STRING(SS_DELAY(100) SS_TAP(X_LGUI) SS_DELAY(100) "signal" SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100));
          layer_off(1);
        }
        break;

    case START_VSCODE:
        if (record->event.pressed) {
          // Start up VSCode on either Windows or Linux:
          writePin(B6, 1); // turn off LED (hacky ...)
          SEND_STRING(SS_DELAY(100) SS_TAP(X_LGUI) SS_DELAY(100) "vscode" SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100));
          layer_off(1);
        }
        break;

    case START_CHROME:
        if (record->event.pressed) {
          // Start up Spotify on either Windows or Linux:
          writePin(B6, 1); // turn off LED (hacky ...)
          SEND_STRING(SS_DELAY(100) SS_TAP(X_LGUI) SS_DELAY(100) "chrome" SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100));
          layer_off(1);
        }
        break;
    
    case START_SPOTIFY:
        if (record->event.pressed) {
          // Start up Spotify on either Windows or Linux:
          writePin(B6, 1); // turn off LED (hacky ...)
          SEND_STRING(SS_DELAY(100) SS_TAP(X_LGUI) SS_DELAY(100) "spotify" SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100));
          layer_off(1);
        }
        break;

    case START_ARDUINO:
        if (record->event.pressed) {
          // Start up Arduino on either Windows or Linux:
          writePin(B6, 1); // turn off LED (hacky ...)
          SEND_STRING(SS_DELAY(100) SS_TAP(X_LGUI) SS_DELAY(100) "arduino" SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100));
          layer_off(1);
        }
        break;

    case START_TYPORA:
        if (record->event.pressed) {
          // Start up Typora on either Windows or Linux:
          writePin(B6, 1); // turn off LED (hacky ...)
          SEND_STRING(SS_DELAY(100) SS_TAP(X_LGUI) SS_DELAY(100) "typora" SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100));
          layer_off(1);
        }
        break;
    
    case START_FILES:
        if (record->event.pressed) {
          // Start up VSCode on either Windows or Linux:
          writePin(B6, 1); // turn off LED (hacky ...)
          tap_code(KC_MY_COMPUTER);
          layer_off(1);
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

  // TAP VS. HOLD MACROS:

  static uint16_t my_hash_timer;

    case UNTAB_TAB:
      // If tapped, will send Tab, if held down, will send Shift + Tab
      if(record->event.pressed) { // When UNTAB_TAB is pressed for ANY duration:
          my_hash_timer = timer_read();
        } else { // When UNTAB_TAB is EVER released
          if (timer_elapsed(my_hash_timer) < TAPPING_TERM) { // If UNTAB_TAB was tapped
            SEND_STRING(SS_TAP(X_TAB)); 
          } else { // If UNTAB_TAB was held down:          
            register_code(KC_LSFT);
            tap_code(KC_TAB);
            unregister_code(KC_LSFT); 
          }
        }
      return false; // We handled this keypress

    case SFTPSCR_PSCR:
      // If tapped, will send PrintScreen, if held down, will send Shift + PrintScreen 
      if(record->event.pressed) { // When SFTPSCR_PSCR is pressed for ANY duration:
          my_hash_timer = timer_read();
        } else { // When SFTPSCR_PSCR is EVER released

          if (timer_elapsed(my_hash_timer) < TAPPING_TERM) { // If SFTPSCR_PSCR was tapped
            SEND_STRING(SS_TAP(X_PSCR)); 

          } else { // If SFTPSCR_PSCR was held down:
            register_code(KC_LSFT);
            tap_code(KC_PSCR);
            unregister_code(KC_LSFT);
          }
        }
      return false; // We handled this keypress

    case END_HOME:
      // If tapped, will send Home, if held down, will send End
      if(record->event.pressed) { // When END_HOME is pressed for ANY duration:
          my_hash_timer = timer_read();

        } else { // When END_HOME is EVER released

          if (timer_elapsed(my_hash_timer) < TAPPING_TERM) { // If END_HOME was tapped
            SEND_STRING(SS_TAP(X_HOME)); 

          } else { // If END_HOME was held down:          
            tap_code(KC_END);
          }
        }
      return false; // We handled this keypress

    case START_TERMINAL:
        if (record->event.pressed) {
          my_hash_timer = timer_read();
          
        } else {
            if (timer_elapsed(my_hash_timer) < TAPPING_TERM) { // If START_TERMINAL was tapped
              // Open up terminal on Linux:
              writePin(B6, 1); // turn off LED (hacky ...)
              SEND_STRING(SS_DOWN(X_LCTL) SS_LALT("t") SS_UP(X_LCTL));
              layer_off(1);  
            } else { // If START_TERMINAL was held down, open up git bash on Windows:
              writePin(B6, 1); // turn off LED (hacky ...)
              SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "gitbash" SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100));
              layer_off(1);
            }
        }
        break;

    case MOUSE_R_L:
      // If tapped, will send Home, if held down, will send End
      if(record->event.pressed) { // When MOUSE_R_L is pressed for ANY duration:
          my_hash_timer = timer_read();

        } else { // When MOUSE_R_L is EVER released

          if (timer_elapsed(my_hash_timer) < TAPPING_TERM) { // If MOUSE_R_L was tapped
            tap_code(KC_MS_BTN1); 

          } else { // If MOUSE_R_L was held down:          
            tap_code(KC_MS_BTN2);
          }
        }
      return false; // We handled this keypress

  }

  return true;
};

// ADVANCED TAP DANCING----------------------------------------------------------------
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD, // Doesn't seem to work doesn't
    DOUBLE_SINGLE_TAP, // Send two single taps ... Doesn't seem to work
    TRIPLE_TAP,
    TRIPLE_HOLD // Doesn't seem to work
};

// Tap dance enums
enum {
    PY_DOCS, // I put this tap vs. hold behaviour as a tap dance instead of a macro, because of a bug that swaps typed chars
    ESC_GRAVE_MD_DOCS,
    SOME_OTHER_DANCE
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void py_docs_finished(qk_tap_dance_state_t *state, void *user_data);
void py_docs_reset(qk_tap_dance_state_t *state, void *user_data);
void esc_grave_md_docs_finished(qk_tap_dance_state_t *state, void *user_data);
void esc_grave_md_docs_reset(qk_tap_dance_state_t *state, void *user_data);

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8; // Magic number. At some point this method will expand to work for more presses
}

// Create an instance of 'tap' for each of the tap dances:
static tap py_docs_tap_state = {
    .is_press_action = true,
    .state = 0
};

static tap esc_grave_md_docs_tap_state = {
    .is_press_action = true,
    .state = 0
};

void py_docs_finished(qk_tap_dance_state_t *state, void *user_data) {
    py_docs_tap_state.state = cur_dance(state);
    switch (py_docs_tap_state.state) {
        case SINGLE_TAP: register_code(KC_QUOTE); break;  
        case SINGLE_HOLD: 
          tap_code(KC_QUOTE);
          tap_code(KC_QUOTE);
          tap_code(KC_QUOTE);
          tap_code(KC_ENTER);
          tap_code(KC_ENTER);
          tap_code(KC_QUOTE);
          tap_code(KC_QUOTE);
          tap_code(KC_QUOTE);
          tap_code(KC_UP);
          tap_code(KC_ESC);
          break;

        // case DOUBLE_TAP: register_code(KC_B); break; // for example
        // case TRIPLE_TAP: register_code(KC_3); break; // for example

        // // Last case is for fast typing. Assuming your key is `f`:
        // // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        // case DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void py_docs_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (py_docs_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_QUOTE); break;
        case SINGLE_HOLD: clear_keyboard(); break;
        // case DOUBLE_TAP: unregister_code(KC_B); break; // for example
        // case TRIPLE_TAP: unregister_code(KC_3); break; // for example
    }
    py_docs_tap_state.state = 0;
}

void esc_grave_md_docs_finished(qk_tap_dance_state_t *state, void *user_data) {
    esc_grave_md_docs_tap_state.state = cur_dance(state);
    switch (esc_grave_md_docs_tap_state.state) {
        case SINGLE_TAP: tap_code(KC_GRAVE); break;  
        case SINGLE_HOLD: 
          tap_code(KC_GRAVE);
          tap_code(KC_GRAVE);
          tap_code(KC_GRAVE);
          tap_code(KC_ENTER);
          tap_code(KC_ENTER);
          tap_code(KC_GRAVE);
          tap_code(KC_GRAVE);
          tap_code(KC_GRAVE);
          tap_code(KC_UP);
          tap_code(KC_ESC);
          break;
        case DOUBLE_TAP: register_code(KC_ESC); break;
        // case TRIPLE_TAP: register_code(KC_3); break; // for example

        // // Last case is for fast typing. Assuming your key is `f`:
        // // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        // case DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void esc_grave_md_docs_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (esc_grave_md_docs_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_QUOTE); break;
        case SINGLE_HOLD: clear_keyboard(); break;
        case DOUBLE_TAP: unregister_code(KC_ESC); break;
        // case TRIPLE_TAP: unregister_code(KC_3); break; // for example
    }
    esc_grave_md_docs_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [PY_DOCS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, py_docs_finished, py_docs_reset),
    [ESC_GRAVE_MD_DOCS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, esc_grave_md_docs_finished, esc_grave_md_docs_reset)
};

// When tap dancing, remember to preface the command in the keymap with TD(). E.g. TD(X_CTL)

// COMBOING----------------------------------------------------------------------------
// When two buttons are pressed (very near) simultaneously, a piece of punctuation appears
enum combos {

  SPACE_F_LPAR,
  SPACE_D_LBRAK,
  SPACE_S_LBRAC,
  SPACE_A_LCAR,

  SPACE_J_RPAR,
  SPACE_K_RBRAK,
  SPACE_L_RBRAC,
  SPACE_SCLN_RCAR,

  SPACE_W_HTAG,
  SPACE_E_USCR,
  SPACE_R_DASH,
  
  SPACE_U_PLUS,
  SPACE_I_EQL,

};

const uint16_t PROGMEM spacef_combo[] = {KC_SPACE, KC_F, COMBO_END};
const uint16_t PROGMEM spaced_combo[] = {KC_SPACE, KC_D, COMBO_END};
const uint16_t PROGMEM spaces_combo[] = {KC_SPACE, KC_S, COMBO_END};
const uint16_t PROGMEM spacea_combo[] = {KC_SPACE, KC_A, COMBO_END};

const uint16_t PROGMEM spacej_combo[] = {KC_SPACE, KC_J, COMBO_END};
const uint16_t PROGMEM spacek_combo[] = {KC_SPACE, KC_K, COMBO_END};
const uint16_t PROGMEM spacel_combo[] = {KC_SPACE, KC_L, COMBO_END};
const uint16_t PROGMEM spacescln_combo[] = {KC_SPACE, KC_SCLN, COMBO_END};

const uint16_t PROGMEM spacew_combo[] = {KC_SPACE, KC_W, COMBO_END};
const uint16_t PROGMEM spacee_combo[] = {KC_SPACE, KC_E, COMBO_END};
const uint16_t PROGMEM spacer_combo[] = {KC_SPACE, KC_R, COMBO_END};

const uint16_t PROGMEM spaceu_combo[] = {KC_SPACE, KC_U, COMBO_END};
const uint16_t PROGMEM spacei_combo[] = {KC_SPACE, KC_I, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {

  [SPACE_F_LPAR] = COMBO(spacef_combo, KC_LPRN),
  [SPACE_D_LBRAK] = COMBO(spaced_combo, KC_LBRC),
  [SPACE_S_LBRAC] = COMBO(spaces_combo, KC_LCBR),
  [SPACE_A_LCAR] = COMBO(spacea_combo, KC_LABK),
  
  [SPACE_J_RPAR] = COMBO(spacej_combo, KC_RPRN),
  [SPACE_K_RBRAK] = COMBO(spacek_combo, KC_RBRC),
  [SPACE_L_RBRAC] = COMBO(spacel_combo, KC_RCBR),
  [SPACE_SCLN_RCAR] = COMBO(spacescln_combo, KC_RABK),

  [SPACE_W_HTAG] = COMBO(spacew_combo, KC_HASH),
  [SPACE_E_USCR] = COMBO(spacee_combo, KC_UNDS),
  [SPACE_R_DASH] = COMBO(spacer_combo, KC_PMNS),

  [SPACE_U_PLUS] = COMBO(spaceu_combo, KC_PPLS),
  [SPACE_I_EQL] = COMBO(spacei_combo, KC_EQL), 

};
// INDICATOR LED------------------------------------------------------------------------

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  // FC660C uses B6 as the Caps Lock LED
  setPinOutput(B6); 
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
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
        writePin(B6, !layer_state_is(1)); // if Layer 1 is enabled, turn on LED

        // TODO: Fix LED light-up for when layer is turned off programmatically!! Do manually with each command for now (very hacky)
        
    } 

    return res; 
}

// KEYMAP-----------------------------------------------------------------------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
        TD(ESC_GRAVE_MD_DOCS), KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL,   KC_BSPC,   SFTPSCR_PSCR,
        UNTAB_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,                 KC_DEL,
        TG(1),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, TD(PY_DOCS),    KC_ENT,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT,         KC_UP,
        KC_LCTL,KC_LGUI,KC_LALT,          KC_SPC,          KC_RALT,KC_LCTL,END_HOME,                     KC_LEFT,KC_DOWN,KC_RIGHT
    ),
  [1] = LAYOUT(
        TD(ESC_GRAVE_MD_DOCS), KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,     _______,
        _______,_______,_______,_______,_______,START_TERMINAL,START_TYPORA,_______,_______,_______,_______,_______,_______,_______,     _______,
        TG(1)  ,START_ARDUINO,START_SIGNAL,KC_MS_L,KC_MS_D,_______,_______,KC_MS_U,KC_MS_R,_______,_______,_______,KC_MEDIA_PLAY_PAUSE,
        _______,_______,START_FILES,START_CHROME,START_VSCODE,_______,_______,START_SPOTIFY,_______,_______,_______,_______,                      KC__VOLUP,
        _______,_______,_______,                MOUSE_R_L,                _______,_______,_______,                              KC_MEDIA_PREV_TRACK,KC__VOLDOWN,KC_MEDIA_NEXT_TRACK
    )
};
