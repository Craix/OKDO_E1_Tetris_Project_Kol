#include "game.h"

void gameInit(SPI_Type *base)
{
	TetrisInit(base);
}

void gameUpdate(float x, float y)
{
	TetrisUpdate(x, y);
}

void gameButton(void)
{
	TetrisButton();
}

void gameDraw(void)
{
	TetrisDraw();
}
