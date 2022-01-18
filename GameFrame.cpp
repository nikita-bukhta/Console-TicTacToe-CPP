#include "GameFrame.h"

#include <iostream>

void GameFrame::MakeGameFrame(void)
{
	for (short row = 0; row < _frameSize.height; ++row)
	{
		for (short column = 0; column < _frameSize.width; ++column)
		{
			// if is the first row;
			if (row == 0)
			{
				// corners;
				if (column == 0)
					_frame[row][column] = FrameChar::UpLeftCorner;
				else if (column == (_frameSize.width - 1))
					_frame[row][column] = FrameChar::UpRightCorner;
				// cross to down
				else if (column % (_cellSize.width + 1) == 0)
					_frame[row][column] = FrameChar::GoDown;
				// line;
				else
					_frame[row][column] = FrameChar::HorizontStick;
			}
			// if is the last row;
			else if (row == (_frameSize.height - 1))
			{
				// corners;
				if (column == 0)
					_frame[row][column] = FrameChar::DownLeftCorner;
				else if (column == (_frameSize.width - 1))
					_frame[row][column] = FrameChar::DownRightCorner;
				// cross down;
				else if (column % (_cellSize.width + 1) == 0)
					_frame[row][column] = FrameChar::GoUp;
				// line;
				else
					_frame[row][column] = FrameChar::HorizontStick;
			}
			else
			{
				// crosses;
				if (row % (_cellSize.height + 1) == 0)
				{
					if (column == 0)
						_frame[row][column] = FrameChar::GoRight;
					else if (column == (_frameSize.width - 1))
						_frame[row][column] = FrameChar::GoLeft;
					else if (column % (_cellSize.width + 1) == 0)
						_frame[row][column] = FrameChar::Cross;
					// line;
					else
						_frame[row][column] = FrameChar::HorizontStick;
				}
				// line
				else if (column == 0 || column == (_frameSize.width - 1) || 
					column % (_cellSize.width + 1) == 0)
					_frame[row][column] = FrameChar::VerticalStick;
				// else make empty space;
				else
					_frame[row][column] = FrameChar::Space;
			}
		}
	}
}

GameFrame::GameFrame() : Frame(Config::gameFrameStandartSize.width,
	Config::gameFrameStandartSize.height)
{
	_cellSize = { 3, 3 };
	MakeGameFrame();
}

GameFrame::GameFrame(Size cellSize) : Frame(Config::gameFrameStandartSize.width,
	Config::gameFrameStandartSize.height)
{
	_cellSize = cellSize;
	MakeGameFrame();
}

GameFrame::GameFrame(Size gameFrameSize, Size cellSize) :  Frame(gameFrameSize)
{
	_cellSize = cellSize;
	MakeGameFrame();
}

short GameFrame::GetCellsCountInRow(void)
{
	// check if all cells has their size;
	// 
	// _frameSize.width - 1	- decrease the frame line;
	// _cellSize.width + 1	- every cell has line in the end,
	//	so increase by one;
	if ((_frameSize.width - 1) % (_cellSize.width + 1) != 0)
		return (_frameSize.width - 1) / (_cellSize.width + 1) + 1;
	else
		return (_frameSize.width - 1) / (_cellSize.width + 1);
}

short GameFrame::GetCellsCountInColumn(void)
{
	// check if all cells has their size;
	// 
	// _frameSize.width - 1	- decrease the frame line;
	// _cellSize.width + 1	- every cell has line in the end,
	//	so increase by one;
	if ((_frameSize.height - 1) % (_cellSize.height + 1) != 0)
		return (_frameSize.height - 1) / (_cellSize.height + 1) + 1;
	else
		return (_frameSize.height - 1) / (_cellSize.height + 1);
}
