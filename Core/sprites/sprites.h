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
    smiley,
    heal1,
    heal2,
    heal3,
    heal4,
    heal5,
    heal6,
    heal7,
    heal8
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

/*
Sprite epd_bitmap_spriteCute [128 * 64];
Sprite epd_bitmap_spriteHappy [128 * 64];
Sprite epd_bitmap_spriteUnhappy [128 * 64];
Sprite epd_bitmap_spriteSerious [128 * 64];
Sprite epd_bitmap_smiley[10 * 10];
*/

void SpriteFrame_Init(SpriteFrame* self, Sprite* p_sprite, KeyframeIndex p_key, int p_x, int p_y, int p_w, int p_h);
void SpriteFrame_SetInit(SpriteFrame* sfArray, int len, Sprite* sprites[], int* keysArr,
		int* xArr, int* yArr, int* wArr, int* hArr);

#endif /*SPRITES_SPRITES_H_*/
