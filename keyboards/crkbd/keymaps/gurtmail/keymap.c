/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>
#include "keymap_swedish.h"

#define _COLEMAK 0
#define _QUERTY 1
#define _SWE 2
#define _GAME 3
#define _GAME2 4
#define _NAV 5
#define _MOUSE 6
#define _BUTTON 7
#define _MEDIA 8
#define _NUM 9
#define _SYM 10
#define _FUN 11


const uint16_t PROGMEM esc_combo[] = { KC_Q, KC_W, COMBO_END };
const uint16_t PROGMEM del_combo[] = { KC_Y, KC_NUHS, COMBO_END };
const uint16_t PROGMEM swe_combo1[] = { KC_W, KC_F, COMBO_END };
const uint16_t PROGMEM swe_combo2[] = { KC_F, KC_P, COMBO_END };
const uint16_t PROGMEM swe_combo3[] = { KC_U, KC_Y, COMBO_END };
combo_t key_combos[COMBO_COUNT] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(del_combo, KC_DEL),
    COMBO(swe_combo1, KC_LBRC),
    COMBO(swe_combo2, KC_QUOT),
    COMBO(swe_combo3, KC_SCLN),
};

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           U_NA,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,  KC_Y,  KC_NUHS,  U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          U_NA,LGUI_T(KC_A),LALT_T(KC_R),LCTL_T(KC_S),LSFT_T(KC_T),KC_G,         KC_M,   LSFT_T(KC_N),LCTL_T(KC_E),LALT_T(KC_I),LGUI_T(KC_O), U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         U_NA,LT(_BUTTON, KC_Z),KC_X, KC_C, KC_D, LT(_MEDIA, KC_V),                               LT(_FUN, KC_K),  KC_H,  KC_COMM,   ALGR_T(KC_DOT),LT(_BUTTON,KC_SLSH), U_NA,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
             U_NA,   LT(_NAV,KC_SPC),  LT(_MOUSE,KC_TAB),     LT(_SYM,KC_ENT),   LT(_NUM, KC_BSPC), U_NA
      //`--------------------------'  `--------------------------'

),

[_QUERTY] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         U_NA,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,  KC_O,  KC_P,  U_NA,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        U_NA,LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G,         KC_H,   LSFT_T(KC_J),LCTL_T(KC_K),LALT_T(KC_L),LGUI_T(KC_SCLN), U_NA,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        U_NA, KC_Z,   ALGR_T(KC_X), KC_C, KC_V, LT(_FUN, KC_B),                  LT(_FUN, KC_N),    KC_M,    KC_COMM,ALGR_T(KC_DOT),KC_SLSH, U_NA,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            U_NA,   LT(_NAV,KC_SPC),  LT(_MOUSE,KC_TAB),     LT(_SYM,KC_ENT),   LT(_NUM, KC_BSPC), U_NA
    //`--------------------------'  `--------------------------'
),

[_SWE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        U_NA,    U_NA , U_NA, U_NA, U_NA, U_NA,                                          U_NA, U_NA, U_NA,     U_NA,   U_NA, U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           U_NA,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  U_NA,                        U_NA,    KC_LBRC, KC_QUOT, KC_SCLN, U_NA,  U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           U_NA,    U_NA , U_NA, U_NA, U_NA, U_NA,                            U_NA,    U_NA,   U_NA,     U_NA,   U_NA,  U_NA,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             U_NA, U_NA,  U_NA,        U_NA, U_NA,  U_NA
      //`--------------------------'  `--------------------------'
),

  [_GAME] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,  KC_O,  KC_P,  KC_LBRC,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          MO(_MEDIA),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,  KC_Z,   KC_X,      KC_C,   KC_V,    KC_B,                          KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_LALT,  KC_SPC,  KC_LCTL,     LT(_SYM,KC_ENT),   LT(_NUM, KC_BSPC), LT(_FUN, KC_DEL)
      //`--------------------------'  `--------------------------'
  ),

  [_GAME2] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,  KC_9,  KC_0,  KC_LBRC,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,   KC_U,    KC_I,    KC_O,   KC_P, KC_QUOT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,  KC_A,   KC_S,      KC_D,   KC_F,    KC_G,                          KC_H,    KC_J,  KC_K, KC_L,  KC_SLSH, KC_ESC,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_LALT,  KC_SPC,  KC_LCTL,     LT(_SYM,KC_ENT),   LT(_NUM, KC_BSPC), LT(_FUN, KC_DEL)
      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        U_NA,   U_NA,     U_NA,    U_NA,    U_NA,    U_NA,                      U_UNDO,   U_PSTE,  U_COPY,   U_CUT, U_REDO,    U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      U_NA   , KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  U_NA,                  KC_CAPS_LOCK, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,   U_NA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      U_NA   , U_NA,     U_NA,     U_NA,    U_NA,    U_NA,                       KC_INS,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  U_NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          U_NA   , U_NA   ,  U_NA,     KC_ENT,KC_BSPC, U_NA
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        U_NA,   U_NA,     U_NA,    U_NA,    U_NA,    U_NA,                        U_UNDO,   U_PSTE,  U_COPY,   U_CUT, U_REDO,    U_NA,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        U_NA   , KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  U_NA,                      U_NA,    KC_MS_L,   KC_MS_D,     KC_MS_U,   KC_MS_R,   U_NA,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        U_NA   , U_NA,     U_NA,     U_NA,    U_NA,    U_NA,                       KC_BTN3,    KC_WH_L,   KC_WH_D,     KC_WH_U,   KC_WH_R,  U_NA,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          U_NA   , U_NA   ,  U_NA,        KC_BTN1,  KC_BTN2  ,U_NA
   //`--------------------------'  `--------------------------'
),
  [_BUTTON] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           U_NA,   U_REDO,   U_CUT,  U_COPY, U_PSTE, U_UNDO,                        U_UNDO,   U_PSTE,  U_COPY,   U_CUT, U_REDO,    U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           U_NA   , U_NA, KC_LALT, KC_LCTL, KC_LSFT,  U_NA,                       U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           U_NA,   U_NA,   U_CUT,  U_COPY, U_PSTE, U_UNDO,                       U_UNDO,   U_PSTE,  U_COPY,   U_CUT, U_NA,    U_NA,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             U_NA , KC_BTN2 ,  KC_BTN1,        KC_BTN1,  KC_BTN2  ,U_NA
      //`--------------------------'  `--------------------------'
   ),


  [_MEDIA] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           U_NA,   U_NA,     U_NA,    U_NA,    U_NA,    U_NA,                        U_NA,   U_NA,  U_NA,   U_NA, U_NA,    U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           U_NA   , KC_LGUI, KC_LALT, KC_LCTL, KC_LSHIFT,  U_NA,                      U_NA,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,   U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           U_NA   , U_NA,     U_NA,     U_NA,    U_NA,    U_NA,                     KC_MUTE,    U_NA,   U_NA,     U_NA,   U_NA,  U_NA,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             U_NA   , U_NA   ,  U_NA,        KC_MSTP, KC_MPLY,  U_NA
      //`--------------------------'  `--------------------------'
),


  [_NUM] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         U_NA, U_NA ,  KC_7   ,   KC_8 ,   KC_9,    SE_EQL,                           U_NA,   SE_LCBR,  SE_RCBR,   SE_LABK, U_NA,    U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          U_NA , KC_COMM, KC_4,     KC_5,    KC_6,  SE_PLUS,                              U_NA,  SE_LPRN, SE_RPRN, SE_RABK, U_NA,   U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          U_NA , U_NA   , KC_1,    KC_2,     KC_3, SE_MINS,                            U_NA ,    SE_LBRC,   SE_RBRC,     SE_PIPE,   U_NA,  U_NA,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              U_NA, KC_0   , KC_DOT,        U_NA, U_NA,  U_NA
      //`--------------------------'  `--------------------------'
),

  [_SYM] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      SE_SECT, SE_EXLM , SE_DQUO, SE_HASH , SE_CURR, SE_BSLS,                        U_NA,   U_NA,  U_NA,   U_NA, U_NA,    U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           SE_GRV, SE_ASTR, KC_NUHS, SE_PERC, SE_AMPR,  SE_SLSH,                        U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   U_NA,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      SE_DIAE,    SE_PND, SE_EURO,  SE_DLR, SE_AT,  SE_QUES,                        U_NA,    U_NA,   U_NA,     U_NA,   U_NA,  U_NA,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                  U_NA, SE_SECT,  U_NA,        U_NA, U_NA,  U_NA
      //`--------------------------'  `--------------------------'
),

  [_FUN] = LAYOUT_split_3x6_3(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          U_NA,    KC_F12 , KC_F7,    KC_F8 , KC_F9,   KC_PSCR,                        U_NA,   U_NA,  U_NA,   TG(_COLEMAK), TG(_QUERTY),  TG(_GAME),
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           U_NA,   KC_F11,  KC_F4,    KC_F5,  KC_F6,  KC_SLCK,                        U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   TG(_GAME2),
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           U_NA,   KC_F10,  KC_F1,    KC_F2,  KC_F3,  KC_PAUS,                        U_NA,    U_NA,   U_NA,     U_NA,   U_NA,  U_NA,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                  U_NA, KC_SPC, KC_TAB,        U_NA, U_NA,  U_NA
      //`--------------------------'  `--------------------------'
)

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}


void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _COLEMAK:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        case _QUERTY:
            oled_write_ln_P(PSTR("Querty"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Gaming"), false);
            break;
  
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
