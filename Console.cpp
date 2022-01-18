#include "Console.h"

#include <string>

// static variables;
const HANDLE Console::_handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Console::_currentCursorCoord = COORD();
Size Console::_consoleSize = Size();

void Console::SetCursorPosition(COORD cursorCoord)
{
	_currentCursorCoord = cursorCoord;

	SetConsoleCursorPosition(_handleOut, _currentCursorCoord);
}

void Console::SetCursorPosition(const short coordX, const short coordY)
{
	_currentCursorCoord = { coordX, coordY };

	SetConsoleCursorPosition(_handleOut, _currentCursorCoord);
}

Size Console::GetConsoleSize(void)
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	// try to get screen buffer info
	if (GetConsoleScreenBufferInfo(_handleOut, &consoleInfo))
	{
		_consoleSize = {
		consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1,
		consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1
		};
	}
	else
	{
		_consoleSize = { 0, 0 };
		throw "Error: " + std::to_string(GetLastError()) +
			"try to find it on the net!";
	}

	return _consoleSize;
}

void Console::ClearConsole(void)
{
	std::system("cls");
}