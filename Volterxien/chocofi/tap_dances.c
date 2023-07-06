//check this link for more information if needed esp for better hold behaviour: https://docs.qmk.fm/#/feature_tap_dance?id=example-4
#include "my_custom_codes.h"


    
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    else if (state->count == 2) {
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else return TD_UNKNOWN;
}

static td_tap_t gt_lt_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void gt_lt_finished(tap_dance_state_t *state, void *user_data) {
    gt_lt_tap_state.state = cur_dance(state);
    switch (gt_lt_tap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_LT); break;
        case TD_SINGLE_HOLD: register_code16(KC_GT); break;
        case TD_DOUBLE_HOLD: register_code16(KC_LT); break;
        case TD_DOUBLE_SINGLE_TAP: 
        case TD_DOUBLE_TAP: register_code16(KC_LT); register_code16(KC_LT); break;
        default: break;
    }
}

void gt_lt_reset(tap_dance_state_t *state, void *user_data) {
    switch (gt_lt_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_LT); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_GT); break;
        case TD_DOUBLE_HOLD: unregister_code16(KC_LT); break;
        case TD_DOUBLE_SINGLE_TAP: 
        case TD_DOUBLE_TAP: unregister_code16(KC_LT); break;
        default: break;
    }
    gt_lt_tap_state.state = TD_NONE;
}

static td_tap_t h_pgup_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void h_pgup_finished(tap_dance_state_t *state, void *user_data) {
    h_pgup_tap_state.state = cur_dance(state);
    switch (h_pgup_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_HOME); break;
        case TD_SINGLE_HOLD: register_code(KC_PGUP); break;
        default: break;
    }
}

void h_pgup_reset(tap_dance_state_t *state, void *user_data) {
    switch (h_pgup_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_HOME); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_PGUP); break;
        default: break;
    }
    h_pgup_tap_state.state = TD_NONE;
}

static td_tap_t e_pgdn_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};


void e_pgdn_finished(tap_dance_state_t *state, void *user_data) {
    e_pgdn_tap_state.state = cur_dance(state);
    switch (e_pgdn_tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_END); break;
        case TD_SINGLE_HOLD: register_code(KC_PGDN); break;
        default: break;
    }
}

void e_pgdn_reset(tap_dance_state_t *state, void *user_data) {
    switch (e_pgdn_tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_END); break;
        case TD_SINGLE_HOLD: unregister_code(KC_PGDN); break;
        default: break;
    }
    e_pgdn_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_GTLT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gt_lt_finished, gt_lt_reset),
    [TD_E_PD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, e_pgdn_finished, e_pgdn_reset),
    [TD_H_PU] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, h_pgup_finished, h_pgup_reset),     
    [TD_INS_PAUSE] = ACTION_TAP_DANCE_DOUBLE(KC_BRK, KC_INS),

};
