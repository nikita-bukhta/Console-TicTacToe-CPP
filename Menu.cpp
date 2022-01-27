#include "Menu.h"
#include "Console.h"

std::vector<std::wstring> Menu::_startOptions = {
	L"Start game",
	L"Settings",
	L"Exit"
};

void Menu::ShowMenu(void)
{
	auto consoleSize = Console::GetConsoleSize();

	short startOptionNumber = 0;
	for (auto option : _startOptions)
	{
		Console::PutString(option, COORD{ short((consoleSize.width - option.size()) / 2),
			short((consoleSize.height / 2 - startOptionNumber)) 
			});

		startOptionNumber += 2;
	}
}
