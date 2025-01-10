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

Mood checkMood(struct game* self) {
    int overall = 0;
    overall += self->health;
    overall += self->hunger;
    overall += self->happiness;
    overall /= 3;

    if (overall <= 15){
        return MOOD_SERIOUS;
    }
    if (overall <= 30){
        return MOOD_UNHAPPY;
    }
    if (overall <= 45){
        return MOOD_HAPPY;
    }
    else{
        return MOOD_CUTE;
    }
}

void game_init(game* game, int health, int hunger, int happiness) {
	game->health = health;
	game->hunger = hunger;
	game->happiness = happiness;

	game->hurt = hurt;
	game->play = play;
	game->eat = eat;
	game->checkMood = checkMood;

}



