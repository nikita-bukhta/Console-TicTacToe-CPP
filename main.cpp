#include "TicTacToe.h"
//#include "Title.h"

#include "Menu.h"

int main(int argc, char** argv)
{
	Menu::ShowMenu();
	system("pause");
	//while (true)
		//Console::GetConsoleSize();

	TicTacToe game;
	return game.StartGame();
}