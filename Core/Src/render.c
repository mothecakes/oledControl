/*
 * render.c
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */
#include "render.h"

#include "animation.h"
#include "sprites.h"


const int STARTING_Y = 2;


void render_DisplayHealth(const game* game) {
	const int STARTING_X = 2;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->health + STARTING_Y, Black);
}

void render_DisplayHunger( game* game) {
	const int STARTING_X = 6;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->hunger + STARTING_Y, Black);
}

void render_DisplayHappiness( game* game) {
	const int STARTING_X = 10;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->happiness + STARTING_Y, Black);
}
/*
void render_DisplaySprite(game* game){
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
*/

void render_DisplaySprite(SpriteFrame* frame) {
    SpriteFrame current = frame;
    ssd1306_DrawBitmap(current.x, current.y, current, current.w, current.h, White);
}

void render_WriteText(char* str) {
	ssd1306_SetCursor(32, 5);
	ssd1306_WriteString(str, Font_6x8, Black);
}

void render_DisplayKarma( game* game) {
    ActionType mood = game->action_type;
    char* karma = mood ? "EVIL" : "GOOD";
    write_text(karma);
}

void render_DisplayScreen( game* game){
    ssd1306_Fill(White); //consider delegating to a render_start func
    // render_Display_sprite(game);
    render_DisplayHealth(game);       //
    render_DisplayHunger(game);       // consider putting this in a render_Display stats func in game
    render_DisplayHappiness(game);    //
    render_DisplayKarma(game);        //
    ssd1306_UpdateScreen(); //consider delegating to a render_end func
}

void render_Init() {
    ssd1306_Init();
    ssd1306_Fill(Black);
}
