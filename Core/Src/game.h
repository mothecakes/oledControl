/*
 * game.h
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_

typedef struct game{
	int health;
	int hunger;
	int happiness;

	void (*hurt)(struct game* self, int amt);
	void (*eat) (struct game* self, int amt);
	void (*play)(struct game* self, int amt);
} game;

void game_init(game* game, int health, int hunger, int happiness);

#endif /* SRC_GAME_H_ */
