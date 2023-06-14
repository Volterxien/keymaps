/**************************************************************************************************************************************************************************
 * ************************************************************************************************************************************************************************
 * **********************************************        PROCESS RECORD USER         **************************************************************************************
 * ************************************************************************************************************************************************************************
 * ************************************************************************************************************************************************************************
*/
#include QMK_KEYBOARD_H

#include "my_custom_codes.h"
#include "oled.h"
#include "features/achordion.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }
  switch(keycode){
                /* KEYBOARD PET STATUS START */


        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

            /* KEYBOARD PET STATUS END */
            // try sending tap keycode instead of more intense logic
        // case KC_BSDL:
        //     if (record->event.pressed) {
        //         uint8_t saved_mods = get_mods() & MOD_MASK_SHIFT;

        //         if (saved_mods == MOD_MASK_SHIFT) {  // Both shifts pressed
        //             register_code(KC_DEL);
        //         } else if (saved_mods) {   // One shift pressed
        //             del_mods(saved_mods);  // Remove any Shifts present
        //             register_code(KC_DEL);
        //             add_mods(saved_mods);  // Add shifts again
        //         } else {
        //             register_code(KC_BSPC);
        //         }
        //         } else {
        //             unregister_code(KC_DEL);
        //             unregister_code(KC_BSPC);
        //         }
            // break;
        case E_PGD:
            if (!record->tap.count && record->event.pressed) {
                register_code16(KC_PGDN); 
                return false;
            }
            else if (!record->tap.count){
                unregister_code16(KC_PGDN);
                return false;
            }
            return true;             
        case H_PGU:
            if (!record->tap.count && record->event.pressed) {
                register_code16(KC_PGUP); 
                return false;
            }
            else if (!record->tap.count){
                unregister_code16(KC_PGUP);
                return false;
            }
            return true;             
        case LT_GT:
            if (!record->tap.count && record->event.pressed) {
                register_code16(KC_GT); 
                return false;
            }
            else if (!record->tap.count){
                unregister_code16(KC_GT);
                return false;
            }
            if (record->tap.count && record->event.pressed) {
                register_code16(KC_LT); 
                return false;
            }
            else if (record->tap.count){
                unregister_code16(KC_LT);
                return false;
            }
            return true;
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
            // if (record->event.pressed) {
                // SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_TAP(X_DEL));
            // }
            // return false;
        case BS_SOL:
            // if (record->event.pressed) {
                // SEND_STRING(SS_LSFT(SS_TAP(X_HOME)) SS_TAP(X_DEL));
            // }
            // return false;
        case S_VIM:
            // if (record->event.pressed) {
                // SEND_STRING(SS_TAP(X_ESC) SS_LSFT(SS_TAP(X_SCLN)) SS_TAP(X_W) SS_TAP(X_ENT));
            // }
            // return false;
        case KC_ARR:
            // if (record->event.pressed) {
                // SEND_STRING("->");
            // }
            // return false;
        case NOT_EQL:
            // if (record->event.pressed) {
                // SEND_STRING(" != ");
            // }
            // return false;
            break;
        
    }
    if (record->event.pressed) {

#ifdef OLED_ENABLE
    // set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
  }