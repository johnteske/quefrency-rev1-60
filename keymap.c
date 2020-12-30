#include QMK_KEYBOARD_H

#define _BASE 0
#define _FN1 1

#ifdef RGBLIGHT_ENABLE
#    define HSV_AMBER 32, 218, 255
#endif

#ifdef AUDIO_ENABLE
#    define _LL_AUDIO 2
#endif

#define CTL_ESC LCTL_T(KC_ESC)
#define SFT_SLS RSFT_T(KC_SLSH)

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  SFT_SLS, KC_UP,   _______, \
    MO(_FN1),KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,           KC_SPC,  _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT(
    KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, \
    RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    AU_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  )
};
/* clang-format on */

#ifdef RGBLIGHT_LAYERS
/* ============
 * Light layers
 * ============ */

// Define light layers
const rgblight_segment_t PROGMEM light_layer_base[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_WHITE});
const rgblight_segment_t PROGMEM light_layer_fn1[]  = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_WHITE});
#    ifdef AUDIO_ENABLE
const rgblight_segment_t PROGMEM light_layer_audio[] = RGBLIGHT_LAYER_SEGMENTS({7, 1, HSV_AMBER});
#    endif

const rgblight_segment_t* const PROGMEM light_layers[] = RGBLIGHT_LAYERS_LIST(light_layer_base, light_layer_fn1,
#    ifdef AUDIO_ENABLE
                                                                              light_layer_audio
#    endif
);

// Set light layer on layer change
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_BASE, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(_FN1, layer_state_cmp(state, _FN1));
    return state;
}

#    ifdef AUDIO_ENABLE
// Helper to set audio indicator light layer
void set_audio_light_layer(void) { rgblight_set_layer_state(_LL_AUDIO, is_audio_on()); }
#    endif

void keyboard_post_init_user(void) {
    rgblight_layers = light_layers;

    // Set initial light layers
    rgblight_set_layer_state(_BASE, true);
#    ifdef AUDIO_ENABLE
    set_audio_light_layer();
#    endif
}

#    ifdef AUDIO_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case AU_TOG:
            // Set audio light layer on keyup
            if (!record->event.pressed) {
                set_audio_light_layer();
            }
            break;
    }
    return true;
}
#    endif
#endif
