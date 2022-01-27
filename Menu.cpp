#include "Menu.h"
#include "Console.h"

std::vector<std::wstring> Menu::_startOptions = {
	L"Start game",
	L"Settings",
	L"Exit"
};

void Menu::ShowMenu(void)
{
	for (auto option : _startOptions)
	{
		//std::wcout << option << std::endl;
	}
}
