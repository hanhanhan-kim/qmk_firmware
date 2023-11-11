// Copyright 2023 Han Kim (@hanhanhan-kim)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

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

// place overrides here ...

// For a good home row mod experience:
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

/* Rotary Encoder Support */
#define ENCODERS_PAD_A { D2 } // adjust according to handwiring ... see also the info.json
#define ENCODERS_PAD_B { D3 } // adjust accoridn g to handwiring ... see al the info.json
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 10