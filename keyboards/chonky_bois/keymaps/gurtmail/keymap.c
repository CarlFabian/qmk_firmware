
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


/* copy paste and stuff*/
#define U_COPY LCTL(SE_C)
#define U_PSTE LCTL(SE_V)
#define U_CUT LCTL(SE_X)
#define U_UNDO LCTL(SE_Z)
#define U_REDO LCTL(SE_Y)

#define U_NA KC_NO // present but not available for use

// Combos
enum combo_events {
    ESC_COMBO,
    DEL_COMBO,
    SWE_COLEMAK_COMBO1,
    SWE_COLEMAK_COMBO2,
    SWE_COLEMAK_COMBO3,
    SWE_QWERTY_COMBO1,
    SWE_QWERTY_COMBO2,
    SWE_QWERTY_COMBO3,
    CAPS_COMBO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

//Function combos
const uint16_t PROGMEM esc_combo[] = { SE_Q, SE_W, COMBO_END }; // ESC
const uint16_t PROGMEM del_combo[] = { SE_Y, SE_QUOT, COMBO_END };// DEL
const uint16_t PROGMEM caps_combo[] = { SE_C, SE_COMM, COMBO_END };// CAPSWORD

//Swedish letter combos 
const uint16_t PROGMEM sweColemak_combo1[] = { SE_W, SE_F, COMBO_END }; // Å
const uint16_t PROGMEM sweColemak_combo2[] = { SE_F, SE_P, COMBO_END }; // Ä
const uint16_t PROGMEM sweColemak_combo3[] = { SE_U, SE_Y, COMBO_END }; // Ö
const uint16_t PROGMEM sweQwerty_combo1[] = { SE_W, SE_E, COMBO_END }; // Å
const uint16_t PROGMEM sweQwerty_combo2[] = { SE_E, SE_R, COMBO_END }; // Ä
const uint16_t PROGMEM sweQwerty_combo3[] = { SE_I, SE_O, COMBO_END }; // Ö

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(del_combo, KC_DEL),
    COMBO(sweColemak_combo1, SE_LBRC),
    COMBO(sweColemak_combo2, SE_QUOT),
    COMBO(sweColemak_combo3, SE_SCLN),
    COMBO(sweQwerty_combo1, SE_LBRC),
    COMBO(sweQwerty_combo2, SE_QUOT),
    COMBO(sweQwerty_combo3, SE_SCLN),
    [CAPS_COMBO] = COMBO_ACTION(caps_combo),
};


// Tap Dance keycodes
enum td_keycodes {
    TD_PRN, // (
    TD_CBR, // {
    TD_BRC, // [
    TD_ABK, // <
    TD_SLSH // /
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t* state);

// `finished` and `reset` functions for each tapdance keycode
void tdprn_finished(qk_tap_dance_state_t* state, void* user_data);
void tdprn_reset(qk_tap_dance_state_t* state, void* user_data);
void tdcbr_finished(qk_tap_dance_state_t* state, void* user_data);
void tdcbr_reset(qk_tap_dance_state_t* state, void* user_data);
void tdbrc_finished(qk_tap_dance_state_t* state, void* user_data);
void tdbrc_reset(qk_tap_dance_state_t* state, void* user_data);
void tdabk_finished(qk_tap_dance_state_t* state, void* user_data);
void tdabk_reset(qk_tap_dance_state_t* state, void* user_data);
void tdslsh_finished(qk_tap_dance_state_t* state, void* user_data);
void tdslsh_reset(qk_tap_dance_state_t* state, void* user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_COLEMAK] = LAYOUT(
     //,-----------------------------------------------------.                  ,-----------------------------------------------------.
          SE_Q,    SE_W,    SE_F,       SE_P,      SE_B,                             SE_J,   SE_L,      SE_U,    SE_Y,    SE_QUOT,
     //,-----------------------------------------------------.                  ,-----------------------------------------------------.
     LGUI_T(SE_A),LALT_T(SE_R),LCTL_T(SE_S),LSFT_T(SE_T), SE_G,                 SE_M,   LSFT_T(SE_N),LCTL_T(SE_E),LALT_T(SE_I),LGUI_T(SE_O),
     //,-----------------------------------------------------.                  ,-----------------------------------------------------.
       LT(_BUTTON, SE_Z)  ,SE_X, SE_C, SE_D, LT(_MEDIA, SE_V),                    LT(_FUN, SE_K), SE_H,  SE_COMM, ALGR_T(SE_DOT),LT(_BUTTON,SE_MINS),
     //,-----------------------------------------------------.                  ,-----------------------------------------------------.
                           LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB),                 LT(_SYM, KC_ENT),  LT(_NUM, KC_BSPC)
     //                          ----------------------------.                  ,--------------------------------
                              ),

    [_QWERTY] = LAYOUT(
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,                               SE_Y,    SE_U,    SE_I,  SE_O,  SE_P,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
        LGUI_T(SE_A),LALT_T(SE_S),LCTL_T(SE_D),LSFT_T(SE_F),SE_G,                SE_H, RSFT_T(SE_J),LCTL_T(SE_K),LALT_T(SE_L),LGUI_T(SE_QUOT),
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
              LT(_BUTTON, SE_Z), ALGR_T(SE_X), KC_C, KC_V, LT(_FUN, SE_B),                       LT(_FUN, SE_N), SE_M, SE_COMM, ALGR_T(SE_DOT), LT(_BUTTON,SE_MINS),
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                             LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB),                   LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC)
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
             KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  KC_BTN3,                          U_NA,    KC_MS_L,   KC_MS_D,     KC_MS_U,   KC_MS_R,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
            U_NA,     U_NA,     U_NA,    U_NA,    U_NA,                            U_NA,    KC_WH_L,   KC_WH_D,     KC_WH_U,   KC_WH_R,
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

    [_MEDIA] = LAYOUT(   //                                                            Media keys
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 U_NA,     U_NA,    U_NA,    U_NA,    U_NA,                         U_NA,   U_NA,  U_NA,   U_NA,     U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                        U_NA, U_NA, U_NA, U_NA,  U_NA,                               U_NA, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 U_NA,     U_NA,     U_NA,    U_NA,    U_NA,                       KC_MUTE,    U_NA,   U_NA,     U_NA,   U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                             KC_MPLY ,  KC_MSTP,                   KC_MSTP, KC_MPLY
        //                          ----------------------------.               ,--------------------------------
                                 ),

    [_NUM] = LAYOUT(     //Numpad                                                       Brackets
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 U_NA ,  SE_7   ,   SE_8 ,   SE_9,   SE_EQL,                      U_NA,   U_NA,  U_NA, U_NA,  U_NA,
        //,-----------------------------------------------------.               ,----------------------------------------------------.
                 SE_COMM, SE_4,     SE_5,    SE_6,  SE_PLUS,                       U_NA,  TD(TD_PRN), TD(TD_CBR), TD(TD_BRC), TD(TD_ABK),
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 SE_HALF   , SE_1,    SE_2,     SE_3, SE_MINS,                        U_NA ,  TD(TD_SLSH), SE_PIPE, U_NA,  U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                           SE_0   , SE_DOT,                        U_NA, U_NA
        //                          ----------------------------.               ,--------------------------------
                                     ),

    [_SYM] = LAYOUT(     //Symbols                                                      Dead symbols
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 SE_SECT,  SE_AT, SE_HASH , SE_CURR, SE_MICR,                          U_NA,   SE_ACUT,  SE_DIAE,  U_NA,   U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 SE_PERC, SE_AMPR, SE_DQUO, SE_EXLM,   SE_QUES,                     U_NA,  SE_GRV,    SE_CIRC, SE_TILD, U_NA, 
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                   U_NA, SE_PND, SE_EURO,  SE_DLR,  U_NA,                           U_NA,    U_NA,   U_NA,     U_NA,   U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                         U_NA  , U_NA ,                             U_NA, U_NA
        //                          ----------------------------.               ,--------------------------------
                                         ),

    [_FUN] = LAYOUT(    //Function                                                      Layer toggle and reset
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



// Determine the tapdance state to return
td_state_t cur_dance(qk_tap_dance_state_t* state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void tdprn_finished(qk_tap_dance_state_t* state, void* user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
    case TD_SINGLE_TAP:
        register_code16(SE_LPRN);
        break;
    case TD_SINGLE_HOLD:
        register_code16(SE_RPRN); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        break;
    case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
        tap_code16(SE_LPRN);
        register_code16(SE_LPRN);
        break;
    default:
        break;
    }
}

void tdprn_reset(qk_tap_dance_state_t* state, void* user_data) {
    switch (td_state) {
    case TD_SINGLE_TAP:
        unregister_code16(SE_LPRN);
        break;
    case TD_SINGLE_HOLD:
        unregister_code16(SE_RPRN); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        break;
    case TD_DOUBLE_SINGLE_TAP:
        unregister_code16(SE_LPRN);
        break;
    default:
        break;
    }
}
void tdcbr_finished(qk_tap_dance_state_t* state, void* user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
    case TD_SINGLE_TAP:
        register_code16(SE_LCBR);
        break;
    case TD_SINGLE_HOLD:
        register_code16(SE_RCBR); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        break;
    case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
        tap_code16(SE_LCBR);
        register_code16(SE_LCBR);
        break;
    default:
        break;
    }
}

void tdcbr_reset(qk_tap_dance_state_t* state, void* user_data) {
    switch (td_state) {
    case TD_SINGLE_TAP:
        unregister_code16(SE_LCBR);
        break;
    case TD_SINGLE_HOLD:
        unregister_code16(SE_RCBR); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        break;
    case TD_DOUBLE_SINGLE_TAP:
        unregister_code16(SE_LCBR);
        break;
    default:
        break;
    }
}
void tdbrc_finished(qk_tap_dance_state_t* state, void* user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
    case TD_SINGLE_TAP:
        register_code16(SE_LBRC);
        break;
    case TD_SINGLE_HOLD:
        register_code16(SE_RBRC); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        break;
    case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
        tap_code16(SE_LBRC);
        register_code16(SE_LBRC);
        break;
    default:
        break;
    }
}

void tdbrc_reset(qk_tap_dance_state_t* state, void* user_data) {
    switch (td_state) {
    case TD_SINGLE_TAP:
        unregister_code16(SE_LBRC);
        break;
    case TD_SINGLE_HOLD:
        unregister_code16(SE_RBRC); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        break;
    case TD_DOUBLE_SINGLE_TAP:
        unregister_code16(SE_LBRC);
        break;
    default:
        break;
    }
}

void tdabk_finished(qk_tap_dance_state_t* state, void* user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
    case TD_SINGLE_TAP:
        register_code16(SE_LABK);
        break;
    case TD_SINGLE_HOLD:
        register_code16(SE_RABK); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        break;
    case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
        tap_code16(SE_LABK);
        register_code16(SE_LABK);
        break;
    default:
        break;
    }
}

void tdabk_reset(qk_tap_dance_state_t* state, void* user_data) {
    switch (td_state) {
    case TD_SINGLE_TAP:
        unregister_code16(SE_LABK);
        break;
    case TD_SINGLE_HOLD:
        unregister_code16(SE_RABK); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        break;
    case TD_DOUBLE_SINGLE_TAP:
        unregister_code16(SE_LABK);
        break;
    default:
        break;
    }
}

void tdslsh_finished(qk_tap_dance_state_t* state, void* user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
    case TD_SINGLE_TAP:
        register_code16(SE_SLSH);
        break;
    case TD_SINGLE_HOLD:
        register_code16(SE_BSLS); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        break;
    case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
        tap_code16(SE_SLSH);
        register_code16(SE_SLSH);
        break;
    default:
        break;
    }
}

void tdslsh_reset(qk_tap_dance_state_t* state, void* user_data) {
    switch (td_state) {
    case TD_SINGLE_TAP:
        unregister_code16(SE_SLSH);
        break;
    case TD_SINGLE_HOLD:
        unregister_code16(SE_BSLS); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        break;
    case TD_DOUBLE_SINGLE_TAP:
        unregister_code16(SE_SLSH);
        break;
    default:
        break;
    }
}
// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tdprn_finished, tdprn_reset),
    [TD_CBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tdcbr_finished, tdcbr_reset),
    [TD_BRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tdbrc_finished, tdbrc_reset),
    [TD_ABK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tdabk_finished, tdabk_reset),
    [TD_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tdslsh_finished, tdslsh_reset)
};
