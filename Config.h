#pragma once

#include <Windows.h>

struct Size
{
	int width;
	int height;

	Size operator - (const Size& other)
	{
		Size result = {
			this->width - other.width,
			this->height - other.height
		};

		return result;
	}

	Size operator / (const short value)
	{
		Size result = {
			this->width / value,
			this->height / value
		};

		return result;
	}

	bool operator == (const Size& other)
	{
		return this->width == other.width &&
			this->height == other.height;
	}

	bool operator != (const Size& other)
	{
		return this->width != other.width ||
			this->height != other.height;
	}
};

namespace Config
{
	const Size gameFrameStandartSize = { 13, 13 };
	const Size gameFrameCellStandartSize = { 3,3 };
}