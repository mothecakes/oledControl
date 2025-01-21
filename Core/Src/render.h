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
#include "ssd1306_fonts.h"

typedef struct {
	void (*displayHealth)(const game* game);
	void (*displayHunger)(const game* game);
	void (*displayHappiness)(const game* game);
	void (*displaySprite)(const game* game);
	void (*displayScreen)(const game* game);
	void (*displayKarma)(const game* game);

	void (*writeText)(const char* str);

} render;

void render_init(render* render);

#endif /* SRC_RENDER_H_ */
