/* Copyright 2018 Jack Humbert
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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEFE
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    Pauper
#define PRODUCT         Brick

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { D3, D5, F0, F1 }
#define MATRIX_COL_PINS { B1, B3, F7, F6, D4, D6, D7, B4, B5, B6, C6, C7 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define RGB_DI_PIN D2
#ifdef RGB_DI_PIN
    #define RGBLED_NUM 8
    #define RGBLIGHT_HUE_STEP 8
    #define RGBLIGHT_SAT_STEP 8
    #define RGBLIGHT_VAL_STEP 8
#endif

// For a good home row mod experience:

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD