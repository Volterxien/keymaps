#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "my_custom_codes.h"
#include "oled.h"



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
 * `-----------------------------------------/       /     \      \----------------------------------------'
 *                   |      |      |bpc/low|/ent/sym/       \tab/rai\   | Space |      |      | 
 *                   |      |      |      |/       /          \      \  |       |      |      |
 *                   `----------------------------'            '------''--------------------'
 */

//  [_DVORAK] = LAYOUT(
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    XXXXXXX,
//   XXXXXXX, HOME_A,  HOME_O,  HOME_E,  HOME_U,  KC_I,                      KC_D,    HOME_H,  HOME_T,  HOME_N,  HOME_S,  XXXXXXX,
//   XXXXXXX, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    XXXXXXX, XXXXXXX, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    XXXXXXX,
//                              XXXXXXX, XXXXXXX, BS_LOW,  T_SYMS,  E_RAISE, KC_SPC,  XXXXXXX, XXXXXXX
// ),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | Lead |      |-------.    ,-------| Pgup | Left | Down | Right| Pgdn |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste| Redo |-------|    |-------|      | Menu |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |  DEL |bpc/low|/ent/sym/       \tab/rai\   | Space | RGUI |      | 
 *                   |      |      |      |/       /          \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_LEAD, XXXXXXX,                   H_PGU,   KC_LEFT, KC_DOWN, KC_RIGHT, E_PGD,  XXXXXXX,
  XXXXXXX, UNDO,    CUT,     COPY,    PASTE,   REDO,    XXXXXXX, XXXXXXX, XXXXXXX, KC_APP,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, _______, _______, _______
),


/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | </>  |   :  |      |      |                    |      |      | GAME |QWERTY|DVORAK|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   9  |  5   |  0   |  3   |  =   |-------.    ,-------|TG_RAI|  2   |  1   |  4   |  8   |      |
 * |------+------+------+------+------+------| Space |    | DVORAK|------+------+------+------+------+------|
 * |      |      |  /   |  -   |  7   |      |-------|    |-------|      |  6   |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |bpc/low|/ent/sym/       \tab/rai\   | Space |      |      | 
 *                   |      |      |      |/       /          \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  XXXXXXX, XXXXXXX, LT_GT,   KC_COLN, XXXXXXX, XXXXXXX,                   GRAPH, SEMI, GAMING,  QWERTY,  DVORAK,  XXXXXXX,
  XXXXXXX, KC_9,    KC_5,    KC_0,    KC_3,    KC_EQL,                    TG_RAI,  KC_2,    KC_1,    KC_4,    KC_8,    XXXXXXX,
  XXXXXXX, XXXXXXX, KC_SLSH, KC_MINS, KC_7,    XXXXXXX, KC_SPC,  DVORAK,  XXXXXXX, KC_6,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                             _______, _______, _______, _______, _______, _______, _______, _______
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
// *                   |      |      |bpc/low|/ent/sym/       \tab/rai\   | Space |      |      | 
// *                   |      |      |      |/       /          \      \  |       |      |      |
//  *                   `----------------------------'           '------''--------------------'
//  */

// [_RAISE] = LAYOUT(
//   _______,    _______,    _______,    _______,    _______,    _______,                     _______, _______, _______, _______, _______, _______,
//   XXXXXXX,    KC_SLSH,    KC_7,       KC_8,       KC_9,       KC_MINUS,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX,    LT_GT,      KC_4,       KC_5,       KC_6,       KC_0,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX,    XXXXXXX,    KC_1,       KC_2,       KC_3,       KC_EQL,      KC_SPACE,    DVORAK,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                              _______, _______, _______,  _______, _______,  _______, _______, _______
// ),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |   
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |bpc/low|/ent/sym/       \tab/rai\   | Space |      |      | 
 *                   |      |      |      |/       /          \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
/*  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
                             _______, _______, _______, _______, _______, _______, _______, _______
  ),
*/
/* SYMS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |BRKINS|                    |      |  `   |  [   |  ]   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |PRNSRC|-------.    ,-------|      |  :   |  (   |  )   |  \   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 | F12  |SCRLK |-------|    |-------|      | ../  |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |bpc/low|/ent/sym/       \tab/rai\   | Space |      |      | 
 *                   |      |      |      |/       /          \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMS] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   BRK_INS,                   XXXXXXX, KC_GRV, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_PSCR,                   XXXXXXX, KC_COLN, KC_LPRN, KC_RPRN, KC_BSLS, XXXXXXX,
  XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_SCRL, XXXXXXX, XXXXXXX, XXXXXXX, PREVDIR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, _______, _______, _______
),


// Consider putting space on right hand thumb keys
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
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    B_DVRK, KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_LEFT, KC_DOWN,KC_RIGHT,
                             KC_LCTL, KC_LALT, KC_SPC, KC_LCTL, RAISE,   KC_ENT,  KC_RBRC, KC_MINS

  ),

 /* GLOWER
* ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |   6  |   7  |   8  |   9  |   0  |  B   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |Space |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |GLOWER|      |      |      |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  Up  |  '   |
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
  _______, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______,                       _______, _______, _______, _______, _______, _______,
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
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  //KC_LCTL, HOME_QA, HOME_QS, HOME_QD, HOME_QF, KC_G,                     KC_H,    HOME_QJ, HOME_QK, HOME_QL, HOME_QSC,KC_QUOT,
  KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,                     KC_H,    KC_J, KC_K, KC_L, KC_SCLN,KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_LALT, KC_LGUI, BS_LOW, T_SYMS, E_RAISE, KC_SPC, KC_BSPC, KC_RGUI
 ),
//  [_GRAPHITE] = LAYOUT(
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, KC_B, KC_L, KC_D,  KC_W,    KC_Z,                      KC_QUOT,    KC_F,    KC_O,    KC_U,    KC_J,    XXXXXXX,
//   XXXXXXX, HOME_GN,  HOME_GR,  HOME_GT,  HOME_GS,  KC_G,                      KC_Y,    HOME_GH,  HOME_GA,  HOME_GE,  HOME_GI,  XXXXXXX,
//   XXXXXXX, KC_Q,    KC_X,    KC_M,    KC_C, KC_V,    XXXXXXX, XXXXXXX, KC_K,    KC_P,    KC_DOT,    KC_COMM,    KC_SCLN,    XXXXXXX,
//                              XXXXXXX, XXXXXXX, BS_LOW,  T_SYMS,  E_RAISE, KC_SPC,  XXXXXXX, XXXXXXX
//  ),
 [_SEMIMAK] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F, KC_L, KC_H,  KC_V,    KC_Z,                      KC_QUOT,    KC_W,    KC_U,    KC_O,    KC_Y,    XXXXXXX,
  XXXXXXX, HOME_SS,  HOME_SR,  HOME_SN,  HOME_ST,  KC_K,                      KC_C,    HOME_SD,  HOME_SE,  HOME_SA,  HOME_GI,  XXXXXXX,
  XXXXXXX, KC_X, KC_J,    KC_B,    KC_M,    KC_Q,    XXXXXXX, XXXXXXX, KC_P,    KC_G,    KC_COMM,    KC_DOT,    KC_SCLN,    XXXXXXX,
                             XXXXXXX, XXXXXXX, BS_LOW,  T_SYMS,  E_RAISE, KC_SPC,  XXXXXXX, XXXXXXX
 ),

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
    return state;
  //uncomment for adjust layer
  //return update_tri_layer_state(state, _SYMS, _RAISE, _ADJUST);
}
