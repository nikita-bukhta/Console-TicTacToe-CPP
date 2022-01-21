#include "Letter.h"
#include "Console.h"

#include <iostream>

Letter::Letter(const wchar_t firstCode)
{
    _possibleUnicode.push_back(firstCode);
}

Letter::Letter(const wchar_t firstCode, const wchar_t secondCode) : Letter(firstCode)
{
    _possibleUnicode.push_back(secondCode);
}

bool Letter::operator==(wchar_t keyCode) const
{
    keyCode = Console::ToUpperCase(keyCode);
    for (auto& code : _possibleUnicode)
    {
        if (code == keyCode)
            return true;
    }

    return false;
}

bool Letter::operator!=(wchar_t keyCode) const
{
    keyCode = Console::ToUpperCase(keyCode);
    for (auto& code : _possibleUnicode)
    {
        if (code != keyCode)
            return true;
    }

    return false;
}
