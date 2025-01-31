/*
 * sprites.h
 *
 *  Created on: Jan 7, 2025
 *      Author: Joseph Sary
 */
#include "ssd1306_conf.h"

#ifndef SPRITES_SPRITES_H_
#define SPRITES_SPRITES_H_

enum sprite {
    spriteCute,
    spriteHappy,
    spriteUnhappy,
    spriteSerious
};

typedef const unsigned char Frame;

typedef int KeyframeIndex;

typedef struct animation_frame {
    KeyframeIndex key;
    int x;
    int y;
    int w;
    int h;

    Frame* frame;
} animation_frame;


extern Frame* sprites_arr[];

Frame epd_bitmap_spriteCute [];
Frame epd_bitmap_spriteHappy [];
Frame epd_bitmap_spriteUnhappy [];
Frame epd_bitmap_spriteSerious [];
Frame smiley[];

void init_animation_frame(animation_frame* self, Frame* p_frame, KeyframeIndex p_key, int p_x, int p_y, int p_w, int p_h);


#endif /*SPRITES_SPRITES_H_*/
