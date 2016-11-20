#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "bone.h"

#define BASE  0 // default layer
#define SHIFT 1 // shifted base layer
#define DEV   2 // development
#define NAV   3 // navigation

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   j  |   d  |   u  |   a  |   x  | Enter|           |Return|  p  |   h  |   l  |   m  |   w  |   ß    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   c  |   t  |   i  |   e  |   o  |------|           |------|   b  |   n  |   r  |   s  |   g  |   q    |
 * |--------+------+------+------+------+------| DEL  |           | BSP  |------+------+------+------+------+--------|
 * | LShift |   f  |   v  |   ü  |   ä  |   ö  |      |           |      |   y  |   z  |   ,  |   .  |   k  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTRL |      |      |      |      |                                       |      |      |      |      |  CTRLS |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |  FN  |       | ALT   |Ctrl/Esc|
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      | Alt  |       |      |        |      |
 *                                 | [SFT]| [DEV]| ---- |       |------| SPACE  |[SFT] |
 *                                 |      |      | [NAV]|       | [NAV]|        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_ESC,          BONE_1,           BONE_2,     BONE_3,     BONE_4,     BONE_5,   _______,
    KC_TAB,          BONE_J,           BONE_D,     BONE_U,     BONE_A,     BONE_X,   KC_ENT,
    KC_ENT,          BONE_C,           BONE_T,     BONE_I,     BONE_E,     BONE_O,
    KC_LSFT,         BONE_F,           BONE_V,     BONE_UE,    BONE_AE,    BONE_OE,  KC_DELT,
    KC_LCTL,         _______,          _______,    _______,    _______,

                                                                           _______,  KC_LALT,
                                                                                     KC_HOME,
                                                       LT(SHIFT, KC_ENT),  MO(DEV),  MO(NAV),

    // right hand
    BONE_AT,         BONE_6,           BONE_7,      BONE_8,    BONE_9,     BONE_0,   _______,
    KC_ENT,          BONE_P,           BONE_H,      BONE_L,    BONE_M,     BONE_W,   BONE_SS,
                     BONE_B,           BONE_N,      BONE_R,    BONE_S,     BONE_G,   BONE_Q,
    KC_BSPC,         BONE_Y,           BONE_Z,      BONE_COMM, BONE_DOT,   BONE_K,   KC_RSFT,
                                       _______,     _______,   _______,    _______,  KC_RCTL,
    KC_RALT, CTL_T(KC_ESC),
    KC_PGUP,
    MO(NAV), MO(DEV), LT(SHIFT, KC_SPC)
),
/* Keymap 1: Shifted Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   J  |   D  |   U  |   A  |   X  |      |           |      |   P  |   H  |   L  |   M  |   W  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   C  |   T  |   I  |   E  |   O  |------|           |------|   B  |   N  |   R  |   S  |   G  |   Q    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   F  |   V  |   Ü  |   Ä  |   Ö  |      |           |      |   Y  |   Z  |      |      |   K  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |       |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |       |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// SYMBOLS
[SHIFT] = LAYOUT_ergodox(
    // layer 1 : reserved for now, possibly turned into a shifted layer to work around normal shift shortcommings

    // left hand
    _______,          _______,           _______,     _______,     _______,     _______,     _______,
    _______,          S(BONE_J),         S(BONE_D),   S(BONE_U),   S(BONE_A),   S(BONE_X),   _______,
    _______,          S(BONE_C),         S(BONE_T),   S(BONE_I),   S(BONE_E),   S(BONE_O),
    _______,          S(BONE_F),         S(BONE_V),   S(BONE_UE),  S(BONE_AE),  S(BONE_OE),  _______,
    _______,          _______,           _______,     _______,     _______,

                                                                                   _______,  _______,
                                                                                             _______,
                                                                         _______,  _______,  _______,

    // right hand
    _______,           _______,           _______,      _______,    _______,     _______,    _______,
    _______,           S(BONE_P),         S(BONE_H),    S(BONE_L),  S(BONE_M),   S(BONE_W),  _______,
                       S(BONE_B),         S(BONE_N),    S(BONE_R),  S(BONE_S),   S(BONE_G),  S(BONE_Q),
    _______,           S(BONE_Y),         S(BONE_Z),    BONE_COMM,  BONE_DOT,    S(BONE_K),  _______,
                                          _______,      _______,    _______,     _______,    _______,
    _______, _______,
    _______,
    _______, _______, _______
),

[DEV] = LAYOUT_ergodox(  // layer 2 : programming symbols
        // left hand
        _______,         BONE_1,           BONE_2,     BONE_3,     BONE_4,     BONE_5,        _______,
        KC_TAB,          BONE_EURO,        BONE_UNDER, BONE_LBRC,  BONE_RBRC,  BONE_AC_CIRC,  KC_DELT,
        _______,         BOME_BSLSH,       BONE_SLASH, BONE_LCBR,  BONE_RCBR,  KC_PAST,
        KC_LSFT,         BONE_HASH,        BONE_DOLLAR,BONE_VERTL, BONE_TILDE, BONE_AC_GRAV,  KC_ENT,
        KC_LCTL,         _______,          _______,    _______,    _______,

                                                                                   _______, KC_LALT,
                                                                                            KC_HOME,
                                                                          _______, _______, _______,

        // right hand
        _______,         BONE_6,           BONE_7,      BONE_8,    BONE_9,           BONE_0,      RESET,
        KC_BSPC,         BONE_EXCL,        BONE_LT,     BONE_GT,   BONE_EQ,          BONE_AMP,    _______,
                         BONE_QUEST,       BONE_LB,     BONE_RB,   BONE_MINUS,       BONE_DPOINT, _______,
        KC_ENT,          BONE_PLUS,        BONE_PERCENT,BONE_QUOTES, BONE_SQUOTE,    BONE_SEMIC,  KC_RSFT,
                                           _______,     _______,     _______,       _______,      KC_RCTL,
        KC_RALT, CTL_T(KC_ESC),
        KC_PGUP,
        _______, _______, _______
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | RESET  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NAV] = LAYOUT_ergodox(  // layer 3 : navigation keys
        // left hand
     _______,   _______,          _______,    _______,    _______,   _______,  _______,
     _______,   _______,             KC_BTN1,  KC_MS_U,  KC_BTN2, _______,_______,
     _______,   _______,             KC_MS_L,  KC_MS_D,  KC_MS_R, _______,
     KC_LSFT,   _______,        _______,    _______,    _______,   _______,  _______,
     _______,   _______,          _______,    _______,    _______,

                                                        _______,  _______,
                                                                _______,
                                                 _______,    KC_TRNS,   KC_TRNS,

        // right hand
     _______,   _______,          _______,    _______,    _______,   _______,     RESET,
     _______,   _______,             KC_PGDN,  KC_UP,    KC_PGUP, _______,_______,
              _______,             KC_LEFT,  KC_DOWN,  KC_RGHT, _______,_______,
     _______,   _______,          _______,       KC_HOME,  KC_END,  _______,   KC_RSFT,
                              _______,    _______,    _______,   _______,  _______,
     _______,   _______,
     _______,
        KC_TRNS, KC_TRNS,  KC_TRNS
)
};

const uint16_t PROGMEM fn_actions[] = {
//[1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
case 0:
  if (record->event.pressed) {
    SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
  }
  break;
case 1:
  if (record->event.pressed) { // For resetting EEPROM
    eeconfig_init();
  }
  break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
// dynamically generate these.
case EPRM:
  if (record->event.pressed) {
    eeconfig_init();
  }
  return false;
  break;
case VRSN:
  if (record->event.pressed) {
    SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
  }
  return false;
  break;
case RGB_SLD:
  if (record->event.pressed) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_mode(1);
    #endif
  }
  return false;
  break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
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
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
    #endif
    break;
  default:
    break;
}

  return state;
};
