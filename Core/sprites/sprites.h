/*
 * sprites.h
 *
 *  Created on: Jan 7, 2025
 *      Author: Joseph Sary
 */
#include "ssd1306_conf.h"

#ifndef SPRITES_SPRITES_H_
#define SPRITES_SPRITES_H_

typedef const unsigned char Frame;

typedef int KeyframeIndex;

typedef struct animation_frame {
    Frame frame;
    KeyframeIndex key;
} animation_frame;

animation_frame init_frame(Frame pFrame, KeyframeIndex pKey) {
    animation_frame final;
    final.frame = pFrame;
    final.key = pKey;
    return final;
}

extern Frame epd_bitmap_spriteCute   [SSD1306_WIDTH * SSD1306_HEIGHT];
extern Frame epd_bitmap_spriteHappy  [SSD1306_WIDTH * SSD1306_HEIGHT];
extern Frame epd_bitmap_spriteSerious[SSD1306_WIDTH * SSD1306_HEIGHT];
extern Frame epd_bitmap_spriteUnhappy[SSD1306_WIDTH * SSD1306_HEIGHT];

extern const unsigned char* epd_bitmap_allArray[4];

#endif /* SPRITES_SPRITES_H_ */
