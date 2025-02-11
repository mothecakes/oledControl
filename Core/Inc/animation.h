/*
 * animation.h
 *
 *  Created on: Jan 26, 2025
 *      Author: esqflowne
 */

#include "sprites.h"

#ifndef INC_ANIMATION_H_
#define INC_ANIMATION_H_

typedef int bool;

#define true 1;
#define false 0;


typedef struct animation {
	// current_frame keeps track of frames and
	int current_frame;
	int length;

	// limit is 10 frames at a max of 5 seconds per animation
	//bool is_playing;

	SpriteFrame* frames;

	bool (*animation_Play)(struct animation* self);
} animation;

typedef struct animationCfg {
    SpriteFrame* CfgSpriteFrames;
    Sprite** CfgSprites;
    int* CfgKeys;
    int* CfgX;
    int* CfgY;
    int* CfgW;
    int* CfgH;
} animationCfg;

void animation_LoadMedia(animation list[]);
void animation_Init(animation* self, SpriteFrame* p_frames, int p_length);


#endif /* INC_ANIMATION_H_ */
