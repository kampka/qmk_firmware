#include QMK_KEYBOARD_H
#include "version.h"

#define XXXXXXX KC_NO

/*
 * TODO Introduction
 */

/* Layers
 *
 * This layout defines the same set of layers against multiple software keyboard variants 
 * (aka. the keyboard layout set on your OS)
 *  
 * For the moment, the following three layouts are supported
 *  * ISO - The ISO QUERTZ keyboard 
 *  * BONE - The BONE keyboard as defined in xbd
 *
 * For each layout, a set of layers is defined, starting with layer one
 *  1 - Basic Character layer
 *  2 - Shifted Character layer
 *  3 - Programming Character layer
 *  4 - Numpad / Navigation layer
 *  5 - Misc
 *
 */

// ISO LAYER
#define ISO_1 0 
#define ISO_2 1
#define ISO_3 2
#define ISO_4 3
#define ISO_5 4

// BONE LAYER
#define BONE_1 5
#define BONE_2 6
#define BONE_3 7
#define BONE_4 9
#define BONE_5 10

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ISO Layer 1: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    | F1   | F2   | F3   | F4   | F5   | F6   |           | F7   | F8   | F9   | F10  | F11  | F12  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   j  |   d  |   u  |   a  |   x  |      |           | ENTR |   p  |   h  |   l  |   m  |   w  |   ß    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   c  |   t  |   i  |   e  |   o  |------|           |------|   b  |   n  |   r  |   s  |   g  |   q    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCTRL  |   f  |   v  |   ü  |   ä  |   ö  |      |           |      |   y  |   z  |   ,  |   .  |   k  | RCTRL  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |Super |       | C+A  |       |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      |      |       |      |       |      |
 *                                 | L2   | L3   |------|       |------| L4    |Space |
 *                                 |      |      | ALT  |       | ALTG |       |      |
 *                                 `--------------------'       `---------------------'
 */
[ISO_1] = LAYOUT_ergodox(
  // left hand
  KC_ESC ,         KC_F1,       KC_F2,         KC_F3,   KC_F4,   KC_F5,   KC_F6,
  KC_TAB ,         KC_J,        KC_D,          KC_U,    KC_A,    KC_X,    XXXXXXX,
  XXXXXXX,         KC_C,        KC_T,          KC_I,    KC_E,    KC_O,
  KC_LCTRL,        KC_F,        KC_V,          KC_LBRC, KC_QUOT, KC_SCLN, XXXXXXX,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, KC_LCMD, 
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                    MO(ISO_2), MO(ISO_3), KC_LALT,
  // right hand
  KC_F7,        KC_F8,       KC_F9,       KC_F10,      KC_F11,   KC_F12,   XXXXXXX,
  KC_ENT,       KC_P,        KC_H,        KC_L,        KC_M,     KC_W,     KC_MINS,
                KC_B,        KC_N,        KC_R,        KC_S,     KC_G,     KC_Q,
  XXXXXXX,      KC_Z,        KC_Y,        KC_COMM,     KC_DOT,   KC_K,     KC_RCTRL,
                             KC_RCMD,     XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,
  LCTL(KC_LALT), XXXXXXX,
  XXXXXXX,
  KC_ALGR,  MO(ISO_4), KC_SPC
),
/* ISO Layer 2: Shifted layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | F1   | F2   | F3   | F4   | F5   | F6   |           | F7   | F8   | F9   | F10  | F11  | F12  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   J  |   D  |   U  |   A  |   X  |      |           | ENTR |   P  |   H  |   L  |   M  |   W  |   €    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   C  |   T  |   I  |   E  |   O  |------|           |------|   B  |   N  |   R  |   S  |   G  |   Q    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | S/LCTRL|   F  |   V  |   Ü  |   Ä  |   Ö  |      |           |      |   Y  |   Z  |   ,  |   .  |   K  |S/RCTRL |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |       |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      |      |       |      |       |      |
 *                                 | L3   |      |------|       |------| SPACE | L4   |
 *                                 |      |      |      |       |      |       |      |
 *                                 `--------------------'       `---------------------'
 */
[ISO_2] = LAYOUT_ergodox(
  // left hand
  _______,            _______,     _______,       _______,    _______,    _______,    _______,
  XXXXXXX,            S(KC_J),     S(KC_D),       S(KC_U),    S(KC_A),    S(KC_X),    XXXXXXX,
  XXXXXXX,            S(KC_C),     S(KC_T),       S(KC_I),    S(KC_E),    S(KC_O),
  S(KC_LCTRL),        S(KC_F),     S(KC_V),       S(KC_LBRC), S(KC_QUOT), S(KC_SCLN), XXXXXXX,
  XXXXXXX,            XXXXXXX,     XXXXXXX,       XXXXXXX,    _______, 
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                      MO(ISO_3), XXXXXXX, _______,
  // right hand
  _______,      _______,     _______,     _______,     _______,  _______,  _______,
  XXXXXXX,      S(KC_P),     S(KC_H),     S(KC_L),     S(KC_M),  S(KC_W),  RALT(KC_E),
                S(KC_B),     S(KC_N),     S(KC_R),     S(KC_S),  S(KC_G),  S(KC_Q),
  XXXXXXX,      S(KC_Z),     S(KC_Y),     KC_COMM,     KC_DOT,   S(KC_K),  S(KC_RCTRL),
                             _______,     XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  _______, _______, MO(ISO_4)
),
/* ISO Layer 3: Programming Characters
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         | F1   | F2   | F3   | F4   | F5   | F6   |           | F7   | F8   | F9   | F10  | F11  | F12  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  @   |  _   |  [   |  ]   |  ^   |      |           | ENTR |  !   |  <   |  >   |  =   |  &   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  \   |  /   |  {   |  }   |  *   |------|           |------|  ?   |  (   |  )   |  -   |  :   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  #   |  $   |  |   |  ~   |  `   |      |           |      |  +   |  %   |  "   |  '   |  ;   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | CAD  |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ISO_3] = LAYOUT_ergodox(
  // left hand
  _______,     _______,       _______,     _______,               _______,           _______,        _______,
  XXXXXXX,     RALT(KC_Q),    S(KC_SLASH), RALT(KC_8),            RALT(KC_9),        KC_GRAVE,       XXXXXXX,
  XXXXXXX,     RALT(KC_MINS), S(KC_7),     RALT(KC_7),            RALT(KC_0),        S(KC_RBRACKET),
  KC_LCTRL,    KC_NONUS_HASH, S(KC_4),     RALT(KC_NONUS_BSLASH), RALT(KC_RBRACKET), S(KC_EQUAL),    XXXXXXX,
  XXXXXXX,     XXXXXXX,       XXXXXXX,     XXXXXXX,               _______, 
                                                                                       XXXXXXX, XXXXXXX,
                                                                                                XXXXXXX,
                                                                              XXXXXXX, _______, _______,
  // right hand
  _______,      _______,      _______,         _______,            _______,          _______,      _______,
  XXXXXXX,      S(KC_1),      KC_NONUS_BSLASH, S(KC_NONUS_BSLASH), S(KC_0),          S(KC_6),      XXXXXXX,
                S(KC_MINS),   S(KC_8),         S(KC_9),            KC_SLASH,         S(KC_DOT),    XXXXXXX,
  XXXXXXX,      KC_RBRACKET,  S(KC_5),         S(KC_2),            S(KC_NONUS_HASH), S(KC_COMM),   KC_RCTRL,
                              _______,         XXXXXXX,            XXXXXXX,          XXXXXXX,      XXXXXXX,
  LCTL(LALT(KC_DEL)), XXXXXXX,
  XXXXXXX,
  _______, _______, _______
),
/* ISO Layer 4: Navigation
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         | F1   | F2   | F3   | F4   | F5   | F6   |           | F7   | F8   | F9   | F10  | F11  | F12  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         | PgUp |  BSP |  Up  | DEL  |PgDwn |      |           | ENTR |      |  7   |  8   |  9   |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | HOME | LEFT | DOWN | RGHT | ESC  |------|           |------|      |  4   |  5   |  6   |  .   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | END  | TAB  |      |  ENT |      |      |           |      |  0   |  1   |  2   |  3   |  ,   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ISO_4] = LAYOUT_ergodox(
  // left hand
  _______,     _______,       _______,     _______,     _______,      _______,      _______,
  XXXXXXX,     KC_PGUP,       KC_BSPC,     KC_UP,       KC_DEL,       KC_PGDN,      XXXXXXX,  
  XXXXXXX,     KC_HOME,       KC_LEFT,     KC_DOWN,     KC_RGHT,      KC_ESC,
  KC_LCTRL,    KC_END,        KC_TAB,      XXXXXXX,     KC_ENT,       XXXXXXX,      XXXXXXX,
  XXXXXXX,     XXXXXXX,       XXXXXXX,     XXXXXXX,     _______, 
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                        XXXXXXX, XXXXXXX, _______,
  // right hand
  _______,      _______,     _______,     _______,     _______,       _______,      _______,
  _______,      XXXXXXX,     KC_7,        KC_8,        KC_9,          XXXXXXX,      XXXXXXX,
                XXXXXXX,     KC_4,        KC_5,        KC_6,          KC_DOT,       XXXXXXX,
  XXXXXXX,      KC_0,        KC_1,        KC_2,        KC_3,          KC_COMM,      KC_RCTRL,
                             _______,     XXXXXXX,     XXXXXXX,       XXXXXXX,      XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
