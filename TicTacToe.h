#pragma once

#include "Frame.h"
#include "GameFrame.h"
#include "Console.h"

class TicTacToe
{
private:
	GameFrame _gameFrame;
public:
	TicTacToe(void);
	// method of starting game;
	//
	// return 0 if everything is successful;
	// return 1 if something has been happened;
	bool StartGame(void);
};