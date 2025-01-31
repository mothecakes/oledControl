/*
 * render.h
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */

#ifndef SRC_RENDER_H_
#define SRC_RENDER_H_

#include "game.h"

void render_DisplayHealth( game* game);
void render_DisplayHunger( game* game);
void render_DisplayHappiness( game* game);
void render_DisplaySprite( animation* ani);
void render_DisplayScreen( game* game);
void render_DisplayKarma( game* game);
void render_DisplayWriteText(char* str);

void render_init();

#endif /* SRC_RENDER_H_ */
