/*
 * input.h
 *
 *  Created on: Jan 20, 2025
 *      Author: Joseph Sary
 */

#ifndef SRC_INPUT_H_
#define SRC_INPUT_H_

#include "main.h"
#include "game.h"
#include "render.h"

typedef struct Input{
    // check pins and call correct functions
    void (*button_check)( game* Game);
    // changes lights for karma actions
    // void switch_lights(const game* Game);
} input;

void input_init(input* self);

#endif /* SRC_INPUT_H_ */
