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
const Letter Console::Keyboard::A(L'A', L'Ô');
const Letter Console::Keyboard::B(L'B', L'È');
const Letter Console::Keyboard::C(L'C', L'Ñ');
const Letter Console::Keyboard::D(L'D', L'Â');
const Letter Console::Keyboard::E(L'E', L'Ó');
const Letter Console::Keyboard::F(L'F', L'À');
const Letter Console::Keyboard::G(L'G', L'Ï');
const Letter Console::Keyboard::H(L'H', L'Ð');
const Letter Console::Keyboard::I(L'I', L'Ø');
const Letter Console::Keyboard::J(L'J', L'Î');
const Letter Console::Keyboard::K(L'K', L'Ë');
const Letter Console::Keyboard::L(L'L', L'Ä');
const Letter Console::Keyboard::M(L'M', L'Ü');
const Letter Console::Keyboard::N(L'N', L'Ò');
const Letter Console::Keyboard::O(L'O', L'Ù');
const Letter Console::Keyboard::P(L'P', L'Ç');
const Letter Console::Keyboard::Q(L'Q', L'É');
const Letter Console::Keyboard::R(L'R', L'Ê');
const Letter Console::Keyboard::S(L'S', L'Û');
const Letter Console::Keyboard::T(L'T', L'Å');
const Letter Console::Keyboard::U(L'U', L'Ã');
const Letter Console::Keyboard::V(L'V', L'Ì');
const Letter Console::Keyboard::W(L'W', L'Ö');
const Letter Console::Keyboard::X(L'X', L'×');
const Letter Console::Keyboard::Y(L'Y', L'Í');
const Letter Console::Keyboard::Z(L'Z', L'ß');
const Letter Console::Keyboard::ARROW_UP(72);
const Letter Console::Keyboard::ARROW_LEFT(75);
const Letter Console::Keyboard::ARROW_RIGHT(77);
const Letter Console::Keyboard::ARROW_DOWN(80);
const Letter Console::Keyboard::SPACE(32);
const Letter Console::Keyboard::ENTER(13);
#pragma endregion

bool Console::SetCursorPosition(COORD cursorCoord)
{
	// if cursor outside of console frame;
	if (GetConsoleSize() < cursorCoord)
		return false;

	_currentCursorCoord = cursorCoord;
	SetConsoleCursorPosition(_handleOut, _currentCursorCoord);

	return true;
}

bool Console::SetCursorPosition(const short coordX, const short coordY)
{
	return SetCursorPosition(COORD{ coordX, coordY });
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
	throw std::exception("Something");
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
	if (L'À' <= character && character <= L'ß')
		character += 32;
	else if (towupper(character))
		character = towlower(character);

	return character;
}

wchar_t Console::ToUpperCase(wchar_t character)
{
	if (L'à' <= character && character <= L'ÿ')
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

void Console::PutChar(wchar_t character)
{
	_putwch(character);
}

bool Console::PutChar(const wchar_t character, const COORD& charCood)
{
	auto oldCoord = GetCursorPosition();
	// if coord outside of frame;
	if (!SetCursorPosition(charCood))
		return false;

	PutChar(character);
	SetCursorPosition(oldCoord);

	return true;
}

bool Console::PutChar(const wchar_t character, const short coordX, const short coordY)
{
	return PutChar(character, COORD{ coordX, coordY });
}

// check if our coord inside some size;
bool operator<(COORD first, Size other)
{
	return first.X < other.width &&
		first.Y < other.height;
}

// check if coord outside of size;
bool operator<(Size first, COORD other)
{
	return first.width < other.X ||
		first.height < other.Y;
}

bool operator>(COORD first, Size other)
{
	return other < first;
}

bool operator>(Size first, COORD other)
{
	return other < first;
}

// check if some coord inside or in border of
//	some size;
bool operator<=(COORD first, Size other)
{
	return first.X <= other.width &&
		first.Y <= other.height;
}

// check if some coord outside or in border of 
//	some size;
bool operator<=(Size first, COORD other)
{
	return first.width <= other.X ||
		first.height <= other.Y;
}

bool operator>=(COORD first, Size other)
{
	return other <= first;
}

bool operator>=(Size first, COORD other)
{
	return other <= first;
}
