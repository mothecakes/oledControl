/*
 * input.c
 *
 *  Created on: Jan 20, 2025
 *      Author: Joseph Sary
 */
#include "input.h"

void switch_lights(game* Game) {
      // PA5 PA6
      if (Game->action_type == ACTION_GOOD) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
      } else {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
      }
}

void button_check( game* Game) {
      int state1 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5);
      int state2 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6);
      int state3 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8);
      int state4 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9);

      if (state1) {
    	  Game->resolve_happiness(Game);
      }
      if (state2) {
    	  Game->resolve_hunger(Game);
      }
      if (state3) {
    	  Game->resolve_health(Game);
      }
      if (state4) {
          Game->switch_action(Game);
      }

      switch_lights(Game);
}


void input_init(input* self) {
    self->button_check = button_check;
}
