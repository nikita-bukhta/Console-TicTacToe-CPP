#include "Letter.h"

#include <iostream>

Letter::Letter(const unsigned char firstCode)
{
    _possibleUnicode.push_back(firstCode);
}

Letter::Letter(const unsigned char firstCode, const unsigned char secondCode) : Letter(firstCode)
{
    _possibleUnicode.push_back(secondCode);
}

bool Letter::operator==(const unsigned char keyCode) const
{
    for (auto& code : _possibleUnicode)
    {
        if (code == keyCode)
            return true;
    }

    return false;
}

bool Letter::operator!=(const unsigned char keyCode) const
{
    for (auto& code : _possibleUnicode)
    {
        if (code != keyCode)
            return true;
    }

    return false;
}
