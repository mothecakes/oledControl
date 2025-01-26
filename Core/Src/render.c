/*
 * render.c
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */
#include "render.h"

const int STARTING_Y = 2;


void displayHealth(const game* game) {
	const int STARTING_X = 2;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->health + STARTING_Y, Black);
}

void displayHunger(const game* game) {
	const int STARTING_X = 6;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->hunger + STARTING_Y, Black);
}

void displayHappiness(const game* game) {
	const int STARTING_X = 10;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->happiness + STARTING_Y, Black);
}

void displaySprite(const game* game){
    Mood mood = game->checkMood(game);
    switch (mood) {
    case MOOD_SERIOUS:
      ssd1306_DrawBitmap(0,0, epd_bitmap_spriteSerious, SSD1306_WIDTH, SSD1306_HEIGHT, Black);
      break;
    case MOOD_UNHAPPY:
      ssd1306_DrawBitmap(0,0, epd_bitmap_spriteUnhappy, SSD1306_WIDTH, SSD1306_HEIGHT, Black);
      break;
    case MOOD_HAPPY:
      ssd1306_DrawBitmap(0,0, epd_bitmap_spriteHappy, SSD1306_WIDTH, SSD1306_HEIGHT, Black);
      break;
    case MOOD_CUTE:
      ssd1306_DrawBitmap(0,0, epd_bitmap_spriteCute, SSD1306_WIDTH, SSD1306_HEIGHT, Black);
      break;
    }

}

void writeText(const char* str) {
	ssd1306_SetCursor(32, 5);
	ssd1306_WriteString(str, Font_6x8, Black);
}

void displayKarma(const game* game) {
    ActionType mood = game->actionType;
    const char* karma = mood ? "EVIL" : "GOOD";
    writeText(karma);
}

void displayScreen(const game* game){
    ssd1306_Fill(White);
    displaySprite(game);
    displayHealth(game);
    displayHunger(game);
    displayHappiness(game);
    displayKarma(game);
    ssd1306_UpdateScreen();
}


void render_init(render* render) {
    ssd1306_Init();
    ssd1306_Fill(Black);
	render->displayHealth = displayHealth;
	render->displayHunger = displayHunger;
	render->displayHappiness = displayHappiness;
	render->displaySprite = displaySprite;
	render->displayScreen = displayScreen;
	render->displayKarma = displayKarma;

	render->writeText = writeText;
}
