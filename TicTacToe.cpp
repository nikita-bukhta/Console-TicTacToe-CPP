#include "TicTacToe.h"
#include "Console.h"
#include "config.h"

#include <iostream>

TicTacToe::TicTacToe(void)
{
	//Size gameFrameSize = Config::gameFrameSize;
	_gameFrame = GameFrame(3, 3);
}

bool TicTacToe::StartGame(void)
{
	Size consoleSize;

	// throw exception, if we can't get console size
	//	and exit from this method in case of failture;
	try
	{
		consoleSize = Console::GetConsoleSize();
	}
	catch (std::exception& error)
	{
		std::cerr << error.what() << std::endl;
		return 1;
	}

	Size gameFrameSize = _gameFrame.GetFrameSize();
	// start coord for drawing gameFrame;
	Size* result = new Size((consoleSize - gameFrameSize) / 2);
	COORD startCoordForGameFrame = { result->width, result->height };
	delete result;

	_gameFrame.DrawFrame(startCoordForGameFrame);

	return 0;
}
