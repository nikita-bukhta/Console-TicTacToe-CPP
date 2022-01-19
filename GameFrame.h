#pragma once
#include "Frame.h"
#include "Config.h"

class GameFrame : public Frame
{
private:
	Size _cellSize;
	
	// fill _frame with characters;
	void MakeGameFrame(void) override;
public:
	GameFrame();
	GameFrame(Size cellSize);
	GameFrame(short cellWidth, short cellHeight) : GameFrame(Size{ cellWidth, cellHeight }) {}
	GameFrame(Size gameFrameSize, Size cellSize);
	GameFrame(short gameFrameWidth, short gameFrameHeight, short cellWidth, short cellHeight) :
		GameFrame(Size{ gameFrameWidth, gameFrameHeight }, Size{ cellWidth, cellHeight }) {}

	// return count of cells in each row;
	//	but count of cells only of 1 row;
	short GetCellsCountInRow(void) const;
	// return count of cells in each column;
	//	but count of cells only of 1 row;
	short GetCellsCountInColumn(void) const;

	Size GetCellSize(void) const; 

};

