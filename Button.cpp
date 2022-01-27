#include "Button.h"
#include "Console.h"

#include <iostream>

Button::Button(const wchar_t firstCode)
{
    _possibleUnicode.push_back(firstCode);
}

Button::Button(const wchar_t firstCode, const wchar_t secondCode) : Button(firstCode)
{
    _possibleUnicode.push_back(secondCode);
}

bool Button::operator==(wchar_t keyCode) const
{
    keyCode = Console::ToUpperCase(keyCode);
    for (auto& code : _possibleUnicode)
    {
        if (code == keyCode)
            return true;
    }

    return false;
}

bool Button::operator!=(wchar_t keyCode) const
{
    keyCode = Console::ToUpperCase(keyCode);
    for (auto& code : _possibleUnicode)
    {
        if (code != keyCode)
            return true;
    }

    return false;
}
