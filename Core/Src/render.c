/*
 * render.c
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */
#include "render.h"

#include "sprites.h"


const int STARTING_Y = 2;


void display_health(const game* game) {
	const int STARTING_X = 2;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->health + STARTING_Y, Black);
}

void display_hunger( game* game) {
	const int STARTING_X = 6;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->hunger + STARTING_Y, Black);
}

void display_happiness( game* game) {
	const int STARTING_X = 10;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->happiness + STARTING_Y, Black);
}

void display_sprite(game* game){
    Mood mood = game->check_mood(game);
    switch (mood) {
    case MOOD_SERIOUS:
      ssd1306_DrawBitmap(0,0, sprites_arr[spriteSerious], SSD1306_WIDTH, SSD1306_HEIGHT, White);
      break;
    case MOOD_UNHAPPY:
      ssd1306_DrawBitmap(0,0, sprites_arr[spriteUnhappy], SSD1306_WIDTH, SSD1306_HEIGHT, White);
      break;
    case MOOD_HAPPY:
      ssd1306_DrawBitmap(0,0, sprites_arr[spriteHappy], SSD1306_WIDTH, SSD1306_HEIGHT, White);
      break;
    case MOOD_CUTE:
      ssd1306_DrawBitmap(0,0, sprites_arr[spriteCute], SSD1306_WIDTH, SSD1306_HEIGHT, White);
      break;
    }

}

void write_text(char* str) {
	ssd1306_SetCursor(32, 5);
	ssd1306_WriteString(str, Font_6x8, Black);
}

void display_karma( game* game) {
    ActionType mood = game->action_type;
    char* karma = mood ? "EVIL" : "GOOD";
    write_text(karma);
}

void display_screen( game* game){
    ssd1306_Fill(White);
    display_sprite(game);
    display_health(game);
    display_hunger(game);
    display_happiness(game);
    display_karma(game);
    ssd1306_UpdateScreen();
}

bool play_animation(animation* self) {
    bool success = true;
    if (!self->is_playing)
        return !success;

    animation_frame current = self->frames[self->current_frame];

    ssd1306_Fill(Black);
    ssd1306_DrawBitmap(
            current.x, current.y,
            current.frame,
            current.w, current.h,
            White);
    ssd1306_UpdateScreen();
    return success;
}

void render_init(render* render) {
    ssd1306_Init();
    ssd1306_Fill(Black);
	render->display_health = display_health;
	render->display_hunger = display_hunger;
	render->display_happiness = display_happiness;
	render->display_sprite = display_sprite;
	render->display_screen = display_screen;
	render->display_karma = display_karma;

	render->play_animation = play_animation;

	render->write_text = write_text;
}
