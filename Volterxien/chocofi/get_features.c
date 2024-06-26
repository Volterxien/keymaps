/**************************************************************************************************************************************************************************
 * ************************************************************************************************************************************************************************
 * **********************************************       FEATURE MODIFICATION         **************************************************************************************
 * ************************************************************************************************************************************************************************
 * ************************************************************************************************************************************************************************
*/

#include QMK_KEYBOARD_H

#include "my_custom_codes.h"

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
        case T_RAISE:
        case E_SYMS:
        case BS_LOW:
        case T_SYMS:
        case E_RAISE:
            return TAPPING_TERM - 25;
        case E_PGD:
        case H_PGU:
            return AUTO_SHIFT_TIMEOUT + 20;
        case LT_GT:
            return AUTO_SHIFT_TIMEOUT;

        // semimak hrm
        case HOME_SN:
        case HOME_SE:
            return TAPPING_TERM - 55;
        case HOME_SS:
        case HOME_SI:
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM; 
    }

}


uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case E_SYMS:
        case E_RAISE:
            return QUICK_TAP_TERM - 55;
        case BS_LOW:
        case S_RAISE:
        case E_LOWER:
        case BS_SYMS:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_8:
        case KC_9:
        case KC_2:
            return AUTO_SHIFT_TIMEOUT + 10;
        default:
            return get_generic_autoshift_timeout();
    }
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_1:
            return true;
        case KC_2:
            return true;
        case KC_3:
            return true;
        case KC_4:
            return true;
        case KC_5:
            return true;
        case KC_6:
            return true;
        case KC_7:
            return true;
        case KC_8:
            return true;
        case KC_0:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_1:
            register_code16((!shifted) ? KC_1 : KC_ASTR);
            break;
        case KC_2:
            register_code16((!shifted) ? KC_2 : KC_DLR);
            break;
        case KC_3:
            register_code16((!shifted) ? KC_3 : KC_CIRC);
            break;
        case KC_4:
            register_code16((!shifted) ? KC_4 : KC_DOT);
            break;
        case KC_5:
            register_code16((!shifted) ? KC_5 : KC_AT);
            break;
        case KC_6:
            register_code16((!shifted) ? KC_6 : KC_AMPR);
            break;
        case KC_7:
            register_code16((!shifted) ? KC_7 : KC_PERC);
            break;
        case KC_8:
            register_code16((!shifted) ? KC_8 : KC_RPRN);
            break;
        case KC_0:
            register_code16((!shifted) ? KC_0 : KC_HASH);
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
        case KC_1:
            unregister_code16((!shifted) ? KC_1 : KC_ASTR);
            break;
        case KC_2:
            unregister_code16((!shifted) ? KC_2 : KC_DLR);
            break;
        case KC_3:
            unregister_code16((!shifted) ? KC_3 : KC_CIRC);
            break;
        case KC_4:
            unregister_code16((!shifted) ? KC_4 : KC_DOT);
            break;
        case KC_5:
            unregister_code16((!shifted) ? KC_5 : KC_AT);
            break;
        case KC_6:
            unregister_code16((!shifted) ? KC_6 : KC_AMPR);
            break;
        case KC_7:
            unregister_code16((!shifted) ? KC_7 : KC_PERC);
            break;
        case KC_8:
            unregister_code16((!shifted) ? KC_8 : KC_RPRN);
            break;
        case KC_0:
            unregister_code16((!shifted) ? KC_0 : KC_HASH);
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
        case KC_ENT:
        case KC_ESC:
            return COMBO_TERM + 10; // 50
        case KC_MINUS:
            return COMBO_TERM + 10;
        case KC_RGUI:
            return COMBO_TERM + 20;
        case TG_RAI:
            return COMBO_TERM + 40;
        default:
            return COMBO_TERM;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true;

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    if(combo->keycode == KC_BSPC) {return false;}
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

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable combo `SOME_COMBO` on layer `_LAYER_A` */
        switch (combo_index){
            //dvorak combos
            // case ESC_COMBO ... ENT_COMBO:
            //     if ((get_highest_layer(layer_state)) == _DVORAK){
            //         return true;
            //     }
            //     return false;
            case SESC_COMBO ... SENT_COMBO:
                if ((get_highest_layer(layer_state)) == _SEMIMAK){
                    return true;
                }
                return false;
            case TG_RAISE_COMBO:
                return true;
            // case QW_ESC_COMBO:
            //     if ((get_highest_layer(layer_state)) == _QWERTY){
            //         return true;
            //     }
            //     return false; 
            // default:
            //     if (((get_highest_layer(layer_state)) == _DVORAK) || (get_highest_layer(layer_state) == _SEMIMAK) || (get_highest_layer(layer_state) == _GRAPHITE)){
            //         return true;
            //     }
            //     else {return false;}

        }
        return true;
}


void housekeeping_task_user(void){
    if (last_input_activity_elapsed() > 5000) {
        if((get_highest_layer(layer_state)) == _RAISE) {
            layer_invert(_RAISE);
        }
    }
}
