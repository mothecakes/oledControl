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
    spriteSerious,
    smiley
};

typedef const unsigned char Sprite;

typedef int KeyframeIndex;

typedef struct SpriteFrame {
    KeyframeIndex key;
    int x;
    int y;
    int w;
    int h;

    Sprite* sprite;
} SpriteFrame;


extern Sprite* sprites_arr[];

Sprite epd_bitmap_spriteCute [];
Sprite epd_bitmap_spriteHappy [];
Sprite epd_bitmap_spriteUnhappy [];
Sprite epd_bitmap_spriteSerious [];
Sprite smiley[];

void SpriteFrame_Init(SpriteFrame* self, Sprite* p_sprite, KeyframeIndex p_key, int p_x, int p_y, int p_w, int p_h);


#endif /*SPRITES_SPRITES_H_*/
