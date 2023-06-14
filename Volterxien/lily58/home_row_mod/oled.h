#pragma once
#include <my_custom_codes.h>
#    define MIN_WALK_SPEED      30
#    define MIN_RUN_SPEED       90

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
extern uint32_t anim_timer;

/* current frame */
extern uint8_t current_frame;

extern int   current_wpm; 
extern led_t led_usb_state;

extern bool isSneaking;
extern bool isJumping;
extern bool showedJump;
