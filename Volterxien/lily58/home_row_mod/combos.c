#include "my_custom_codes.h"
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM esc_combo[] = {KC_COMMA, KC_QUOT, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM excl_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {KC_J, KC_Q, COMBO_END};
const uint16_t PROGMEM dsh_combo[] = {HOME_N, HOME_T, COMBO_END};
const uint16_t PROGMEM tg_raise_combo[] = {T_RAISE, KC_SPC, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_K, BS_LOW, COMBO_END};
const uint16_t PROGMEM rgui_combo[] = {KC_W, KC_J, COMBO_END};
// const uint16_t PROGMEM arr_combo[] = {HOME_A, HOME_O, COMBO_END};
// const uint16_t PROGMEM noteql_combo[] = {KC_DOT, KC_P, COMBO_END};
// const uint16_t PROGMEM res1_combo[] = {HOME_O, HOME_E, COMBO_END};
// const uint16_t PROGMEM res2_combo[] = {HOME_E, HOME_U, COMBO_END};
// const uint16_t PROGMEM res3_combo[] = {HOME_H, HOME_T, COMBO_END};
// const uint16_t PROGMEM res4_combo[] = {HOME_N, HOME_S, COMBO_END};

combo_t key_combos[] = {
    [ESC_COMBO]     = COMBO(esc_combo, KC_ESC),
    [SLSH_COMBO]    = COMBO(slsh_combo, KC_SLASH),
    [DSH_COMBO]     = COMBO(dsh_combo, KC_MINUS),
    [EXCL_COMBO]    = COMBO(excl_combo, KC_EXLM),
    [EQL_COMBO]     = COMBO(eql_combo, KC_EQL),
    [TG_RAISE_COMBO]= COMBO(tg_raise_combo, TG_RAI),
    [DEL_COMBO]     = COMBO(del_combo, KC_DEL),
    [RGUI_COMBO]    = COMBO(rgui_combo, KC_RGUI),
    // [ARR_COMBO]     = COMBO(arr_combo, KC_ARR),
    // [NOTEQL_COMBO]  = COMBO(noteql_combo, NOT_EQL)
};

