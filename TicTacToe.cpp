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

	// if key was pushed;
	if (_kbhit())
	{
		COORD currentCursorPosition = Console::GetCursorPosition();
		Size gameFrameSize = _gameFrame.GetFrameSize();
		// distance between centre of two cells = lenght of side of cell
		// + 1 to calculate the frame;
		Size step = _gameFrame.GetCellSize() + 1;

		wchar_t pressedKey = Console::GetPressedKey(); // pressed key
		// move RIGHT;
		if (Console::Keyboard::D == pressedKey || 
			Console::Keyboard::ARROW_RIGHT == pressedKey)
		{
			// check the right border;
			if ((currentCursorPosition.X + step.width) <= (_startCoordForGameFrame.X + gameFrameSize.width))
				ChoosePlayingCell(++_currentCellNumber);	// move cursor right
		}
		// move DOWN;
		else if (Console::Keyboard::S == pressedKey ||
			Console::Keyboard::ARROW_DOWN == pressedKey)
		{
			// check the buttom border;
			if ((currentCursorPosition.Y + step.height) <= (_startCoordForGameFrame.Y + gameFrameSize.height))
			{
				// Move cell number to the next row (down).
				//	Number that lower by rows must be greater by count of cells in row;
				_currentCellNumber += _gameFrame.GetCellsCountInRow();
				ChoosePlayingCell(_currentCellNumber);
			}
		}
		// move LEFT
		else if (Console::Keyboard::A == pressedKey ||
			Console::Keyboard::ARROW_LEFT == pressedKey)
		{
			// check the left border;
			if ((currentCursorPosition.X - step.width) >= _startCoordForGameFrame.X)
				ChoosePlayingCell(--_currentCellNumber);	// move cursor left;
		}
		// move UP
		else if (Console::Keyboard::W == pressedKey ||
			Console::Keyboard::ARROW_UP == pressedKey)
		{
			// check the top border;
			if ((currentCursorPosition.Y - step.height) >= _startCoordForGameFrame.Y)
			{
				// Move cell number to the past row (up).
				//	Number that higher by rows must be lower by count of cells in row;
				_currentCellNumber -= _gameFrame.GetCellsCountInRow();
				ChoosePlayingCell(_currentCellNumber);
			}
		}
		else if (Console::Keyboard::SPACE == pressedKey)
		{
			COORD currentCellIndex = {
				_currentCellNumber % 3,
				_currentCellNumber / 3
			};
			if (_calculationField[currentCellIndex.Y][currentCellIndex.X] == Player::PlayingChar::Empty)
			{
				Console::PutChar(wchar_t(player->GetPlayingChar()));
				_calculationField[currentCellIndex.Y][currentCellIndex.X] = player->GetPlayingChar();
				++_playerTurnsCount;
			}
		}
	}

	return true;
}

void TicTacToe::ChoosePlayingCell(short cellNumber)
{
	// row and column where is cell;
	short row = cellNumber / _gameFrame.GetCellsCountInColumn();
	short column = cellNumber % _gameFrame.GetCellsCountInRow();

	// first get centre of the first cell, than get the cell
	//	starting from the first cell;
	Console::SetCursorPosition(
		_startCoordForGameFrame.X + (_cellSize.width + 1) / 2 + (column * _cellSize.width) + column,
		_startCoordForGameFrame.Y + (_cellSize.height + 1) / 2 + (row * _cellSize.height) + row
	);
}

TicTacToe::TicTacToe(void)
{
	_cellSize = Config::gameFrameCellStandartSize;
	_gameFrame = GameFrame(_cellSize);
	_currentCellNumber = 0;

	_rowsCount = _gameFrame.GetCellsCountInRow();
	_columnsCount = _gameFrame.GetCellsCountInColumn();
	_calculationField = new Player::PlayingChar*[_rowsCount];
	for (short row = 0; row < _rowsCount; ++row)
	{
		_calculationField[row] = new Player::PlayingChar[_columnsCount];
		for (short column = 0; column < _columnsCount; ++column)
			_calculationField[row][column] = Player::PlayingChar::Empty;
	}

	player1.SetPlayingChar(Player::PlayingChar::X);
	player2.SetPlayingChar(Player::PlayingChar::Y);

	_playerTurnsCount = short();
}

bool TicTacToe::CheckDrawingPosition(void)
{
	// for check changing console size;
	static Size pastConsoleSize;
	static Size currentConsoleSize;
 
	currentConsoleSize = Console::GetConsoleSize();


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

	return 1;
}

TicTacToe::~TicTacToe(void)
{
	if (_calculationField != nullptr)
	{
		for (short row = 0; row < _rowsCount; ++row)
		{
			delete[] _calculationField[row];
			_calculationField[row] = nullptr;
		}

		_calculationField = nullptr;
	}
}

bool TicTacToe::StartGame(void)
{
	// Set console title;
	SetConsoleTitleW(L"Tic Tac Toe by Nikita Bukhta");

	while (true)
	{
		// throw exception, if we can't get console size
		//	and exit from this method in case of failture;
		
		try
		{
			CheckDrawingPosition();
		}
		catch (std::exception& error)
		{
			std::cerr << error.what() << std::endl;
			return 0;
		}
#pragma region PlayerTurn

		// if first player must turn;
		Player* currentPlayer = nullptr;
		_playerTurnsCount % 2 == 0 ?
			currentPlayer = &player1 :
			currentPlayer = &player2;
		
		// Get centre of the first game cell;
		if (_currentCellNumber == 0)
		{
			ChoosePlayingCell(_currentCellNumber);
			//_currentCellNumber = 0;
		}
		MakePlayerTurn(currentPlayer);
#pragma endregion
	}

	return 0;
}
