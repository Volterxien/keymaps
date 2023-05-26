#pragma once
//keycode simplification 
#define KC_LBRA LSFT(KC_LBRC)
#define KC_RBRA LSFT(KC_RBRC)

//Temp Layers
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GLOWER MO(_GLOWER)
#define SYMS MO(_SYMS);

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
#define D_SYMS LT(_SYMS, KC_DEL)
#define E_LOWER LT(_LOWER, KC_ENT)

//Custom hold keys
#define H_PGU LT(0, KC_HOME)
#define E_PGD LT(0, KC_END)

enum layer_number {
  _DVORAK = 0,
  _GAME,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SYMS,
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
    KC_BSDL
};