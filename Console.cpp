#include "Console.h"

#include <string>
#include <iostream>
#include <conio.h>	// _getch()

// TODO:
//	1) Make getting russian character WITHOUT
//		destruction of game frame ( I am shocked by that too :( );
//	2) Make method to increase the font size;
//

// static variables;
const HANDLE Console::_handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Console::_currentCursorCoord = COORD();
Size Console::_consoleSize = Size();

#pragma region Keybord Keys
const Letter Console::Keyboard::A('A', '�');
const Letter Console::Keyboard::B('B', '�');
const Letter Console::Keyboard::C('C', '�');
const Letter Console::Keyboard::D('D', '�');
const Letter Console::Keyboard::E('E', '�');
const Letter Console::Keyboard::F('F', '�');
const Letter Console::Keyboard::G('G', '�');
const Letter Console::Keyboard::H('H', '�');
const Letter Console::Keyboard::I('I', '�');
const Letter Console::Keyboard::J('J', '�');
const Letter Console::Keyboard::K('K', '�');
const Letter Console::Keyboard::L('L', '�');
const Letter Console::Keyboard::M('M', '�');
const Letter Console::Keyboard::N('N', '�');
const Letter Console::Keyboard::O('O', '�');
const Letter Console::Keyboard::P('P', '�');
const Letter Console::Keyboard::Q('Q', '�');
const Letter Console::Keyboard::R('R', '�');
const Letter Console::Keyboard::S('S', '�');
const Letter Console::Keyboard::T('T', '�');
const Letter Console::Keyboard::U('U', '�');
const Letter Console::Keyboard::V('V', '�');
const Letter Console::Keyboard::W('W', '�');
const Letter Console::Keyboard::X('X', '�');
const Letter Console::Keyboard::Y('Y', '�');
const Letter Console::Keyboard::Z('Z', '�');
const Letter Console::Keyboard::ARROW_UP(72);
const Letter Console::Keyboard::ARROW_LEFT(75);
const Letter Console::Keyboard::ARROW_RIGHT(77);
const Letter Console::Keyboard::ARROW_DOWN(80);
const Letter Console::Keyboard::SPACE(32);
const Letter Console::Keyboard::ENTER(13);
#pragma endregion

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

COORD Console::GetCursorPosition(void)
{
	CONSOLE_SCREEN_BUFFER_INFO  screenBuffer;
	if (GetConsoleScreenBufferInfo(_handleOut, &screenBuffer))
		return screenBuffer.dwCursorPosition;
	else
		return { 0, 0 };

}

Size Console::GetConsoleSize(void)
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	// try to get screen buffer info
	if (GetConsoleScreenBufferInfo(_handleOut, &consoleInfo))
	{
		_consoleSize = {
		short(consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1),
		short(consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1)
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

unsigned char Console::ToLowerCase(unsigned char character)
{
	if (isupper(unsigned char(character))) // ASCII
		character = tolower(character);
	else if (character > 127 && character < 144)
		character += 32;
	else if (character > 143 && character < 160)	
		character += 80;
	else if (character == 240)
		character += 1;

	return character;
}

unsigned char Console::ToUpperCase(unsigned char character)
{
	if (character > 159 && character < 176)
		character -= 32;
	else if (character > 223 && character < 240)
		character -= 80;
	else if (character == 241)
		character -= 1;
	else if (islower(unsigned char(character))) // ASCII
		character = toupper(character);

	return character;
}

unsigned char Console::GetPressedKey(void)
{
	unsigned char pressedKey = _getch();
	// if this key is arrow;
	if (pressedKey == 224)
	{
		pressedKey = _getch();
		return pressedKey;
	}
	else
		return ToUpperCase(pressedKey);
}

