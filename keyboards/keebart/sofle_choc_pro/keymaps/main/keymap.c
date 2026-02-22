// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,   
    _BASE_WIN,
    _MDIA,   
    _SYMBOLS,  
    _NVIM,   
};
enum custom_keycodes {
    SFT_LS = SAFE_RANGE,
    TOGGLE_OS,
    NUM_1,
    NUM_2,
    NUM_3,
    NUM_4,
    NUM_5,
    NUM_6,
    NUM_7,
    NUM_8,
    NUM_9,
    NUM_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE (With symbols on number row)
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                     |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                     |   Y  |   U  |   I  |   O  |   P  | BSPC |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | LCTL |   A  |   S  |   D  |   F  |   G  |-------.    ,--------|   H  |   J  |   K  |   L  |   ;  |  ENT |
 * |------+------+------+------+------+------|  Mute |    | Pause  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |--------|   N  |   M  |   ,  |   .  |   /  |    ' |
 * `-----------------------------------------/       /     \       \-----------------------------------------'
 *          |      |      | LALT   | LCMD   / Space /       \MO_NVI \  EMT  | DEL  |      |       |
 *          |      |      |        |       /       /         \       \      |      |      |       |
 *          `-------------------------------------'           '---------------------------------'
 */

[_BASE] = LAYOUT_split_4x6_5(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,     KC_7,     KC_8,    KC_9,    KC_0,   KC_GRV,
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_ENT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE, KC_MPLY,  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_QUOT,
            _______, _______,  KC_LALT, KC_LCMD,  KC_SPC,          MO(_NVIM), KC_LCMD,   KC_DEL, _______, MO(_SYMBOLS)
),

[_BASE_WIN] = LAYOUT_split_4x6_5(
     KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,     KC_7,     KC_8,    KC_9,    KC_0,   KC_GRV,
    KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
   KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_ENT,
   KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE, KC_MPLY,  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT,
            KC_LGUI, _______, KC_LALT, KC_LCTL, KC_SPC,                 MO(_NVIM), KC_LCTL, KC_DEL, _______, MO(_SYMBOLS)
),

/*kk
 * MEDIA Layer - Controls, RGB, and media&
 */
[_MDIA] = LAYOUT_split_4x6_5(
    KC_MUTE, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_MUTE,
    RM_TOGG, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, RM_TOGG,
    RM_NEXT, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, RM_NEXT,
    RM_HUEU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_HUEU,
             _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______
),

/*
 * _SYMBOLS Layer - Numbers on top row (activated by holding LShift)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   -  |   =  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  [   |  ]   |  {   |  }   |  (   |  )   |                    |  _   |  -   |  [   |  ]   |  \   |      |   
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |   :  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |   <  |   >  |   ?  |   "  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMBOLS] = LAYOUT_split_4x6_5(
    _______, KC_EXLM,   KC_AT, KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL, _______,
    KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN,                    KC_UNDS, KC_MINS, KC_LBRC, KC_RBRC, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, KC_PIPE, KC_COLN, _______,
    _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, KC_LT,   KC_GT, KC_QUES, KC_DQUO,
             _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______
),
/*
 * NVIM Navigation Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   -  |  =   |   [  |   ]  |   \  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  CUT |  CPY | VSP  |      |-------|    |-------| HOME |PgDown| PgUp | END  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NVIM] = LAYOUT_split_4x6_5(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                    KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
      _______, _______, _______, _______, _______, _______,                   KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______,
      _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
      _______, _______, KC_X,    KC_C,    _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
                 MO(_MDIA), _______, _______, _______, _______,             _______, _______, TOGGLE_OS, _______, MO(_MDIA)
)
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case SFT_LS:
        //     if (record->event.pressed) {
        //         layer_on(_SYMBOLS);
        //         register_code(KC_LSFT);
        //     } else {
        //         layer_off(_SYMBOLS);
        //         unregister_code(KC_LSFT);
        //     }
        //     return false;

        case TOGGLE_OS:
            if (record->event.pressed) {
                if (layer_state_is(_BASE)) {
                    layer_move(_BASE_WIN);
                } else {
                    layer_move(_BASE);
                }
            }
            return false;

        // Numbers - temporarily release shift
        case NUM_1 ... NUM_0:
            if (record->event.pressed) {
                unregister_code(KC_LSFT);  // release shift
                tap_code(keycode - NUM_1 + KC_1);  // tap the correct number
                register_code(KC_LSFT);    // restore shift
            }
            return false;
    }
    return true;
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_BASE_WIN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_MDIA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_SYMBOLS] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_NVIM] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) }
};
#endif