#include "TicTacToe.h"
#include "Console.h"

#include <conio.h>
#include <iostream>
#include <string>

/*
* TODO:
*	сделать нормальный бинд для каждой клавиши с несколькими
*	значениями
*/

int main(int argc, char** argv)
{
	TicTacToe game;
	return game.StartGame();
}