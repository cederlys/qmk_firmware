/*
Copyright 2019 Stephen Peery
Copyright 2023 Per Cederqvist

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

#define LED_WIN_LOCK_PIN   D6

void keyboard_pre_init_user(void)
{
  setPinOutput(LED_WIN_LOCK_PIN);
}

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _FN,
    _MS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC,       KC_F1, KC_F2, KC_F3, KC_F4,    KC_F5, KC_F6, KC_F7, KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_PSCR, KC_SCRL, KC_PAUS,
    KC_GRV, KC_1, KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0, KC_MINS, KC_EQL,     KC_BSPC,        KC_INS,  KC_HOME, KC_PGUP,   KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,     KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_LBRC, KC_RBRC,               KC_DEL,  KC_END,  KC_PGDN,   KC_P7,  KC_P8,   KC_P9,   KC_PPLS,
    KC_CAPS,       KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,                               KC_P4,  KC_P5,   KC_P6,
    KC_LSFT, KC_NUBS, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,                     KC_UP,              KC_P1,  KC_P2,   KC_P3,   KC_PENT,
    KC_LCTL, MO(_FN),  KC_LALT,                  KC_SPC,                      KC_RALT, KC_RGUI,  KC_APP,   TG(_MS),  KC_LEFT, KC_DOWN, KC_RIGHT,      KC_P0,       KC_PDOT),
  [_FN] = LAYOUT(
    RESET,            KC_MYCM, KC_WHOM, KC_MAIL, KC_MSEL,     KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,      KC_VOLU, KC_VOLD, KC_MUTE, KC_CALC,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,        _______, _______, _______,   _______, _______, _______, _______,
    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______,   _______, _______, _______, _______,
    _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,                       _______,            _______, _______, _______, _______,
    _______, _______,    _______,                          _______,                          _______,   _______,   _______, _______,          _______, _______, _______,        _______,     _______),
  [_MS] = LAYOUT(
    _______,          _______, _______, _______, _______,     _______, _______, _______, _______,      _______, _______, _______, _______,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,        _______, _______, _______,   KC_BTN1, KC_BTN2, KC_BTN3, _______,
    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______,   KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,
    _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                   KC_MS_L, KC_NO,   KC_MS_R,
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
