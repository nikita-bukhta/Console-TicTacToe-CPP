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
	// Set console title;
	SetConsoleTitleW(L"Tic Tac Toe by Nikita Bukhta");

	Size pastConsoleSize = Size();
	Size currentConsoleSize;

	while (true)
	{
		// throw exception, if we can't get console size
		//	and exit from this method in case of failture;
		try
		{
			currentConsoleSize = Console::GetConsoleSize();
		}
		catch (std::exception& error)
		{
			std::cerr << error.what() << std::endl;
			return 1;
		}

		// if console size has been changed
		//	redraw all;
		if (pastConsoleSize != currentConsoleSize)
		{
			Size gameFrameSize = _gameFrame.GetFrameSize();
			// start coord for drawing gameFrame;
			Size* result = new Size((currentConsoleSize - gameFrameSize) / 2);
			COORD startCoordForGameFrame = { result->width, result->height };

			delete result;

			// redrawing;
			Console::ClearConsole();
			_gameFrame.DrawFrame(startCoordForGameFrame);

			// set current size;
			pastConsoleSize = currentConsoleSize;
		}
	}

	return 0;
}
