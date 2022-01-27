#pragma once

#include <vector>
#include <wchar.h>

class Button
{
private:
	std::vector<wchar_t> _possibleUnicode;

public:
	// firstCode - first possible symbol (for example G);
	Button(const wchar_t firstCode);
	// firstCode - first possible symbol (for example G)
	// secondCord - second possible symbol (for example Ï)
	//
	// G and Ï placed on the same button;
	Button(const wchar_t firstCode, const wchar_t secondCode);

	bool operator == (wchar_t keyCode) const;
	bool operator != (wchar_t keyCode) const;
};
