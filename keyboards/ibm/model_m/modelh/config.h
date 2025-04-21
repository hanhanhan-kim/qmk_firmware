/*
Copyright 2020 John Hawthorn

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

#pragma once


/* Model H customizations */

<<<<<<< HEAD:keyboards/crkbd/config.h
// wiring of each half
#define MATRIX_COL_PINS \
    { F4, F5, F6, F7, B1, B3 }
// #define MATRIX_COL_PINS { B2, B3, B1, F7, F6, F5, F4 } //uncomment this line and comment line above if you need to reverse left-to-right key order

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed, default is 5 */
#define DEBOUNCE 5
=======
#define MODELH_STATUS_LED C13
>>>>>>> master:keyboards/ibm/model_m/modelh/config.h

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
<<<<<<< HEAD:keyboards/crkbd/config.h

// For a good home row mod experience:
// Prevent normal rollover on alphas form accidentally triggering mods:
 #define IGNORE_MOD_TAP_INTERRUPT
 //Enable rapid switch from tap to hold, disables double tap hold auto-repeat
 // may have to modify this so it's not global
 #define TAPPING_FORCE_HOLD

#define USE_SERIAL
=======
>>>>>>> master:keyboards/ibm/model_m/modelh/config.h
