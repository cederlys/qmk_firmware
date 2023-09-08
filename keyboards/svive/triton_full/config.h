// Copyright 2023 Per Cederqvist (@Per Cederqvist)
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

// This keyboard has a special fourth LED, that by default indicates
// if the Windows key has been disabled.  This state is toggled by
// pressing Fn+Win in the stock firmware.  The default keymap also
// implements this.
#define LED_WIN_LOCK_PIN   D6

/* RGB matrix configuration can't be fully expressed in JSON as of now */
#define RGB_MATRIX_LED_COUNT (105)
#define SN32_RGB_MATRIX_ROW_PINS { C0, C1, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, B13, D3, B15, B14 }

/* Enable additional RGB effects                                       */
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

/* Configure the effects:                                              */
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
