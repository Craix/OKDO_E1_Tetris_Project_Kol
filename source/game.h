#ifndef GAME_H_
#define GAME_H_

#include "lcd.h"
#include "tetris.h"

void gameInit(SPI_Type *base);
void gameUpdate(float x, float y);
void gameButton(void);
void gameDraw(void);

#endif /* GAME_H_ */
