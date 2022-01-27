#include "Console.h"

#include <string>
#include <iostream>
#include <conio.h>	// _getch()

// TODO:
//	2) Make method to increase the font size;
//

// static variables;
const HANDLE Console::_handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Console::_currentCursorCoord = COORD();

#pragma region Keybord Keys
const Button Console::Keyboard::A(L'A', L'Ô');
const Button Console::Keyboard::B(L'B', L'È');
const Button Console::Keyboard::C(L'C', L'Ñ');
const Button Console::Keyboard::D(L'D', L'Â');
const Button Console::Keyboard::E(L'E', L'Ó');
const Button Console::Keyboard::F(L'F', L'À');
const Button Console::Keyboard::G(L'G', L'Ï');
const Button Console::Keyboard::H(L'H', L'Ð');
const Button Console::Keyboard::I(L'I', L'Ø');
const Button Console::Keyboard::J(L'J', L'Î');
const Button Console::Keyboard::K(L'K', L'Ë');
const Button Console::Keyboard::L(L'L', L'Ä');
const Button Console::Keyboard::M(L'M', L'Ü');
const Button Console::Keyboard::N(L'N', L'Ò');
const Button Console::Keyboard::O(L'O', L'Ù');
const Button Console::Keyboard::P(L'P', L'Ç');
const Button Console::Keyboard::Q(L'Q', L'É');
const Button Console::Keyboard::R(L'R', L'Ê');
const Button Console::Keyboard::S(L'S', L'Û');
const Button Console::Keyboard::T(L'T', L'Å');
const Button Console::Keyboard::U(L'U', L'Ã');
const Button Console::Keyboard::V(L'V', L'Ì');
const Button Console::Keyboard::W(L'W', L'Ö');
const Button Console::Keyboard::X(L'X', L'×');
const Button Console::Keyboard::Y(L'Y', L'Í');
const Button Console::Keyboard::Z(L'Z', L'ß');
const Button Console::Keyboard::ARROW_UP(72);
const Button Console::Keyboard::ARROW_LEFT(75);
const Button Console::Keyboard::ARROW_RIGHT(77);
const Button Console::Keyboard::ARROW_DOWN(80);
const Button Console::Keyboard::SPACE(32);
const Button Console::Keyboard::ENTER(13);
#pragma endregion

void Console::GetScreenBufferInfo(CONSOLE_SCREEN_BUFFER_INFO& screenBuf)
{
	if (!GetConsoleScreenBufferInfo(_handleOut, &screenBuf))
		throw std::exception("Can't get screen buffer info! Error" + GetLastError());

}

void Console::SetScreenBufferInfo(CONSOLE_SCREEN_BUFFER_INFO& screenBuf)
{
}

CONSOLE_SCREEN_BUFFER_INFO Console::GetScreenBufferInfo()
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetScreenBufferInfo(consoleInfo);

	return consoleInfo;
}

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
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetScreenBufferInfo(consoleInfo);

	Size consoleSize = {
		short(consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1),
		short(consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1)
	};

	return consoleSize;
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

bool Console::PutChar(const wchar_t character, const COORD& charCoord)
{
	auto oldCoord = GetCursorPosition();
	// if coord outside of frame;
	if (!SetCursorPosition(charCoord))
		return false;

	PutChar(character);
	SetCursorPosition(oldCoord);

	return true;
}

void Console::PutString(std::wstring& text)
{
	for (auto& c : text)
		PutChar(c);
}

bool Console::PutString(std::wstring& text, const COORD& startStringCoord)
{
	auto oldCoord = GetCursorPosition();
	// if coord outside of frame;
	if (!SetCursorPosition(startStringCoord))
		return false;

	PutString(text);
	SetCursorPosition(oldCoord);

	return true;
}

bool Console::PutChar(const wchar_t character, const short coordX, const short coordY)
{
	return PutChar(character, COORD{ coordX, coordY });
}

void Console::UpdateConsoleFont(void)
{
	static auto standartConsoleSize = GetConsoleSize();
	static auto pastConsoleSize = standartConsoleSize;
	auto currentConsoleSize = GetConsoleSize();

	if (pastConsoleSize == currentConsoleSize)
		return;

	CONSOLE_FONT_INFOEX font = { sizeof(font) };

	if (!GetCurrentConsoleFontEx(_handleOut, false, &font))
		throw std::exception("Error with getting font info EX. Error " + GetLastError());

	static auto standartFont = font;
	font.dwFontSize = {
		//0,
		short(float(currentConsoleSize.width) / standartConsoleSize.width * font.dwFontSize.X),
		short(float(currentConsoleSize.height) / standartConsoleSize.height * font.dwFontSize.Y),
	};

	if (!SetCurrentConsoleFontEx(_handleOut, false, &font))
		throw std::exception("Error with setting console font. Error " + GetLastError());

	pastConsoleSize = currentConsoleSize;
}

void Console::SetFullScreen(bool fullScreen)
{
	system("mode con COLS=700");
	fullScreen ?
		SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000) :
		ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
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
