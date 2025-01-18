/*
 * render.c
 *
 *  Created on: Jan 9, 2025
 *      Author: esqflowne
 */
#include "render.h"

const int STARTING_Y = 2;

void displayHealth(game* game) {
	const int STARTING_X = 2;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->health + STARTING_Y, Black);
}

void displayHunger(game* game) {
	const int STARTING_X = 6;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->hunger + STARTING_Y, Black);
}

void displayHappiness(game* game) {
	const int STARTING_X = 10;
	ssd1306_FillRectangle(STARTING_X, STARTING_Y, STARTING_X + 1, game->happiness + STARTING_Y, Black);
}

void displaySprite(game* game){
    Mood mood = game->checkMood(game);
    switch (mood) {
    case MOOD_SERIOUS:
      ssd1306_DrawBitmap(0,0, epd_bitmap_spriteSerious, SSD1306_WIDTH, SSD1306_HEIGHT, White);
      break;
    case MOOD_UNHAPPY:
      ssd1306_DrawBitmap(0,0, epd_bitmap_spriteUnhappy, SSD1306_WIDTH, SSD1306_HEIGHT, White);
      break;
    case MOOD_HAPPY:
      ssd1306_DrawBitmap(0,0, epd_bitmap_spriteHappy, SSD1306_WIDTH, SSD1306_HEIGHT, White);
      break;
    case MOOD_CUTE:
      ssd1306_DrawBitmap(0,0, epd_bitmap_spriteCute, SSD1306_WIDTH, SSD1306_HEIGHT, White);
      break;
    }

}

void displayScreen(game* game){
    ssd1306_Fill(Black);
    displaySprite(game);
    displayHealth(game);
    displayHunger(game);
    displayHappiness(game);
    ssd1306_UpdateScreen();
}

/*
void writeText(void* subject, char* val) {
	ssd1306_setCursor(32, 5);
	ssd1306_WriteString(val, Font_6x8, Black);
}
*/

void render_init(render* render) {
    ssd1306_Init();
	render->displayHealth = displayHealth;
	render->displayHunger = displayHunger;
	render->displayHappiness = displayHappiness;
	render->displaySprite = displaySprite;
	render->displayScreen = displayScreen;
//	render->writeText = writeText;
}
