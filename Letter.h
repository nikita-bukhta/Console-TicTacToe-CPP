#pragma once

#include <vector>
#include <wchar.h>

class Letter
{
private:
	std::vector<wchar_t> _possibleUnicode;

public:
	Letter(const wchar_t firstCode);
	Letter(const wchar_t firstCode, const wchar_t secondCode);

	bool operator == (wchar_t keyCode) const;
	bool operator != (wchar_t keyCode) const;
};
