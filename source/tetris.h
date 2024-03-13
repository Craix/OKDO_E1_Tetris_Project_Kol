
#ifndef TETRIS_H_
#define TETRIS_H_

#include "stdbool.h"
#include "lcd.h"

#include <time.h>
#include <stdio.h>

#define WinSizeX 128
#define WinSizeY 160

#define RectSize 16

#define gndSizeX (WinSizeX/RectSize)
#define gndSizeY (WinSizeY/RectSize)

struct Point
{
	int x, y;
};

//---------------------------------------------------------------------------------

void TetrisInit(SPI_Type *base);
void TetrisUpdate(float x, float y);
void TetrisButton(void);
void TetrisDraw(void);

//---------------------------------------------------------------------------------

#endif /* TETRIS_H_ */
