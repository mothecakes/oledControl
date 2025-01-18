/*
 * game.c
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */

#include "game.h"

//
// Negative Actions
//

static void hurt(game* game, int amount) {
	if (game->health >= amount) {
		game->health -= amount;
	}
	else {
		game->health = 0;
	}
}

static void bore(game* game, int amount) {
	if (game->happiness >= amount) {
		game->happiness -= amount;
	}
	else {
		game->happiness = 0;
	}
}

static void starve(game* game, int amount) {
	if (game->hunger >= amount) {
		game->hunger -= amount;
	}
	else {
		game->hunger = 0;
	}
}

//
// Positive Actions
//

static void heal(game* game, int amount) {
	if ((game->health + amount) > HEALTH_MAX) {
		game->health = HEALTH_MAX;
	}
	else {
		game->health += amount;
	}
}

static void eat(game* game, int amount) {
	if ((game->hunger + amount) > HUNGER_MAX) {
		game->hunger = HUNGER_MAX;
	}
	else {
		game->hunger += amount;
	}
}

static void play(game* game, int amount) {
	if ((game->happiness + amount) > HAPPINESS_MAX) {
		game->happiness = HAPPINESS_MAX;
	}
	else {
		game->happiness += amount;
	}
}

//
//  Returns current mood of the mon
//

static Mood checkMood(struct game* self) {
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
	if (self->actionType == ACTION_GOOD) {
		self->actionType = ACTION_EVIL;
	}
	else
		self->actionType = ACTION_GOOD;
}

void resolveHunger(game* self) {
	self->actionType == ACTION_GOOD ? eat(self, ACTION_AMT) : starve(self, ACTION_AMT);
}

void resolveHealth(game* self) {
	self->actionType == ACTION_GOOD ? heal(self, ACTION_AMT) : hurt(self, ACTION_AMT);
}

void resolveHappiness(game* self) {
	self->actionType == ACTION_GOOD ? play(self, ACTION_AMT) : bore(self, ACTION_AMT);
}




void game_init(game* game, int health, int hunger, int happiness) {
	game->health = health;
	game->hunger = hunger;
	game->happiness = happiness;

	game->actionType = ACTION_EVIL;
	game->switchAction = switchAction;

	game->resolveHunger = resolveHunger;
	game->resolveHappiness = resolveHappiness;
	game->resolveHealth = resolveHealth;

	game->checkMood = checkMood;

}



