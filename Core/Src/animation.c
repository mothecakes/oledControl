/*
 * animation.c
 *
 *  Created on: Jan 26, 2025
 *      Author: esqflowne
 */

#include "animation.h"
#include "render.h"

// internal prototypes
void animation_OrderFrames(animation* self);
void animation_FindConflicts (animation* self);


// insertion sort used internally to sort frames
void animation_OrderFrames(animation* self) {
    int length = sizeof(self->frames)/sizeof(self->frames[0]);
    for (int i = 1; i < length; ++i) {
        int key = self->frames[i].key;
        int j = i - 1;

        while (j >= 0 && self->frames[j].key > key) {
            self->frames[j+1] = self->frames[j];
            j = j - 1;
        }
        self->frames[j + 1] = self->frames[i];
    }
}

// makes sure no frames have the same key
void animation_FindConflicts(animation* self) {
    int length = sizeof(self->frames)/sizeof(self->frames[0]);
    for (int i = 0; i < length - 2; i++) {
        if (self->frames[i].key == self->frames[i+1].key) {
            self->frames[i+1].key += 1; //just shifts the duplicate frame to the next.
        }
    }
    if (self->frames[length-1].key == self->frames[length-2].key) {
        self->frames[length-1].key += 1;
        self->length += 1;
    }

}

// animation play must be called
bool animation_Play(animation* self) {
    // needs to select correct frame to display at each interval
    // ie if frame1 is key0 and frame2 is key3
    // from current_frame from 0->2, frame1 should be displayed
    int frameToDisplay = 0;
    int arrLength = self->length;
    for (int i = 0; i < arrLength; i++) {
        if (self->current_frame == 0)
            break;
        if (self->current_frame < self->frames[i].key ) {
            frameToDisplay = i-1;
            break;
        }
    }
    // render
    render_DisplaySprite(&self->frames[frameToDisplay]);

    // progress the frames until the end
    self->current_frame += 1;
    if (self->current_frame >= self->length) {
        self->current_frame = 0;
        return false;
    }
    else
        return true;
}

// initializes an animation and its SpriteFrames
// TODO: make this a proper loading function. add key frame array unless you want to make a function for every thing

void animation_LoadMedia(animation list[]) {
      SpriteFrame healSF[8];
      Sprite* healSprites[] = {
              sprites_arr[heal1],sprites_arr[heal2],
              sprites_arr[smiley],sprites_arr[heal4],
              sprites_arr[heal5],sprites_arr[heal6],
              sprites_arr[heal7],sprites_arr[heal8]
      };
      int healKeys[] = {0,1,2,3,4,5,6,7};
      int healX[] = {0,0,0,0,0,0,0,0};
      int healY[] = {0,0,0,0,0,0,0,0};
      int healW[] = {32, 32, 32, 32, 32, 32, 32, 32};
      int healH[] = {32, 32, 32, 32, 32, 32, 32, 32};
      SpriteFrame_SetInit(healSF, 8, healSprites, healKeys, healX, healY, healW, healH);
      animation_Init(list, healSF, 8);
}


// constructor for singular animations
// ->keyframes will be automaticall generated
// ->length needs to be duration in frames
void animation_Init(animation* self, SpriteFrame* p_frames, int p_length) {
    self->frames = p_frames;
    self->length = p_length;

    // is_playing always inits to false. manually turning it on is required
    self->current_frame = 0;
    //self->is_playing = false;

    self->animation_Play = animation_Play;

    //ensures frames are in order
    animation_OrderFrames(self);
    //ensures frames dont take each others key frames
    animation_FindConflicts(self);
}
