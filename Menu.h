#pragma once

#include <iostream>
#include <vector>

class Menu
{
private:
	enum class Options : char
	{
		Start,
		Setting,
		Exit
	};

	static std::vector<std::wstring> _startOptions;

public:
	static void ShowMenu(void);
};

