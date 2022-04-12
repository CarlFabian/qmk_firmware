// -*- compile-command: (concat "pushd " sndr-project-root " && lxqt-sudo make chonky_bois:default:avrdude-split-right"); -*-
/* Copyright 2020 Sander Boer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "features/caps_word.h"

 // Layers
enum layers {
    _COLEMAK,
    _QWERTY,
    _NAV,
    _MOUSE,
    _BUTTON,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN
};

// Combos
enum combo_events {
    ESC_COMBO,
    DEL_COMBO,
    SWE_COMBO1,
    SWE_COMBO2,
    SWE_COMBO3,
    CAPS_COMBO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM esc_combo[] = { KC_Q, KC_W, COMBO_END };
const uint16_t PROGMEM del_combo[] = { KC_Y, KC_NUHS, COMBO_END };
const uint16_t PROGMEM swe_combo1[] = { KC_W, KC_F, COMBO_END };
const uint16_t PROGMEM swe_combo2[] = { KC_F, KC_P, COMBO_END };
const uint16_t PROGMEM swe_combo3[] = { KC_U, KC_Y, COMBO_END };
const uint16_t PROGMEM caps_combo[] = { KC_C, KC_COMM, COMBO_END };

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(del_combo, KC_DEL),
    COMBO(swe_combo1, KC_LBRC),
    COMBO(swe_combo2, KC_QUOT),
    COMBO(swe_combo3, KC_SCLN),
    [CAPS_COMBO] = COMBO_ACTION(caps_combo)
};


void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
    case CAPS_COMBO:
        if (pressed) {
            caps_word_set(true);  // Activate Caps Word!
        }
        break;

        // Other combos...
    }
}

// Caps word
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_caps_word(keycode, record)) { return false; }
    // Your macros ...

    return true;
}


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case KC_LBRC:
    case KC_QUOT:
    case KC_SCLN:
    case KC_SLSH:
        add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
        return true;

        // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
        return true;

    default:
        return false;  // Deactivate Caps Word.
    }
}


// Tapping term for individual keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    case  LGUI_T(KC_A):
        return TAPPING_TERM + 200;
    case LGUI_T(KC_O):
        return TAPPING_TERM + 200;
    case LCTL_T(KC_S):
        return TAPPING_TERM + 50;
    case LCTL_T(KC_E):
        return TAPPING_TERM + 50;
    case LALT_T(KC_R):
        return TAPPING_TERM + 50;
    case LALT_T(KC_I):
        return TAPPING_TERM + 50;
    default:
        return TAPPING_TERM;
    }
}


/* copy paste and stuff*/
#define U_COPY LCTL(KC_C)
#define U_PSTE LCTL(KC_V)
#define U_CUT LCTL(KC_X)
#define U_UNDO LCTL(KC_Z)
#define U_REDO LCTL(KC_Y)


#define U_NA KC_NO // present but not available for use

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
 [_COLEMAK] = LAYOUT(
     //,-----------------------------------------------------.                  ,-----------------------------------------------------.
      KC_Q,    KC_W,    KC_F,       KC_P,      KC_B,                               KC_J,   KC_L,      KC_U,    KC_Y,    KC_NUHS,
     //,-----------------------------------------------------.                  ,-----------------------------------------------------.
      LGUI_T(KC_A),LALT_T(KC_R),LCTL_T(KC_S),LSFT_T(KC_T), KC_G,                   KC_M,   LSFT_T(KC_N),LCTL_T(KC_E),LALT_T(KC_I),LGUI_T(KC_O),
     //,-----------------------------------------------------.                  ,-----------------------------------------------------.
       LT(_BUTTON, KC_Z)  ,KC_X, KC_C, KC_D, LT(_MEDIA, KC_V),                    LT(_FUN, KC_K), KC_H,  KC_COMM, ALGR_T(KC_DOT),LT(_BUTTON,KC_SLSH),
     //,-----------------------------------------------------.                  ,-----------------------------------------------------.
                            LT(_NAV,KC_SPC), LT(_MOUSE,KC_TAB),                   LT(_SYM,KC_ENT),  LT(_NUM, KC_BSPC)
     //                          ----------------------------.                  ,--------------------------------
                              ),


    // TEMP mv KC_COMM to RESET, combos dont do macros nor RESET
    [_QWERTY] = LAYOUT(
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,  KC_O,  KC_P,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
        LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G,                  KC_H, RSFT_T(KC_J),LCTL_T(KC_K),LALT_T(KC_L),LGUI_T(KC_SCLN),
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
          KC_Z,   ALGR_T(KC_X), KC_C, KC_V, LT(_FUN, KC_B),                       LT(_FUN, KC_N),    KC_M,    KC_COMM,ALGR_T(KC_DOT),KC_SLSH,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                             LT(_NAV,KC_SPC), LT(_MOUSE,KC_TAB),                   LT(_SYM,KC_ENT),  LT(_NUM, KC_BSPC)
        //                          ----------------------------.               ,--------------------------------
                                 ),

     [_NAV] = LAYOUT(
         //,-----------------------------------------------------.              ,-----------------------------------------------------.
              U_NA,     U_NA,    U_NA,    U_NA,    U_NA,                          U_UNDO,   U_PSTE,  U_COPY,   U_CUT, U_REDO,
         //,-----------------------------------------------------.              ,-----------------------------------------------------.
              KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  U_NA,                          KC_CAPSLOCK, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
         //,-----------------------------------------------------.              ,-----------------------------------------------------.
             U_NA,     U_NA,     U_NA,    U_NA,    U_NA,                          KC_INS,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,
         //,-----------------------------------------------------.              ,-----------------------------------------------------.
                                               U_NA, U_NA,                        KC_ENT,  KC_BSPC
         //                          ----------------------------.              ,--------------------------------
                                  ),


    [_MOUSE] = LAYOUT(
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                U_NA,     U_NA,    U_NA,    U_NA,    U_NA,                        U_UNDO,   U_PSTE,  U_COPY,   U_CUT, U_REDO,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
             KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  U_NA,                            U_NA,    KC_MS_L,   KC_MS_D,     KC_MS_U,   KC_MS_R,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
            U_NA,     U_NA,     U_NA,    U_NA,    U_NA,                            KC_BTN3,    KC_WH_L,   KC_WH_D,     KC_WH_U,   KC_WH_R,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                                 U_NA, U_NA,                       KC_BTN1,  KC_BTN2
        //                          ----------------------------.               ,--------------------------------
                                 ),

    [_BUTTON] = LAYOUT(
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
             U_REDO,   U_CUT,  U_COPY, U_PSTE, U_UNDO,                             U_UNDO,   U_PSTE,  U_COPY,   U_CUT, U_REDO,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
             U_NA, KC_LALT, KC_LCTL, KC_LSFT,  U_NA,                               U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
            U_NA,   U_CUT,  U_COPY, U_PSTE, U_UNDO,                                U_UNDO,   U_PSTE,  U_COPY,   U_CUT, U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                              KC_BTN2 ,  KC_BTN1,                  KC_BTN1,  KC_BTN2
        //                          ----------------------------.               ,--------------------------------
                                 ),

    [_MEDIA] = LAYOUT(
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 U_NA,     U_NA,    U_NA,    U_NA,    U_NA,                         U_NA,   U_NA,  U_NA,   U_NA,     U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 KC_LGUI, KC_LALT, KC_LCTL, KC_LSHIFT,  U_NA,                       U_NA,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 U_NA,     U_NA,     U_NA,    U_NA,    U_NA,                       KC_MUTE,    U_NA,   U_NA,     U_NA,   U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                             KC_MPLY ,  KC_MSTP,                   KC_MSTP, KC_MPLY
        //                          ----------------------------.               ,--------------------------------
                                 ),

    [_NUM] = LAYOUT(
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 U_NA ,  KC_7   ,   KC_8 ,   KC_9,    U_NA,                      U_NA,   SE_LCBR,  SE_RCBR,   U_NA, U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 KC_COMM, KC_4,     KC_5,    KC_6,  SE_PLUS,                       SE_EQL,  SE_LPRN, SE_RPRN, SE_LABK, SE_RABK,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 U_NA   , KC_1,    KC_2,     KC_3, SE_MINS,                        U_NA ,    SE_LBRC,   SE_RBRC,     SE_PIPE,   U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                           KC_0   , KC_DOT,                        U_NA, U_NA
        //                          ----------------------------.               ,--------------------------------
                                     ),

    [_SYM] = LAYOUT(
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 SE_EXLM , SE_DQUO, SE_HASH , SE_CURR, SE_BSLS,                    U_NA,   U_NA,  U_NA,   U_NA, U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 SE_ASTR, KC_NUHS, SE_PERC, SE_AMPR,  SE_SLSH,                     SE_GRV,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 SE_PND, SE_EURO,  SE_DLR, SE_AT,  SE_QUES,                        U_NA,    U_NA,   U_NA,     U_NA,   U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                         SE_SECT   , SE_DIAE,                      U_NA, U_NA
        //                          ----------------------------.               ,--------------------------------
                                         ),

    [_FUN] = LAYOUT(
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                    KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,                          RESET, U_NA, U_NA, U_NA, TG(_QWERTY),
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                    KC_F11, KC_F4, KC_F5, KC_F6, KC_SLCK,                          U_NA, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                     KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS,                         U_NA, U_NA, U_NA, U_NA, U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                             KC_SPC, KC_TAB,                       U_NA, U_NA
        //                          ----------------------------.               ,--------------------------------
     )

};

