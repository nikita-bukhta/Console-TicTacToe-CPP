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
	class Keyboard
	{
	public:
		static const Letter A;
		static const Letter B;
		static const Letter C;
		static const Letter D;
		static const Letter E;
		static const Letter F;
		static const Letter G;
		static const Letter H;
		static const Letter I;
		static const Letter J;
		static const Letter K;
		static const Letter L;
		static const Letter M;
		static const Letter N;
		static const Letter O;
		static const Letter P;
		static const Letter Q;
		static const Letter R;
		static const Letter S;
		static const Letter T;
		static const Letter U;
		static const Letter V;
		static const Letter W;
		static const Letter X;
		static const Letter Y;
		static const Letter Z;
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
	static unsigned char ToLowerCase(unsigned char character);

	// Convert character to upper case;
	static unsigned char ToUpperCase(unsigned char character);

	// return key you pressed key;
	static unsigned char GetPressedKey(void);
};

#endif CONSOLE_H