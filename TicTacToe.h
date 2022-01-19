#pragma once

#include "Frame.h"
#include "GameFrame.h"
#include "Console.h"
#include "Player.h"

class TicTacToe
{
private:
	GameFrame _gameFrame;
	Player::PlayingChar _calculationField;
	COORD _startCoordForGameFrame;
	Size _cellSize;

	Player player1;
	Player player2;

	short _playerTurnsCount;

	// return true if you can make a turn;
	// return false if player is nullptr;
	// return false if you don't have any free
	//	cells;
	bool MakePlayerTurn(const Player* player);
public:
	TicTacToe(void);
	// method of starting game;
	//
	// return 0 if everything is successful;
	// return 1 if something has been happened;
	bool StartGame(void);
};