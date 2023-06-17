#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "my_custom_codes.h"
#include "oled.h"
#include "my_combos.h"

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM esc_combo[] = {KC_COMMA, KC_QUOT, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM excl_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {KC_J, KC_Q, COMBO_END};
const uint16_t PROGMEM dsh_combo[] = {HOME_N, HOME_T, COMBO_END};
const uint16_t PROGMEM tg_raise_combo[] = {T_RAISE, KC_SPC, COMBO_END};
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
    // [ARR_COMBO]     = COMBO(arr_combo, KC_ARR),
    // [NOTEQL_COMBO]  = COMBO(noteql_combo, NOT_EQL)
};

/**************************************************************************************************************************************************************************
 * ************************************************************************************************************************************************************************
 * **********************************************       KEYMAPS         ***************************************************************************************************
 * ************************************************************************************************************************************************************************
 * ************************************************************************************************************************************************************************
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | BSPC |ent/low| /del/low/      \tab/rai\  |spc/rai| RGUI |      | 
 *                   |      |      |      |/       /         \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_DVORAK] = LAYOUT(
  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  XXXXXXX,   KC_QUOT,   KC_COMMA,   KC_DOT,     KC_P,       KC_Y,                       KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       XXXXXXX,
  XXXXXXX,   HOME_A,    HOME_O,     HOME_E,     HOME_U,     KC_I,                       KC_D,       HOME_H,     HOME_T,     HOME_N,     HOME_S,     XXXXXXX,
  XXXXXXX,   KC_SCLN,   KC_Q,       KC_J,       KC_K,       KC_X,     XXXXXXX, XXXXXXX, KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       XXXXXXX,
                                    XXXXXXX,    KC_DEL,     BS_LOWER, E_SYMS,  T_RAISE, KC_SPC,    KC_RGUI,    XXXXXXX
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | BOOT |      |      |      |      |                    |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| Pgup | Left | Down | Right| Pgdn |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste| Redo |-------|    |-------|      | Menu |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | BSPC |ent/low| /del/low/      \tab/rai\  |spc/rai| RGUI |      | 
 *                   |      |      |      |/       /         \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______,  _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
  XXXXXXX,  QK_BOOT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,      KC_UP,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    QK_LEAD,    XXXXXXX,                            H_PGU,      KC_LEFT,    KC_DOWN,    KC_RIGHT,   E_PGD,      XXXXXXX,
  XXXXXXX,  UNDO,       CUT,        COPY,       PASTE,      REDO,       XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_APP,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),


/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | </>  |      |  :   |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   9  |  5   |  0   |  3   |  =   |-------.    ,-------|TG_RAI|  2   |  1   |  4   |  8   |      |
 * |------+------+------+------+------+------| Space |    | DVORAK|------+------+------+------+------+------|
 * |      |      |  /   |  -   |  7   |      |-------|    |-------|      |  6   |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | BSPC |ent/low| /del/low/      \tab/rai\  |spc/rai| RGUI |      | 
 *                   |      |      |      |/       /         \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  XXXXXXX, XXXXXXX, LT_GT,   XXXXXXX, KC_COLN, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_9,    KC_5,    KC_0,    KC_3,    KC_EQL,                      TG_RAI,  KC_2,    KC_1,    KC_4,    KC_8,    XXXXXXX,
  XXXXXXX, XXXXXXX, KC_SLSH, KC_MINUS,KC_7,    XXXXXXX,  KC_SPACE, DVORAK,  XXXXXXX, KC_6,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
// /* RAISE
//  * ,-----------------------------------------.                    ,-----------------------------------------.
//  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |      |  /   |  7   |  8   |  9   |  -   |                    |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//  * |      | </>  |  4   |  5   |  6   |  0   |-------.    ,-------|      |      |      |      |      |      |
//  * |------+------+------+------+------+------| Space |    | DVORAK|------+------+------+------+------+------|
//  * |      |      |  1   |  2   |  3   |  =   |-------|    |-------|      |      |      |      |      |      |
//  * `-----------------------------------------/       /     \      \-----------------------------------------'
//  *                   |      | BSPC |ent/low| /del/low/      \tab/rai\  |spc/rai| RGUI |      | 
//  *                   |      |      |      |/       /         \      \  |       |      |      |
//  *                   `----------------------------'           '------''--------------------'
//  */

// [_RAISE] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   XXXXXXX, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINUS,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, LT_GT,   KC_4,    KC_5,    KC_6,    KC_0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_EQL,     KC_SPACE, DVORAK,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                              _______, _______, _______,  _______, _______,  _______, _______, _______
// ),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |DVORAK|QWERTY| GAME |      |      |                    |      |  F1  |  F2  |  F3  |  F4  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |  F5  |  F6  |  F7  |  F8  |      |   
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  F9  |  F10 |  F11 | F12  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | BSPC |ent/low| /del/low/      \tab/rai\  |spc/rai| RGUI | RCTL | 
 *                   |      |      |      |/       /         \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, DVORAK,  QWERTY,  GAMING,  XXXXXXX, XXXXXXX,                   XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,
                             _______, _______, _______, _______, _______, _______, _______, _______
  ),

/* SYMS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |  `   |  [   |  ]   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|TG_RAI|  :   |  (   |  )   |  \   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | BOOT | Undo |  Cut | Copy | Paste| Redo |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | BSPC |ent/low| /del/low/      \tab/rai\  |spc/rai| RGUI |      | 
 *                   |      |      |      |/       /         \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMS] = LAYOUT(
  _______,  _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,     XXXXXXX,                            XXXXXXX,    KC_GRV,     KC_LBRC,    KC_RBRC,    XXXXXXX,    XXXXXXX,
  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,     XXXXXXX,                            TG_RAI,     KC_COLN,    KC_LPRN,    KC_RPRN,    KC_BSLS,    XXXXXXX,
  QK_BOOT,  UNDO,       CUT,        COPY,       PASTE,      REDO,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),



/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  B   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |GLOWER|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  Up  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | LCTL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  | Left | Down | Right|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTL | LALT |Space | /LCTL   /       \ RAISE\  | Enter|   [  |  -   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_GAME] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_B,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_GRV,
  GLOWER,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_LEFT, KC_DOWN,KC_RIGHT,
                             KC_LCTL, KC_LALT, KC_SPC, KC_LCTL, RAISE,   KC_ENT,  KC_RBRC, KC_MINS

  ),

 /* GLOWER
* ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |   6  |   7  |   8  |   9  |   0  |  B   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |Space |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |GLOWER|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  Up  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | LCTL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  | Left | Down | Right|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTL | LALT |Space | /LCTL   /       \RAISE \  |Enter |  [   |  -   |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'

 */
 [_GLOWER] = LAYOUT(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______,     _______, _______, _______, _______
 ),

 /* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |Enter | /Lower  /       \Raise \  |Space |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LALT, KC_LGUI, KC_ENT, LOWER, RAISE, KC_SPC, KC_BSPC, KC_RGUI
 )
};



void matrix_scan_user(void) {
  achordion_task();
}


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _GAME:
            autoshift_disable();
            break;
        default:
            autoshift_enable();
            break;
    }
  return update_tri_layer_state(state, _SYMS, _RAISE, _ADJUST);
}