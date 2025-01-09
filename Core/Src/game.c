/*
 * game.c
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */

#include "game.h"

void hurt(game* game, int amount) {
	if (game->health >= amount) {
		game->health -= amount;
	}
	else {
		game->health = 0;
	}
}

void play(game* game, int amount) {
	if (game->happiness >= amount) {
		game->happiness -= amount;
	}
	else {
		game->happiness = 0;
	}
}

void eat(game* game, int amount) {
	if (game->hunger >= amount) {
		game->hunger -= amount;
	}
	else {
		game->hunger = 0;
	}
}
void game_init(game* game, int health, int hunger, int happiness) {
	game->health = health;
	game->hunger = hunger;
	game->happiness = happiness;

	game->hurt = hurt;
	game->play = play;
	game->eat = eat;

}



