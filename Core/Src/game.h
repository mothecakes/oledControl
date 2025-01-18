/*
 * game.h
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

typedef int Mood;
typedef int ActionType;

#define HEALTH_MAX 60
#define HUNGER_MAX 60
#define HAPPINESS_MAX   60

#define MOOD_SERIOUS 0
#define MOOD_UNHAPPY 1
#define MOOD_HAPPY   2
#define MOOD_CUTE    3

#define ACTION_EVIL 1
#define ACTION_GOOD 0

typedef struct game{
	int health;
	int hunger;
	int happiness;

	ActionType actionType = ACTION_GOOD;
	void (*switchAction)(struct game* self);

	//negative actions
	void (*hurt)(struct game* self, int amt);
	void (*starve) (struct game* self, int amt);
	void (*bore)(struct game* self, int amt);
	//positive actions
	void (*heal)(struct game* self, int amt);
	void (*eat) (struct game* self, int amt);
	void (*play)(struct game* self, int amt);

	Mood (*checkMood)(struct game* self);
} game;

void game_init(game* game, int health, int hunger, int happiness);

#endif /* SRC_GAME_H_ */
