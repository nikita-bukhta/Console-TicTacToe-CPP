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
	GameFrame(Size cellSize, Size gameFrameSize);
	GameFrame(short cellWidth, short cellHeight, short gameFrameWidth, short gameFrameHeight) :
		GameFrame(Size{ cellWidth, cellHeight }, Size{ gameFrameWidth, gameFrameHeight }) {}

	// return count of cells in each row;
	//	but count of cells only of 1 row;
	short GetCellsCountInRow(void) const;
	// return count of cells in each column;
	//	but count of cells only of 1 row;
	short GetCellsCountInColumn(void) const;

	Size GetCellSize(void) const; 

};

