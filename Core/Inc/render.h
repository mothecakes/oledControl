/*
 * render.h
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */

#ifndef SRC_RENDER_H_
#define SRC_RENDER_H_

#include "game.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "animation.h"

typedef struct {
	void (*display_health)(const game* game);
	void (*display_hunger)( game* game);
	void (*display_happiness)( game* game);
	void (*display_sprite)( game* game);
	void (*display_screen)( game* game);
	void (*display_karma)( game* game);

	bool (*play_animation)(animation* self);

	void (*write_text)(char* str);

} render;

void render_init(render* render);

#endif /* SRC_RENDER_H_ */
