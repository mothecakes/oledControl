/*
 * render.h
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */

#ifndef SRC_RENDER_H_
#define SRC_RENDER_H_

#include "game.h"
#include "sprites.h"
#include "ssd1306.h"

typedef struct {
	void (*displayHealth)(game* game);
	void (*displayHunger)(game* game);
	void (*displayHappiness)(game* game);
	void (*displaySprite)(game* game);
	void (*displayScreen)(game* game);

} render;

void render_init(render* render);

#endif /* SRC_RENDER_H_ */
