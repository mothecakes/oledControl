/*
 * render.c
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */
#include "render.h"

const int STARTING_Y = 2;

void displayHealth(game* game) {
	const int STARTING_X = 2;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->health + STARTING_Y, Black);
}

void displayHunger(game* game) {
	const int STARTING_X = 6;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->hunger + STARTING_Y, Black);
}

void displayHappiness(game* game) {
	const int STARTING_X = 10;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->happiness + STARTING_Y, Black);
}

void render_init(render* render) {
	render->displayHealth = displayHealth;
	render->displayHunger = displayHunger;
	render->displayHappiness = displayHappiness;
}
