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
const Letter Console::Keyboard::A(L'A', L'�');
const Letter Console::Keyboard::B(L'B', L'�');
const Letter Console::Keyboard::C(L'C', L'�');
const Letter Console::Keyboard::D(L'D', L'�');
const Letter Console::Keyboard::E(L'E', L'�');
const Letter Console::Keyboard::F(L'F', L'�');
const Letter Console::Keyboard::G(L'G', L'�');
const Letter Console::Keyboard::H(L'H', L'�');
const Letter Console::Keyboard::I(L'I', L'�');
const Letter Console::Keyboard::J(L'J', L'�');
const Letter Console::Keyboard::K(L'K', L'�');
const Letter Console::Keyboard::L(L'L', L'�');
const Letter Console::Keyboard::M(L'M', L'�');
const Letter Console::Keyboard::N(L'N', L'�');
const Letter Console::Keyboard::O(L'O', L'�');
const Letter Console::Keyboard::P(L'P', L'�');
const Letter Console::Keyboard::Q(L'Q', L'�');
const Letter Console::Keyboard::R(L'R', L'�');
const Letter Console::Keyboard::S(L'S', L'�');
const Letter Console::Keyboard::T(L'T', L'�');
const Letter Console::Keyboard::U(L'U', L'�');
const Letter Console::Keyboard::V(L'V', L'�');
const Letter Console::Keyboard::W(L'W', L'�');
const Letter Console::Keyboard::X(L'X', L'�');
const Letter Console::Keyboard::Y(L'Y', L'�');
const Letter Console::Keyboard::Z(L'Z', L'�');
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

wchar_t Console::ToLowerCase(wchar_t character)
{
	if (L'�' <= character && character <= L'�')
		character += 32;
	else if (towupper(character))
		character = towlower(character);

	return character;
}

wchar_t Console::ToUpperCase(wchar_t character)
{
	if (L'�' <= character && character <= L'�')
		character -= 32;
	else if (iswlower(character))
		character = towupper(character);

	return character;
}

wchar_t Console::GetPressedKey(void)
{
	wchar_t pressedKey = _getwch();
	// if this key is arrow;
	if (pressedKey == 224)
	{
		pressedKey = _getwch();
		return pressedKey;
	}
	else
		return pressedKey;
}

