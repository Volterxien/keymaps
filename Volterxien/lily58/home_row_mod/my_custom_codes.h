#pragma once
#include QMK_KEYBOARD_H

//keycode simplification 
#define KC_LBRA LSFT(KC_LBRC)
#define KC_RBRA LSFT(KC_RBRC)

//Temp Layers
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GLOWER MO(_GLOWER)
#define SYMS MO(_SYMS)
#define TG_RAI TG(_RAISE)

//Editing shortcuts
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define CUT LCTL(KC_X)

//modtap
#define ALT_ENT MT(MOD_LALT, KC_ENT) 

//home row mods
#define HOME_A MT(MOD_LGUI, KC_A)
#define HOME_O MT(MOD_LALT, KC_O)
#define HOME_E MT(MOD_LSFT, KC_E)
#define HOME_U MT(MOD_LCTL, KC_U)
#define HOME_H MT(MOD_RCTL, KC_H)
#define HOME_T MT(MOD_RSFT, KC_T)
#define HOME_N MT(MOD_RALT, KC_N)
#define HOME_S MT(MOD_RGUI, KC_S)

//Layer tap defs
#define T_RAISE LT(_RAISE, KC_TAB)
#define S_RAISE LT(_RAISE, KC_SPC)
#define E_SYMS LT(_SYMS, KC_ENT)
#define BS_LOW LT(_LOWER, KC_BSPC)
#define BS_SYMS LT(_SYMS, KC_BSPC)
#define E_LOWER LT(_LOWER, KC_ENT)
#define E_RAISE LT(_RAISE, KC_ENT)
#define T_SYMS LT(_SYMS, KC_TAB)

//Custom hold keys
#define H_PGU TD(TD_H_PU)
#define E_PGD TD(TD_E_PD)
#define LT_GT TD(TD_GTLT)
#define BRK_INS TD(TD_INS_PAUSE)

//Macros
#define SEL_LINE_MACRO SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END))
#define COPY_LINE_MACRO SEL_LINE_MACRO SS_LCTL(SS_TAP(X_C))
#define DEL_LINE_MACRO (COPY_LINE_MACRO SS_TAP(X_DEL) SS_TAP(X_BSPC))
#define NEW_LINE_MACRO (SS_TAP(X_END) SS_TAP(X_ENT))
#define NEW_LINE_ABOVE_MACRO (SS_TAP(X_HOME) SS_TAP(X_ENT) SS_TAP(X_UP))

enum LAYERS {
  _DVORAK = 0,
  _GAME,
  _QWERTY,
  _RAISE,
  _SYMS,
  _ADJUST,
  _LOWER,
  _GLOWER
};

enum CUSTOM_KEYCODES{
    DVORAK = SAFE_RANGE,
    QWERTY,
    GAMING,
    DEL_EOL,
    BS_SOL,
    S_VIM,
    KC_ARR,
    KC_BSDL,
    NOT_EQL,
    PREVDIR,
};

enum COMBOS{
    ESC_COMBO,
    SLSH_COMBO,
    DSH_COMBO,
    EXCL_COMBO,
    EQL_COMBO,
    TG_RAISE_COMBO,
    DEL_COMBO,
    RGUI_COMBO,
    ENT_COMBO,
    // LPAR_COMBO,
    // RPAR_COMBO,
    // LBRC_COMBO,
    // RBRC_COMBO,
    // _COMBO,
    // NOTEQL_COMBO,
    COMBO_LENGTH,
};

enum TAP_DANCE{
    TD_GTLT,
    TD_E_PD,
    TD_H_PU,
    TD_INS_PAUSE,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;
