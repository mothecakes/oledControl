/*
 * animation.h
 *
 *  Created on: Jan 26, 2025
 *      Author: esqflowne
 */

#ifndef INC_ANIMATION_H_
#define INC_ANIMATION_H_

typedef int bool;

#include "sprites.h"

typedef struct s_animation {
	// current_frame keeps track of frames and
	int current_frame;
	int length;
	// limit is 10 frames at a max of 5 seconds per animation
	Frame frames[];

} animation;



#endif /* INC_ANIMATION_H_ */
