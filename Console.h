#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include "Config.h"
#include "Button.h"

#include <Windows.h>
#include <ostream>
#include <cstring>

class Console
{
public:
	class Keyboard	// Bind in upper case;
	{
	public:
		static const Button A;	// Bind in upper case;
		static const Button B;	// Bind in upper case;
		static const Button C;	// Bind in upper case;
		static const Button D;	// Bind in upper case;
		static const Button E;	// Bind in upper case;
		static const Button F;	// Bind in upper case;
		static const Button G;	// Bind in upper case;
		static const Button H;	// Bind in upper case;
		static const Button I;	// Bind in upper case;
		static const Button J;	// Bind in upper case;
		static const Button K;	// Bind in upper case;
		static const Button L;	// Bind in upper case;
		static const Button M;	// Bind in upper case;
		static const Button N;	// Bind in upper case;
		static const Button O;	// Bind in upper case;
		static const Button P;	// Bind in upper case;
		static const Button Q;	// Bind in upper case;
		static const Button R;	// Bind in upper case;
		static const Button S;	// Bind in upper case;
		static const Button T;	// Bind in upper case;
		static const Button U;	// Bind in upper case;
		static const Button V;	// Bind in upper case;
		static const Button W;	// Bind in upper case;
		static const Button X;	// Bind in upper case;
		static const Button Y;	// Bind in upper case;
		static const Button Z;	// Bind in upper case;
		static const Button ARROW_UP;
		static const Button ARROW_LEFT;
		static const Button ARROW_RIGHT;
		static const Button ARROW_DOWN;
		static const Button SPACE;
		static const Button ENTER;
	};

private:

	static const HANDLE _handleOut;		// our console;
	static COORD _currentCursorCoord;	// where is our cursor;

	static void GetScreenBufferInfo(CONSOLE_SCREEN_BUFFER_INFO& screenBuf);

	static void SetScreenBufferInfo(CONSOLE_SCREEN_BUFFER_INFO& screenBuf);

	static CONSOLE_SCREEN_BUFFER_INFO GetScreenBufferInfo();

public:
	// set cursor position in console;
	//
	// cursorCoord - where you want to place your cursor;
	//
	// return true if everything is ok;
	// return false if COORD outside of game frame;
	static bool SetCursorPosition(COORD cursorCoord);
	// set cursor position in console;
	//
	// coordX && coordY - where you want to place your cursor;
	//
	// return true if everything is ok;
	// return false if COORD outside of game frame;
	static bool SetCursorPosition(const short coordX, const short coordY);

	static COORD GetCursorPosition(void);

	// return consoleSize;
	//
	// !!! if throw some errors, consoleSize = { 0, 0 }; !!!;
	static Size GetConsoleSize(void);

	static void ClearConsole(void);

	// Convert character to lower case;
	static wchar_t ToLowerCase(wchar_t character);

	// Convert character to upper case;
	static wchar_t ToUpperCase(wchar_t character);

	// return key you pressed key;
	static wchar_t GetPressedKey(void);

	// putchar there where is your cursor;
	//
	// character - what you want to put;
	static void PutChar(wchar_t character);

	// put char in indicated coordinates;
	// 
	// character - what you want to put;
	// charCoord - where you want to place your coord;
	// 
	// return true if everything is ok;
	// return false if COORD outside of game frame;
	static bool PutChar(const wchar_t character, const COORD& charCoord);

	static void PutString(std::wstring& text);

	static bool PutString(std::wstring& text, const COORD& startStringCoord);
	// put char in indicated coordinates;
	// 
	// character - what you want to put;
	// coordX, coordY - where you want to place your coord;
	// 
	// return true if everything is ok;
	// return false if COORD outside of game frame;
	static bool PutChar(const wchar_t character, const short coordX, const short coordY);

	static void UpdateConsoleFont(void);
	
	static void SetFullScreen(bool fullScreen);
};

bool operator < (COORD first, Size other);
bool operator < (Size first, COORD other);
bool operator > (COORD first, Size other);
bool operator > (Size first, COORD other);

bool operator <= (COORD first, Size other);
bool operator <= (Size first, COORD other);
bool operator >= (COORD first, Size other);
bool operator >= (Size first, COORD other);

#endif CONSOLE_H