#include "my_custom_codes.h"
uint16_t COMBO_LEN = COMBO_LENGTH;

//dvorak combos
const uint16_t PROGMEM esc_combo[] = {KC_COMMA, KC_QUOT, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM excl_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {KC_J, KC_Q, COMBO_END};
const uint16_t PROGMEM dsh_combo[] = {KC_SPC, HOME_T, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_K, BS_LOW, COMBO_END};
const uint16_t PROGMEM rgui_combo[] = {KC_W, KC_J, COMBO_END};
const uint16_t PROGMEM bs_combo[] = {KC_J, BS_LOW, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_K, KC_J, COMBO_END};

//generic combos
const uint16_t PROGMEM tg_raise_combo[] = {E_RAISE, KC_SPC, COMBO_END};
const uint16_t PROGMEM qw_esc_combo[] = {KC_Q, KC_W, COMBO_END};

//graphite combos
const uint16_t PROGMEM gesc_combo[] = {KC_B, KC_L, COMBO_END};
const uint16_t PROGMEM gslsh_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM gexcl_combo[] = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM geql_combo[] = {KC_X, KC_M, COMBO_END};
const uint16_t PROGMEM gdsh_combo[] = {KC_SPC, HOME_GA, COMBO_END};
const uint16_t PROGMEM gdel_combo[] = {KC_C, BS_LOW, COMBO_END};
const uint16_t PROGMEM grgui_combo[] = {KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM gent_combo[] = {KC_M, KC_C, COMBO_END};

//semimak combos
const uint16_t PROGMEM sesc_combo[] = {KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM sslsh_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM sexcl_combo[] = {KC_L, KC_H, COMBO_END};
const uint16_t PROGMEM seql_combo[] = {KC_J, KC_B, COMBO_END};
const uint16_t PROGMEM sdsh_combo[] = {KC_SPC, HOME_SE, COMBO_END};
const uint16_t PROGMEM sdel_combo[] = {KC_M, BS_LOW, COMBO_END};
const uint16_t PROGMEM srgui_combo[] = {KC_B, KC_COMM, COMBO_END};
const uint16_t PROGMEM sbs_combo[] = {KC_B, BS_LOW, COMBO_END};
const uint16_t PROGMEM sent_combo[] = {KC_B, KC_M, COMBO_END};

combo_t key_combos[] = {
    [ESC_COMBO]     = COMBO(esc_combo, KC_ESC),
    [SLSH_COMBO]    = COMBO(slsh_combo, KC_SLASH),
    [DSH_COMBO]     = COMBO(dsh_combo, KC_MINUS),
    [EXCL_COMBO]    = COMBO(excl_combo, KC_EXLM),
    [EQL_COMBO]     = COMBO(eql_combo, KC_EQL),
    [DEL_COMBO]     = COMBO(del_combo, KC_DEL),
    [RGUI_COMBO]    = COMBO(rgui_combo, KC_RGUI),
    [BS_COMBO]      = COMBO(bs_combo, KC_BSPC),
    [ENT_COMBO]     = COMBO(ent_combo, KC_ENT),

    // combos or all layers
    [QW_ESC_COMBO]  = COMBO(qw_esc_combo, KC_ESC),
    [TG_RAISE_COMBO]= COMBO(tg_raise_combo, TG_RAI),

    //graphite combos
    // [GESC_COMBO]     = COMBO(gesc_combo, KC_ESC),
    // [GSLSH_COMBO]    = COMBO(gslsh_combo, KC_SLASH),
    // [GDSH_COMBO]     = COMBO(gdsh_combo, KC_MINUS),
    // [GEXCL_COMBO]    = COMBO(gexcl_combo, KC_EXLM),
    // [GEQL_COMBO]     = COMBO(geql_combo, KC_EQL),
    // [GDEL_COMBO]     = COMBO(gdel_combo, KC_DEL),
    // [GRGUI_COMBO]    = COMBO(grgui_combo, KC_RGUI),
    // [GENT_COMBO]     = COMBO(gent_combo, KC_ENT),

    // semimak combos
    [SESC_COMBO]     = COMBO(sesc_combo, KC_ESC),
    [SSLSH_COMBO]    = COMBO(sslsh_combo, KC_SLASH),
    [SDSH_COMBO]     = COMBO(sdsh_combo, KC_MINUS),
    [SEXCL_COMBO]    = COMBO(sexcl_combo, KC_EXLM),
    [SEQL_COMBO]     = COMBO(seql_combo, KC_EQL),
    [SDEL_COMBO]     = COMBO(sdel_combo, KC_DEL),
    [SRGUI_COMBO]    = COMBO(srgui_combo, KC_RGUI),
    [SBS_COMBO]      = COMBO(sbs_combo, KC_BSPC),
    [SENT_COMBO]     = COMBO(sent_combo, KC_ENT),
};

