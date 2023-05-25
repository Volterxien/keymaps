#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "keycodes.h"


enum COMBOS{
    ESC_COMBO,
    SLSH_COMBO,
    DSH_COMBO,
    EXCL_COMBO,
    EQL_COMBO,
    ARR_COMBO,
    // RES1_COMBO,
    // RES2_COMBO,
    // RES3_COMBO,
    // RES4_COMBO,

    COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;





const uint16_t PROGMEM esc_combo[] = {KC_COMMA, KC_QUOT, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM excl_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM eql_combo[] = {KC_J, KC_Q, COMBO_END};
const uint16_t PROGMEM arr_combo[] = {HOME_A, HOME_O, COMBO_END};
const uint16_t PROGMEM dsh_combo[] = {HOME_N, HOME_T, COMBO_END};
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
    [ARR_COMBO]     = COMBO(arr_combo, KC_ARR),
};


/**************************************************************************************************************************************************************************
 * ************************************************************************************************************************************************************************
 * **********************************************       KEYMAPS         ***************************************************************************************************
**************************************************************************************************************************************************************************
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
 *                   | LAlt | BSPC |ent/low| /del/low/      \tab/rai\  |spc/rai| RGUI | RCTL | 
 *                   |      |      |      |/       /         \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_DVORAK] = LAYOUT(
  XXXXXXX,   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  XXXXXXX,   KC_QUOT,   KC_COMMA,   KC_DOT,     KC_P,       KC_Y,                       KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       XXXXXXX,
  XXXXXXX,   HOME_A,    HOME_O,     HOME_E,     HOME_U,     KC_I,                       KC_D,       HOME_H,     HOME_T,     HOME_N,     HOME_S,     XXXXXXX,
  XXXXXXX,   KC_SCLN,   KC_Q,       KC_J,       KC_K,       KC_X,   XXXXXXX,    XXXXXXX, KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       XXXXXXX,
                                    KC_LALT,    KC_BSPC,    E_LOWER,D_SYMS,    T_RAISE,S_RAISE,    KC_RGUI,    KC_RCTL
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  `   |   [  |  ]   |      |                    |      | Pgup |  Up  | Pgdn |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  :   |  \   |   (  |   )  |      |-------.    ,-------| Home | Left | Down | Right| End  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | BOOT | Undo |  Cut | Copy | Paste| Redo |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | BSPC |ent/low| /del/low/      \tab/rai\  |spc/rai| RGUI | RCTL | 
 *                   |      |      |      |/       /         \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______,  _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
  XXXXXXX,  XXXXXXX,    KC_GRV,     KC_LBRC,    KC_RBRC,    XXXXXXX,                            XXXXXXX,    KC_PGUP,    KC_UP,      KC_PGDN,    XXXXXXX,    XXXXXXX,
  XXXXXXX,  KC_COLN,    KC_BSLS,    KC_LPRN,    KC_RPRN,    XXXXXXX,                            KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_END,     XXXXXXX,
  QK_BOOT,  UNDO,       CUT,        COPY,       PASTE,      REDO,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |   .  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |  2   |  3   |  4   |  5   |-------.    ,-------|   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------| Space |    | DVORAK|------+------+------+------+------+------|
 * |      |      |  <   |  >   |  :   |      |-------|    |-------|      |   =  |   -  |  /   |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | BSPC |ent/low| /del/low/      \tab/rai\  |spc/rai| RGUI | RCTL | 
 *                   |      |      |      |/       /         \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, KC_DOT,  XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_COLN, XXXXXXX, KC_SPACE, DVORAK,   XXXXXXX, KC_EQL,  KC_MINUS,KC_SLASH,XXXXXXX, XXXXXXX,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |DVORAK|QWERTY| GAME |      |      |                    |      |  F1  |  F2  |  F3  |  F4  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |DELEOL|BSSOL | SVIM |      |      |-------.    ,-------|      |  F5  |  F6  |  F7  |  F8  |      |   
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
  XXXXXXX, DEL_EOL, BS_SOL,  S_VIM, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  ),

/* SYMS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |  [   |  ]   |   `  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |  (   |  )   |  :   |  \   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | BOOT | Undo |  Cut | Copy | Paste| Redo |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | BSPC |ent/low| /del/low/      \tab/rai\  |spc/rai| RGUI | RCTL | 
 *                   |      |      |      |/       /         \      \  |       |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMS] = LAYOUT(
  _______,  _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,     XXXXXXX,                            XXXXXXX,    KC_LBRC,    KC_RBRC,    KC_GRV,     XXXXXXX,    XXXXXXX,
  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,   XXXXXXX,     XXXXXXX,                            XXXXXXX,    KC_LPRN,    KC_RPRN,    KC_COLN,    KC_BSLS,    XXXXXXX,
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
  KC_ESC,   KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,                     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
                            _______,_______, _______, _______,      _______,  _______, _______, _______
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


/**************************************************************************************************************************************************************************
 * ************************************************************************************************************************************************************************
 * **********************************************       FEATURE MODIFICATION         **************************************************************************************
**************************************************************************************************************************************************************************
 * ************************************************************************************************************************************************************************
*/

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record){
    switch(keycode){
        case HOME_E:
        case HOME_T:
            return TAPPING_TERM - 65;
        case HOME_A:
        case HOME_S:   
            return TAPPING_TERM + 30;
        case S_RAISE:
            return TAPPING_TERM + 40;                                                                         
        default:
            return TAPPING_TERM; 
    }

}


uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case S_RAISE:
        case E_LOWER:
        case D_SYMS:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_1:
        case KC_5:
        case KC_6:
        case KC_0:
            return AUTO_SHIFT_TIMEOUT + 10;
        default:
            return get_generic_autoshift_timeout();
    }
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_9:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_9:
            register_code16((!shifted) ? KC_9 : KC_DOT);
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_9:
            unregister_code16((!shifted) ? KC_9 : KC_DOT);
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    switch (combo->keycode) {
        case KC_ESC:
            return 50;
        case KC_MINUS:
            return COMBO_TERM - 20;
        default:
            return COMBO_TERM;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true;

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;
}


bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_QUOT:
        case KC_LPRN:
        case KC_RPRN:
        case KC_UP:
        case KC_DOWN:
        case KC_LEFT:
        case KC_RIGHT:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}




layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      30
#    define MIN_RUN_SPEED       90

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

int   current_wpm = 0; 
led_t led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {/* 'walk1', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'walk2', 32x22px */
                                                    {
                                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'bark1', 32x22px */
                                                    {
                                                        0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    },

                                                    /* 'bark2', 32x22px */
                                                    {
                                                        0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
                                                     },

                                                     /* 'sneak2', 32x22px */
                                                     {
                                                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                     }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock || is_caps_word_on()) {
            oled_write_raw_P(bark[current_frame], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[current_frame], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[current_frame], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[current_frame], ANIM_SIZE);
        }
    }

#    if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }
#    endif

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

/* KEYBOARD PET END */

void print_mods(void){
    uint8_t mod_state = get_mods();
    if (mod_state & MOD_MASK_CTRL){
        oled_write("C", false);
    }
    else{
        oled_write(" ", false);
    }

    if (mod_state & MOD_MASK_SHIFT){
        oled_write("S", false);
    }
    else{
        oled_write(" ", false);
    }

    if (mod_state & MOD_MASK_ALT){
        oled_write("A", false);
    }
    else{
        oled_write(" ", false);
    }

    if (mod_state & MOD_MASK_GUI){
        oled_write("G", false);
    }
    else{
        oled_write(" ", false);
    }
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return OLED_ROTATION_270;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);




void oled_render_layer_state(void) {
    // oled_write_P(PSTR("Layer: "), false);
            oled_set_cursor(0,0);
            if (!(get_mods() & (MOD_MASK_CTRL))){
                isSneaking = false;
            }
            else {
                isSneaking = true;
            }

    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write("Dvork", false);
            // oled_write_ln_P(PSTR("Dvorak"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwert"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adj"), false);
            break;
        case _SYMS:
            oled_write_ln_P(PSTR("Syms"), false);
            break;
        case _GLOWER:
            oled_write_ln_P(PSTR("Glowr"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);

    }
}

bool oled_task_user(void) {
  current_wpm   = get_current_wpm();
  led_usb_state = host_keyboard_led_state();

  if (is_keyboard_master()) {
        oled_render_layer_state();
        print_mods();
        // oled_render_keylog_r2g();
        // oled_write_ln(read_keylog(), false);
        // oled_write_ln(read_keylogs(), false);
        render_luna(0,13);
    } else {
        // oled_render_logo();
        oled_write(read_logo(), false);
        
    }
    return false;
}
#endif // OLED_ENABLE


/**************************************************************************************************************************************************************************
 * ************************************************************************************************************************************************************************
 * **********************************************        PROCESS RECORD USER         **************************************************************************************
**************************************************************************************************************************************************************************
 * ************************************************************************************************************************************************************************
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }
  switch(keycode){
                /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

            /* KEYBOARD PET STATUS END */
        case QWERTY:
            if (record->event.pressed) {
                // set_single_persistent_default_layer(_QWERTY);
                layer_move(_QWERTY);
            }
            return false;
        case GAMING:
            if (record->event.pressed) {
                // set_single_persistent_default_layer(_GAME);
                layer_move(_GAME);
                }
                return false;
        case DVORAK:
            if  (record->event.pressed) {
                // set_single_persistent_default_layer(_DVORAK);
                layer_move(_DVORAK);
            }
                return false;
        case DEL_EOL:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_TAP(X_DEL));
            }
            return false;
        case BS_SOL:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_TAP(X_DEL));
            }
            return false;
        case S_VIM:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) SS_LSFT(SS_TAP(X_SCLN)) SS_TAP(X_W) SS_TAP(X_ENT));
            }
            return false;
        case KC_ARR:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        
    }
    if (record->event.pressed) {

#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
  }

