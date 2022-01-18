#pragma once

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
};

namespace Config
{
	const Size gameFrameStandartSize = { 13, 13 };
	const Size gameFrameCellStandartSize = { 3,3 };
}