#include "Title.h"

/*
const Title::Letter _lA = {
	L"     ",
	L"     ",
	L"  ▃  ",
	L" ▟▃▙ ",
	L"▟   ▙"
};

Title::Title(std::wstring title)
{
	for (wchar_t letter : title)
	{
		switch (letter)
		{
		case L'a':
			_title.push_back(_lA);
		case L'c':
			_title.push_back(_lC);
			break;
		case L'e':
			_title.push_back(_lE);
			break;
		case L'i':
			_title.push_back(_lI);
			break;
		case L'o':
			_title.push_back(_lO);
			break;
		case L'T':
			_title.push_back(_uT);
			break;
		}
	}
}

void Title::ShowTitle(void)
{
	for (auto letter : _title)
		std::wcout << letter;
}

std::wostream& operator<<(std::wostream& wout, Title::Letter object)
{
	for (auto row : object._letter)
	{
		for (auto value : row)
			wout << value;

		wout << std::endl;
	}

	return wout;
}

Title::Letter::Letter(std::wstring* bigLetter)
{
	for (int i = 0; i < 5; ++i)
	{
		//_letter[i] = bigLetter[i];
	}
}
*/