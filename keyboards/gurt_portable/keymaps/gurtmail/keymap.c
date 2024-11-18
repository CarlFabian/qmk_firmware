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
    _FUN,
    _BRACKETS
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
    SWE_COMBO1,
    SWE_COMBO2,
    SWE_COMBO3,
    LPRN_COMBO,
    RPRN_COMBO,
    LCBR_COMBO,
    RCBR_COMBO,
    LBRC_COMBO,
    RBRC_COMBO,
    LABK_COMBO,
    RABK_COMBO,
    BSLS_COMBO,
    SLSH_COMBO,
    PIPE_COMBO,
    CAPS_COMBO,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

//Function combos
const uint16_t PROGMEM esc_combo[] = { SE_Q, SE_W, COMBO_END }; // ESC
const uint16_t PROGMEM del_combo[] = { SE_Y, SE_QUOT, COMBO_END };// DEL
const uint16_t PROGMEM caps_combo[] = { SE_C, SE_COMM, COMBO_END };// CAPSWORD

//Symbol combos
const uint16_t PROGMEM lprn_combo[] = { LSFT_T(SE_T), SE_P, COMBO_END };// (
const uint16_t PROGMEM rprn_combo[] = { LSFT_T(SE_N), SE_L, COMBO_END };// )
const uint16_t PROGMEM lcbr_combo[] = { LCTL_T(SE_S), SE_F, COMBO_END };// {
const uint16_t PROGMEM rcbr_combo[] = { LCTL_T(SE_E), SE_U, COMBO_END };// }
const uint16_t PROGMEM lbrc_combo[] = { LALT_T(SE_R), SE_W, COMBO_END };// [
const uint16_t PROGMEM rbrc_combo[] = { LALT_T(SE_I), SE_Y, COMBO_END };// ]
const uint16_t PROGMEM labk_combo[] = { SE_G, SE_B, COMBO_END };// <
const uint16_t PROGMEM rabk_combo[] = { SE_M, SE_J, COMBO_END };// >
const uint16_t PROGMEM bsls_combo[] = { LSFT_T(SE_T), SE_F, COMBO_END };// backslash
const uint16_t PROGMEM slsh_combo[] = { LSFT_T(SE_N), SE_U, COMBO_END };// /
const uint16_t PROGMEM pipe_combo[] = { SE_G, SE_M, COMBO_END};// |

//Swedish letter combos
const uint16_t PROGMEM swe_combo1[] = { SE_W, SE_F, COMBO_END }; // Å
const uint16_t PROGMEM swe_combo2[] = { SE_F, SE_P, COMBO_END }; // Ä
const uint16_t PROGMEM swe_combo3[] = { SE_U, SE_Y, COMBO_END }; // Ö


combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(del_combo, KC_DEL),
    COMBO(swe_combo1, SE_ARNG),
    COMBO(swe_combo2, SE_ADIA),
    COMBO(swe_combo3, SE_ODIA),
    COMBO(lprn_combo, SE_LPRN),
    COMBO(rprn_combo, SE_RPRN),
    COMBO(lcbr_combo, SE_LCBR),
    COMBO(rcbr_combo, SE_RCBR),
    COMBO(lbrc_combo, SE_LBRC),
    COMBO(rbrc_combo, SE_RBRC),
    COMBO(labk_combo, SE_LABK),
    COMBO(rabk_combo, SE_RABK),
    COMBO(bsls_combo, SE_BSLS),
    COMBO(slsh_combo, SE_SLSH),
    COMBO(pipe_combo, SE_PIPE),
    [CAPS_COMBO] = COMBO_ACTION(caps_combo)
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_COLEMAK] = LAYOUT(
     //,-----------------------------------------------------.                  ,-----------------------------------------------------.
          SE_Q,    SE_W,    SE_F,       SE_P,      SE_B,                             SE_J,   SE_L,      SE_U,    SE_Y,    SE_QUOT,
     //,-----------------------------------------------------.                  ,-----------------------------------------------------.
     LGUI_T(SE_A),LALT_T(SE_R),LCTL_T(SE_S),LSFT_T(SE_T), SE_G,                 SE_M,   LSFT_T(SE_N),LCTL_T(SE_E),LALT_T(SE_I),LGUI_T(SE_O),
     //,-----------------------------------------------------.                  ,-----------------------------------------------------.
       LT(_BUTTON, SE_Z)  ,SE_X, SE_C, LT(_BRACKETS, SE_D), LT(_MEDIA, SE_V),      LT(_FUN, SE_K), SE_H,  SE_COMM, ALGR_T(SE_DOT),LT(_BUTTON,SE_MINS),
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
              LT(_BUTTON, SE_Z), ALGR_T(SE_X), KC_C, KC_V, LT(_MEDIA, SE_B),                       LT(_FUN, SE_N), SE_M, SE_COMM, ALGR_T(SE_DOT), LT(_BUTTON,SE_MINS),
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                             LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB),                   LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC)
        //                          ----------------------------.               ,--------------------------------
                                 ),

     [_NAV] = LAYOUT(
         //,-----------------------------------------------------.              ,-----------------------------------------------------.
              U_NA,     U_NA,    U_NA,    U_NA,    U_NA,                          U_UNDO,   U_PSTE,  U_COPY,   U_CUT, U_REDO,
         //,-----------------------------------------------------.              ,-----------------------------------------------------.
              KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  U_NA,                           U_NA , KC_LEFT , KC_DOWN, KC_UP, KC_RGHT,
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
             KC_ACL0, KC_LALT, KC_LCTL, KC_LSFT,  KC_BTN3,                        U_NA ,KC_MS_L,   KC_MS_D,     KC_MS_U,   KC_MS_R,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
            U_NA,     U_NA,     U_NA,    KC_ACL2,    U_NA,                            U_NA,    KC_WH_L,   KC_WH_D,     KC_WH_U,   KC_WH_R,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                           U_NA , U_NA,                       KC_BTN1,  KC_BTN2
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

    [_NUM] = LAYOUT(     //Numpad
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 U_NA ,  SE_7   ,   SE_8 ,   SE_9,   SE_EQL,                      U_NA,   U_NA,  U_NA, U_NA,  U_NA,
        //,-----------------------------------------------------.               ,----------------------------------------------------.
                 SE_COMM, SE_4,     SE_5,    SE_6,  SE_PLUS,                       U_NA,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                 SE_HALF   , SE_1,    SE_2,     SE_3, SE_MINS,                        U_NA ,  U_NA, U_NA, U_NA,  U_NA,
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
                                         U_NA , U_NA ,                             U_NA, U_NA
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
     ),

     [_BRACKETS] = LAYOUT(    //Brackets
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                 U_NA, U_NA, U_NA, U_NA, U_NA,                    U_NA, SE_LCBR, SE_RCBR, U_NA, U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                 U_NA, U_NA, U_NA, U_NA, U_NA,                    SE_PIPE, SE_LPRN, SE_RPRN, SE_LBRC, SE_RBRC,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                 U_NA, U_NA, U_NA, U_NA, U_NA,                    U_NA,  SE_LABK, SE_RABK, U_NA, U_NA,
        //,-----------------------------------------------------.               ,-----------------------------------------------------.
                                                     U_NA, U_NA,                   U_NA, U_NA
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
        add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
        return true;

        // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case SE_MINS:
    case SE_UNDS:
    case KC_LSFT:
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
