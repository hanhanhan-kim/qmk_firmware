// Copyright 2023 Han Kim (@hanhanhan-kim)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// For a good home row mod experience:
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

/* Set 0 if debouncing isn't needed. Default is 5. I recommend at least default, especially for handwired builds*/
#define DEBOUNCE 10

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
