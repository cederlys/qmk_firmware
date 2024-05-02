#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FX,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │     │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ Ent│
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ # │    │
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
     * │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │Ctrl│Fn  │Alt │                        │ Alt│GUI │Menu│Ctrl│
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
    [_BASE] = LAYOUT_60_iso(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL, MO(_FN), KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI,  KC_APP,  TG(_FX)
    ),
    [_FX] = LAYOUT_60_iso(
      _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______, KC_PGUP,
      _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, KC_PGDN, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,   _______, _______, KC_UP,            _______,
      _______, _______, _______,                            _______,                            KC_LEFT, KC_DOWN, KC_RGHT, _______
    ),
    [_FN] = LAYOUT_60_iso(
      QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_VOLU, KC_VOLD, KC_F11,  KC_F12,  KC_DEL,
      _______, _______, _______, KC_END,  _______, _______, _______, _______, KC_INS,  _______, KC_PAUS, _______, _______,
      _______, _______, _______, _______, _______, _______, KC_HOME, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
      _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
};

static int offset = 0;

#define TWEAK(i) (offset > 16 ? (i) : 0)

#define CEDER_SET(i, r, g, b) if (led_min <= i && i < led_max) RGB_MATRIX_INDICATOR_SET_COLOR(i, TWEAK(r), TWEAK(g), TWEAK(b))

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  offset = (g_rgb_timer / 12) % 64;

  if (IS_LAYER_ON(_FN))
    {
      CEDER_SET(0, 255, 0, 0);	   /* QK_BOOT */
      CEDER_SET(1, 128, 128, 128); /* KC_F1 */
      CEDER_SET(2, 128, 128, 128); /* KC_F2 */
      CEDER_SET(3, 128, 128, 128); /* KC_F3 */
      CEDER_SET(4, 128, 128, 128); /* KC_F4 */

      CEDER_SET(5, 96, 96, 0);	/* KC_MPRV */
      CEDER_SET(6, 96, 96, 0);	/* KC_MNXT */
      CEDER_SET(7, 64, 255, 0); /* KC_MPLY */
      CEDER_SET(8, 64, 0, 0);	/* KC_MSTP */

      CEDER_SET(9, 255, 0, 0);	/* KC_VOLU */
      CEDER_SET(10, 0, 255, 0);	/* KC_VOLD */

      CEDER_SET(11, 128, 128, 128); /* KC_F11 */
      CEDER_SET(12, 128, 128, 128); /* KC_F11 */
      CEDER_SET(13, 255, 128, 128); /* KC_DEL */

      CEDER_SET(17, 255, 128, 128); /* KC_END */
      CEDER_SET(22, 255, 128, 128); /* KC_INS */
      CEDER_SET(24, 255, 0, 0);	    /* KC_PAUS */

      CEDER_SET(33, 255, 128, 128); /* KC_HOME */
    }
  else if (IS_LAYER_ON(_FX))
    {
      /* Since _FN overrides _FX, this block only contains keys that
	 are bound in both the _FN and _FX layer. If _FN is active, it
	 overrides the things set here. */
      CEDER_SET(7, 200, 200, 200);  /* KC_P7 */
      CEDER_SET(8, 200, 200, 200);  /* KC_P8 */
      CEDER_SET(9, 200, 200, 200);  /* KC_P9 */
      CEDER_SET(22, 200, 200, 200); /* KC_P5 */
    }

  if (IS_LAYER_ON(_FX))
    {
      CEDER_SET(21, 200, 200, 200); /* KC_P4 */
      CEDER_SET(23, 200, 200, 200); /* KC_P6 */
      CEDER_SET(34, 200, 200, 200); /* KC_P1 */
      CEDER_SET(35, 200, 200, 200); /* KC_P2 */
      CEDER_SET(36, 200, 200, 200); /* KC_P3 */
      CEDER_SET(49, 200, 200, 200); /* KC_P0 */

      CEDER_SET(26, 0, 255, 255); /* KC_PGUP */
      CEDER_SET(39, 0, 255, 255); /* KC_PGDN */

      CEDER_SET(52, 255, 0, 0);	/* KC_UP */
      CEDER_SET(58, 255, 0, 0);	/* KC_LEFT */
      CEDER_SET(59, 255, 0, 0);	/* KC_DOWN */
      CEDER_SET(60, 255, 0, 0);	/* KC_RGHT */
    }

  return false;
}
