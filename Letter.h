#pragma once

#include <vector>
#include <wchar.h>

class Letter
{
private:
	std::vector<unsigned char> _possibleUnicode;

public:
	Letter(const unsigned char firstCode);
	Letter(const unsigned char firstCode, const unsigned char secondCode);

	bool operator == (const unsigned char keyCode) const;
	bool operator != (const unsigned char keyCode) const;
};
