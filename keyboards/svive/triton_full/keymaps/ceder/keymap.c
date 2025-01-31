// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

// This keymap is similar to the default keymap.  The major changes are:
//
// - The Fn and GUI keys are swapped.
// - The Win disable feature is removed.
// - The Fn layer adds various keys to control the RGB matrix
// - The right Ctrl key toggles the mouse layer, where the numerical
//   keyboard can be used to manipulate the pointer and send scroll
//   wheel events.  The "win lock" led indicates when this layer is
//   enabled.

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FN,
    _MS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
     * │Esc│   │F1 │F2 │F3 │F4 │ │F5 │F6 │F7 │F8 │ │F9 │F10│F11│F12│ │PSc│Scr│Pse│
     * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│ │Ins│Hom│PgU│ │Num│ / │ * │ - │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │     │ │Del│End│PgD│ │ 7 │ 8 │ 9 │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ Ent│ └───┴───┴───┘ ├───┼───┼───┤ + │
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ # │    │               │ 4 │ 5 │ 6 │   │
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐     ├───┼───┼───┼───┤
     * │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │     │ ↑ │     │ 1 │ 2 │ 3 │   │
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤Ent│
     * │Ctrl│Fn  │Alt │                        │ Alt│GUI │Menu│Ctrl│ │ ← │ ↓ │ → │ │   0   │ . │   │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
     */
    [_BASE] = LAYOUT_fullsize_iso(
    KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4,    KC_F5, KC_F6, KC_F7, KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_PSCR, KC_SCRL, KC_PAUS,
    KC_GRV, KC_1, KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_MINS, KC_EQL,     KC_BSPC,        KC_INS,  KC_HOME, KC_PGUP,   KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,     KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_LBRC, KC_RBRC,               KC_DEL,  KC_END,  KC_PGDN,   KC_P7,  KC_P8,   KC_P9,   KC_PPLS,
    KC_CAPS,       KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,                               KC_P4,  KC_P5,   KC_P6,
    KC_LSFT, KC_NUBS, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,                     KC_UP,              KC_P1,  KC_P2,   KC_P3,   KC_PENT,
    KC_LCTL, MO(_FN),  KC_LALT,                  KC_SPC,                      KC_RALT, KC_RGUI,  KC_APP,   TG(_MS),  KC_LEFT, KC_DOWN, KC_RGHT,      KC_P0,       KC_PDOT),
  [_FN] = LAYOUT_fullsize_iso(
    QK_BOOT,          KC_MYCM, KC_WHOM, KC_MAIL, KC_MSEL,     KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,      KC_VOLU, KC_VOLD, KC_MUTE, KC_CALC,   _______, RGB_MOD, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,        _______, _______, _______,   _______, _______, _______, _______,
    _______,    _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, RGB_M_P, _______, _______,                  _______, _______, _______,   _______, _______, _______, _______,
    _______,       _______, RGB_SAI, _______, _______, _______, RGB_HUI, _______, _______, _______, _______, _______, _______, _______,                                   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,                       RGB_VAI,            _______, _______, _______, _______,
    _______, _______,    _______,                          _______,                          _______,   _______,   _______, _______,         RGB_SPD, RGB_VAD, RGB_SPI,        _______,     QK_RBT),
  [_MS] = LAYOUT_fullsize_iso(
    _______,          _______, _______, _______, _______,     _______, _______, _______, _______,      _______, _______, _______, _______,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,        _______, _______, _______,   KC_BTN1, KC_BTN2, KC_BTN3, _______,
    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______,   KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,
    _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                   KC_MS_L, KC_F13,  KC_MS_R,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,                       _______,            KC_NO,   KC_MS_D, KC_NO,  KC_WH_D,
    _______, _______,   _______,                          _______,                          _______,   _______,   _______, _______,          _______, _______, _______,        KC_BTN1,     _______),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  if (IS_LAYER_ON_STATE(state, _MS))
    writePinHigh(LED_WIN_LOCK_PIN);
  else
    writePinLow(LED_WIN_LOCK_PIN);
  return state;
}
