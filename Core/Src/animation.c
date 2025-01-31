/*
 * animation.c
 *
 *  Created on: Jan 26, 2025
 *      Author: esqflowne
 */

#include "animation.h"

// constructor for singular animations
// ->keyframes will be automaticall generated
// ->length needs to be duration in frames
void animation_init(animation* self, Frame* p_frames, int p_length) {
    self->frames = p_frames;
    self->length = p_length;

    // is_playing always inits to false. manually turning it on is required
    self->current_frame = 0;
    self->is_playing = false;
}

//
void animation_order_frames(animation* self) {

}

void animation_set_init() {

}


