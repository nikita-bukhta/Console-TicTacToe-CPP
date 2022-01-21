#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include "Config.h"
#include "Letter.h"

#include <Windows.h>
#include <ostream>
#include <cstring>

class Console
{
public:
	class Keyboard	// Bind in upper case;
	{
	public:
		static const Letter A;	// Bind in upper case;
		static const Letter B;	// Bind in upper case;
		static const Letter C;	// Bind in upper case;
		static const Letter D;	// Bind in upper case;
		static const Letter E;	// Bind in upper case;
		static const Letter F;	// Bind in upper case;
		static const Letter G;	// Bind in upper case;
		static const Letter H;	// Bind in upper case;
		static const Letter I;	// Bind in upper case;
		static const Letter J;	// Bind in upper case;
		static const Letter K;	// Bind in upper case;
		static const Letter L;	// Bind in upper case;
		static const Letter M;	// Bind in upper case;
		static const Letter N;	// Bind in upper case;
		static const Letter O;	// Bind in upper case;
		static const Letter P;	// Bind in upper case;
		static const Letter Q;	// Bind in upper case;
		static const Letter R;	// Bind in upper case;
		static const Letter S;	// Bind in upper case;
		static const Letter T;	// Bind in upper case;
		static const Letter U;	// Bind in upper case;
		static const Letter V;	// Bind in upper case;
		static const Letter W;	// Bind in upper case;
		static const Letter X;	// Bind in upper case;
		static const Letter Y;	// Bind in upper case;
		static const Letter Z;	// Bind in upper case;
		static const Letter ARROW_UP;
		static const Letter ARROW_LEFT;
		static const Letter ARROW_RIGHT;
		static const Letter ARROW_DOWN;
		static const Letter SPACE;
		static const Letter ENTER;
	};

private:

	static const HANDLE _handleOut;		// our console;
	static COORD _currentCursorCoord;	// where is our cursor;
	static Size _consoleSize;

public:
	// set cursor position in console;
	//
	// cursorCoord - where you want to place your cursor;
	static void SetCursorPosition(COORD cursorCoord);
	// set cursor position in console;
	//
	// coordX && coordY - where you want to place your cursor;
	static void SetCursorPosition(const short coordX, const short coordY);

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
};

#endif CONSOLE_H