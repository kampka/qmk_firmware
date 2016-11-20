#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_extras/keymap_bone_ck.h"



#define ____ KC_NO

// Layer names
#define BASE 0 // default layer
#define RESERVED 1
#define SYMBOLS 2
#define NAVIGATION 3


// Gobal key tap timer for this layout
//static uint16_t key_timer;

// Makros

#define M_SPACE_RSHIFT 1
#define M_RETURN_LSHIFT 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  | RESET  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   J  |   D  |   U  |   A  |   X  |  DEL |           | bsp  |   P  |   H  |   L  |   M  |   W  |   ß    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   C  |   T  |   I  |   E  |   O  |------|           |------|   B  |   N  |   R  |   S  |   G  |   Q    |
 * |--------+------+------+------+------+------| Enter|           |Return|------+------+------+------+------+--------|
 * | LShift |   F  |   V  |   Ü  |   Ä  |   Ö  |      |           |      |   Y  |   Z  |   ,  |   .  |   K  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTRL |      |      |      |      |                                       |      |      |      |      |  CTRLS |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | Alt  |       | Alt  |Ctrl/Esc|
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      | Mod3 |------|       |------|        |Space |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,          BONE_1,           BONE_2,     BONE_3,     BONE_4,     BONE_5,   ____,
        KC_TAB,          BONE_J,           BONE_D,     BONE_U,     BONE_A,     BONE_X,   KC_DELT,
        ____,            BONE_C,           BONE_T,     BONE_I,     BONE_E,     BONE_O,
        KC_LSFT,         BONE_F,           BONE_V,     BONE_UE,    BONE_AE,    BONE_OE,  KC_ENT,
        KC_LCTL,         ____,             ____,       ____,       ____,

                                                                                  ____, KC_LALT,
                                                                                        KC_HOME,
                                                            SFT_T(KC_ENT), MO(SYMBOLS), MO(NAVIGATION),

        // right hand
        BONE_AT,         BONE_6,           BONE_7,      BONE_8,    BONE_9,     BONE_0,   RESET,
        KC_BSPC,         BONE_P,           BONE_H,      BONE_L,    BONE_M,     BONE_W,   BONE_SS,
                         BONE_B,           BONE_N,      BONE_R,    BONE_S,     BONE_G,   BONE_Q,
        KC_ENT,          BONE_Y,           BONE_Z,      BONE_COMM, BONE_DOT,   BONE_K,   KC_RSFT,
                                           ____,        ____,      ____,       ____,    KC_RCTL,
        KC_RALT, CTL_T(KC_ESC),
        KC_PGUP,
        MO(NAVIGATION), MO(SYMBOLS), SFT_T(KC_SPC)
    )
, [RESERVED] = KEYMAP(
        // layer 1 : reserved for now, possibly turned into a shifted layer to work around normal shift shortcommings

        // left hand
        KC_TRNS,          KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,          KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,          KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,          KC_TRNS,           KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_LCTL,          ____,              ____,        ____,        ____,

                                                                                     KC_TRNS, KC_TRNS,
                                                                                              KC_TRNS,
                                                                           	KC_TRNS, KC_TRNS, KC_TRNS,

        // right hand
        KC_TRNS,           KC_TRNS,           KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,           KC_TRNS,           KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
                           KC_TRNS,           KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS,           KC_TRNS,           KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
                                              KC_TRNS,      KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    )
, [SYMBOLS] = KEYMAP(  // layer 2 : programming symbols
        // left hand
        KC_TRNS,         BONE_1,           BONE_2,     BONE_3,     BONE_4,     BONE_5,        ____,
        KC_TAB,          BONE_EURO,        BONE_UNDER, BONE_LBRC,  BONE_RBRC,  BONE_AC_CIRC,  KC_DELT,
        ____,            BOME_BSLSH,       BONE_SLASH, BONE_LCBR,  BONE_RCBR,  KC_PAST,
        KC_LSFT,         BONE_HASH,        BONE_DOLLAR,BONE_VERTL, BONE_TILDE, BONE_AC_GRAV,  KC_ENT,
        KC_LCTL,         ____,             ____,       ____,       ____,

                                                                                     ____,  KC_LALT,
                                                                                            KC_HOME,
                                                                          KC_TRNS, KC_TRNS, KC_TRNS,

        // right hand
        ____,            BONE_6,           BONE_7,      BONE_8,    BONE_9,     		BONE_0,      RESET,
        KC_BSPC,         BONE_EXCL,        BONE_LT,     BONE_GT,   BONE_EQ,    		BONE_AMP, 	 KC_TRNS,
                         BONE_QUEST,       BONE_LB,     BONE_RB,   BONE_MINUS, 		BONE_DPOINT, KC_TRNS,
        KC_ENT,          BONE_PLUS,        BONE_PERCENT,BONE_QUOTES, BONE_SQUOTE, BONE_SEMIC,  KC_RSFT,
                                           ____,        ____,        ____,        ____,        KC_RCTL,
        KC_RALT, CTL_T(KC_ESC),
        KC_PGUP,
        KC_TRNS, KC_TRNS, KC_TRNS
    )
, [NAVIGATION] = KEYMAP(  // layer 3 : navigation keys
        // left hand
        ____,    ____,           ____,     ____,     ____,    ____,   ____,
        ____,    ____,           KC_BTN1,  KC_MS_U,  KC_BTN2, ____,   ____,
        ____,    ____,           KC_MS_L,  KC_MS_D,  KC_MS_R, ____,
        KC_LSFT, ____,           ____,     ____,     ____,    ____,   ____,
        ____,    ____,           ____,     ____,     ____,

                                                           ____,   ____,
                                                                   ____,
                                                    ____,  KC_TRNS,   KC_TRNS,

        // right hand
        ____,    ____,           ____,     ____,     ____,    ____,   RESET,
        ____,    ____,           KC_PGDN,  KC_UP,    KC_PGUP, ____,   ____,
                 ____,           KC_LEFT,  KC_DOWN,  KC_RGHT, ____,   ____,
        ____,    ____,           ____,     KC_HOME,  KC_END,  ____,   KC_RSFT,
                                 ____,     ____,     ____,    ____,   ____,
        ____,    ____,
        ____,
        KC_TRNS, KC_TRNS,  KC_TRNS
    )

};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    // LED order
    //  1 - left
    //  2 - middle
    //  3 - right

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
        case 1:
            ergodox_right_led_3_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            ergodox_right_led_2_on();
            break;
        case 4:
            ergodox_right_led_3_on();
            break;
        case 5:
            ergodox_right_led_3_on();
            ergodox_right_led_1_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_1_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            ergodox_board_led_off();
            break;
    }

};
