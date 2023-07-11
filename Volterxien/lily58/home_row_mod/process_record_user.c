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
    // tap_dance_action_t *action;
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
            case PREVDIR:
                if (record->event.pressed) {
                    SEND_STRING("../");
                }
                return false;
            case QWERTY:
                if (record->event.pressed) {
                    layer_move(_QWERTY);
                }
                return false;
            case GAMING:
                if (record->event.pressed) {
                    layer_move(_GAME);
                    }
                    return false;
            case DVORAK:
                if  (record->event.pressed) {
                    layer_move(_DVORAK);
                }
                    return false;
            case SEMI:
                if  (record->event.pressed) {
                    layer_move(_SEMIMAK);
                }
                    return false;
            case GRAPH:
                if  (record->event.pressed) {
                    layer_move(_GRAPHITE);
                }
                    return false;
        }
        // if (record->event.pressed) {
// 
    // #ifdef OLED_ENABLE
    //     // set_keylog(keycode, record);
    // #endif
    //     // set_timelog();
    // }
    return true;
    }