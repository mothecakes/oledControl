/*
 * game.h
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

typedef int Mood;

#define MOOD_SERIOUS 0
#define MOOD_UNHAPPY 1
#define MOOD_HAPPY 2
#define MOOD_CUTE 3

typedef struct game{
	int health;
	int hunger;
	int happiness;

	void (*hurt)(struct game* self, int amt);
	void (*eat) (struct game* self, int amt);
	void (*play)(struct game* self, int amt);
	Mood (*checkMood)(struct game* self);
} game;

void game_init(game* game, int health, int hunger, int happiness);

#endif /* SRC_GAME_H_ */
