#include QMK_KEYBOARD_H
#include "my_custom_codes.h"
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_A)) {
         SEND_STRING("->");
    }
    if (leader_sequence_one_key(KC_EXLM)) {
        SEND_STRING(" != ");
    }
    // save vim
    if (leader_sequence_one_key(KC_SCLN)) {
        SEND_STRING(SS_TAP(X_ESC) SS_LSFT(SS_TAP(X_SCLN)) SS_TAP(X_W) SS_TAP(X_ENT));
    }
    // save + quit vim
    if (leader_sequence_one_key(KC_Q)) {
        SEND_STRING(SS_TAP(X_ESC) SS_LSFT(SS_TAP(X_SCLN)) SS_TAP(X_W) SS_TAP(X_Q) SS_TAP(X_ENT));
    }
    // force quit vim
    if (leader_sequence_one_key(KC_J)) {
        SEND_STRING(SS_TAP(X_ESC) SS_LSFT(SS_TAP(X_SCLN)) SS_TAP(X_Q) SS_LSFT(SS_TAP(X_1)) SS_TAP(X_ENT));
    }
    // del eol
    if (leader_sequence_one_key(KC_DEL)) {
        SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_TAP(X_DEL));
    }
    // del sol
    if (leader_sequence_one_key(KC_BSPC)) {
        SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_TAP(X_DEL));
    }
    // windows screen shot
    if (leader_sequence_one_key(KC_S)) {
        SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_S))));
    }
    // Sel line
    if (leader_sequence_one_key(KC_SPC)){
        SEND_STRING(SEL_LINE_MACRO);
    }
    // Copy line
    if (leader_sequence_two_keys(KC_Y, KC_Y)){
        SEND_STRING(COPY_LINE_MACRO SS_TAP(X_RIGHT));
    }
    // Copy + del line
    if (leader_sequence_two_keys(KC_D, KC_D)){
        SEND_STRING(DEL_LINE_MACRO);
    }
    // New line
    if (leader_sequence_one_key(KC_O)){
        SEND_STRING(NEW_LINE_MACRO);
    }
    // New line above (KC_T instead of HOME_T because that's how QK_LEAD expects it)
    if (leader_sequence_two_keys(KC_T, KC_O)){
	SEND_STRING(NEW_LINE_ABOVE_MACRO);
    }
    // wrap word ()
    if (leader_sequence_one_key(KC_T)){
        SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) "(" SS_LCTL(SS_TAP(X_RIGHT)) SS_TAP(X_LEFT) ")");
    }
    // wrap selection ()
    if (leader_sequence_two_keys(KC_T, KC_T)){
        SEND_STRING(SS_LCTL(SS_TAP(X_X)) "()" SS_TAP(X_LEFT) SS_LCTL(SS_TAP(X_V)) SS_TAP(X_RIGHT));
    }
    // wrap word []
    if (leader_sequence_one_key(KC_C)){
        SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) "[" SS_LCTL(SS_TAP(X_RIGHT)) SS_TAP(X_LEFT) "]");
    }
    // wrap selection []
    if (leader_sequence_two_keys(KC_C, KC_C)){
        SEND_STRING(SS_LCTL(SS_TAP(X_X)) "[]" SS_TAP(X_LEFT) SS_LCTL(SS_TAP(X_V)) SS_TAP(X_RIGHT));
    }
    // wrap word {}
    if (leader_sequence_one_key(KC_W)){
        SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)) "{" SS_LCTL(SS_TAP(X_RIGHT)) SS_TAP(X_LEFT) "}");
    }
    // wrap selection {}
    if (leader_sequence_two_keys(KC_W, KC_W)){
        SEND_STRING(SS_LCTL(SS_TAP(X_X)) "{}" SS_TAP(X_LEFT) SS_LCTL(SS_TAP(X_V)) SS_TAP(X_RIGHT));
    }
    // GTE
    if (leader_sequence_one_key(KC_DOT)){
        SEND_STRING(" >= ");
    }
    // LTE
    if (leader_sequence_one_key(KC_COMM)){
        SEND_STRING(" <= ");
    }


}
