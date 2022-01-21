#include "TicTacToe.h"
#include "Console.h"
#include "config.h"

#include <iostream>
#include <conio.h>

// TODO:
//	1) Make method for different modes
//	2) Make Bind for Space (make a turn)
//

bool TicTacToe::MakePlayerTurn(const Player* player)
{
	if (player == nullptr)
		return false;

	COORD currentCursorPosition = Console::GetCursorPosition();
	Size gameFrameSize = _gameFrame.GetFrameSize();
	// distance between centre of two cells = lenght of side of cell
	// + 1 to calculate the frame;
	Size step = _gameFrame.GetCellSize() + 1;

	while (true)
	{
		wchar_t pressedKey = Console::ToUpperCase(Console::GetPressedKey()); // pressed key
		if (pressedKey == 0)
			continue;
		// move RIGHT;
		else if (Console::Keyboard::D == pressedKey || 
			Console::Keyboard::ARROW_RIGHT == pressedKey)
		{
			// check the right border;
			if ((currentCursorPosition.X + step.width) <= (_startCoordForGameFrame.X + gameFrameSize.width))
			{
				currentCursorPosition.X += step.width;
				Console::SetCursorPosition(currentCursorPosition);
			}
		}
		// move DOWN;
		else if (Console::Keyboard::S == pressedKey ||
			Console::Keyboard::ARROW_DOWN == pressedKey)
		{
			// check the buttom border;
			if ((currentCursorPosition.Y + step.height) <= (_startCoordForGameFrame.Y + gameFrameSize.height))
			{
				currentCursorPosition.Y += step.height;
				Console::SetCursorPosition(currentCursorPosition);
			}
		}
		// move LEFT
		else if (Console::Keyboard::A == pressedKey ||
			Console::Keyboard::ARROW_LEFT == pressedKey)
		{
			// check the left border;
			if ((currentCursorPosition.X - step.width) >= _startCoordForGameFrame.X)
			{
				currentCursorPosition.X -= step.width;
				Console::SetCursorPosition(currentCursorPosition);
			}
		}
		// move UP
		else if (Console::Keyboard::W == pressedKey ||
			Console::Keyboard::ARROW_UP == pressedKey)
		{
			// check the top border;
			if ((currentCursorPosition.Y - step.height) >= _startCoordForGameFrame.Y)
			{
				currentCursorPosition.Y -= step.height;
				Console::SetCursorPosition(currentCursorPosition);
			}
		}
	}

	return true;
}

TicTacToe::TicTacToe(void)
{
	_cellSize = Config::gameFrameCellStandartSize;
	_gameFrame = GameFrame(_cellSize);
	_calculationField = { Player::PlayingChar::Empty };

	player1.SetPlayingChar(Player::PlayingChar::X);
	player2.SetPlayingChar(Player::PlayingChar::Y);

	_playerTurnsCount = short();
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
#pragma region Changing drawing position
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
			_startCoordForGameFrame = { result->width, result->height };

			delete result;

			// redrawing;
			Console::ClearConsole();
			_gameFrame.DrawFrame(_startCoordForGameFrame);

			// set current size;
			pastConsoleSize = currentConsoleSize;
		}
#pragma endregion
#pragma region PlayerTurn

		// if first player must turn;
		Player* currentPlayer = nullptr;
		_playerTurnsCount % 2 == 0 ?
			currentPlayer = &player1 :
			currentPlayer = &player2;
		
		// Get centre of the first game cell;
		Console::SetCursorPosition(
			_startCoordForGameFrame.X + (_cellSize.width + 1) / 2,
			_startCoordForGameFrame.Y + (_cellSize.height + 1) / 2
		);
		MakePlayerTurn(currentPlayer);
#pragma endregion
	}

	return 0;
}
