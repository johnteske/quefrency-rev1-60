#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _FN1 1

#define ____ _______
#define CTRL_ESC LCTL_T(KC_ESC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_GRV,   KC_1,    KC_2,    KC_3,     KC_4,   KC_5,  KC_6,   KC_7,   KC_8,      KC_9,     KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, \
    KC_TAB,   KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,  KC_Y,   KC_U,   KC_I,      KC_O,     KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    CTRL_ESC, KC_A,    KC_S,    KC_D,     KC_F,   KC_G,  KC_H,   KC_J,   KC_K,      KC_L,     KC_SCLN, KC_QUOT, KC_ENT,  \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,  KC_N,   KC_M,   KC_COMM,   KC_DOT,   KC_SLSH, KC_UP,   MO(_FN1), \
    KC_LEAD,  KC_LCTL, KC_LALT, KC_LGUI,  KC_SPC,        KC_SPC, KC_SPC, TO(_BASE), TO(_FN1), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT(
    KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,  KC_F7,  KC_F8,     KC_F9,    KC_F10,  KC_F11,  KC_F12,  ____,    ____, \
    ____,     ____,    ____,    ____,    ____,    ____,  ____,   ____,   ____,       ____,    ____,    ____,    ____,    ____,    \
    ____,     ____,    ____,    ____,    ____,    ____,  KC_LEFT,KC_DOWN,KC_UP,     KC_RGHT,  ____,    ____,    ____,    \
    ____,     ____,    ____,    ____,    ____,    ____,  ____,   ____,   ____,      ____,     ____,    ____,    KC_TRNS, \
    KC_TRNS,  ____,    ____,    ____,    ____,           ____,   ____,   KC_TRNS,   KC_TRNS,  ____,    ____,    ____
  ),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_Q) {
      register_code(KC_LCTRL);
      register_code(KC_LALT);
      register_code(KC_Q);
      unregister_code(KC_Q);
      unregister_code(KC_LALT);
      unregister_code(KC_LGUI);
    }
  }
}
