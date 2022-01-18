#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include "Config.h"

#include <Windows.h>
#include <ostream>

class Console
{
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

	// return consoleSize;
	//
	// !!! if throw some errors, consoleSize = { 0, 0 }; !!!;
	static Size GetConsoleSize(void);

	static void ClearConsole(void);
};

#endif CONSOLE_H