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

void bore(game* game, int amount) {
	if (game->happiness >= amount) {
		game->happiness -= amount;
	}
	else {
		game->happiness = 0;
	}
}

void starve(game* game, int amount) {
	if (game->hunger >= amount) {
		game->hunger -= amount;
	}
	else {
		game->hunger = 0;
	}
}

void heal(game* game, int amount) {
	if ((game->health + amount) > HEALTH_MAX) {
		game->health = HEALTH_MAX;
	}
	else {
		game->health += amount
	}
}

void eat(game* game, int amount) {
	if ((game->hunger + amount) > HUNGER_MAX) {
		game->hunger = HUNGER_MAX;
	}
	else {
		game->hunger += amount
	}
}

void play(game* game, int amount) {
	if ((game->happiness + amount) > HAPPINESS_MAX) {
		game->happiness = HAPPINESS_MAX;
	}
	else {
		game->happiness += amount
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

void switchAction(struct game* self) {
	if (actionType == ACTION_GOOD) {
		actionType = ACTION_EVIL;
	}
	else
		actionType = ACTION_GOOD;
}

void game_init(game* game, int health, int hunger, int happiness) {
	game->health = health;
	game->hunger = hunger;
	game->happiness = happiness;

	game->switchAction = switchAction;

	game->hurt = hurt;
	game->bore = bore;
	game->starve = starve;
	game->heal = heal;
	game->eat = eat;
	game->play = play;


	game->checkMood = checkMood;
}



