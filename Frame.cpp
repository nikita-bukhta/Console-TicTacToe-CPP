#include "Frame.h"

#include <iostream>

void Frame::MakeGameFrame(void)
{
	for (short row = 0; row < _frameSize.height; ++row)
	{
		for (short column = 0; column < _frameSize.width; ++column)
		{
			// if is the first row;
			if (row == 0)
			{
				// corners;
				if (column == 0)
					_frame[row][column] = FrameChar::UpLeftCorner;
				else if (column == (_frameSize.width - 1))
					_frame[row][column] = FrameChar::UpRightCorner;
				// line;
				else
					_frame[row][column] = FrameChar::HorizontStick;
			}
			// if is the last row;
			else if (row == (_frameSize.height - 1))
			{
				// corners;
				if (column == 0)
					_frame[row][column] = FrameChar::DownLeftCorner;
				else if (column == (_frameSize.width - 1))
					_frame[row][column] = FrameChar::DownRightCorner;
				// line;
				else
					_frame[row][column] = FrameChar::HorizontStick;
			}
			// if is the first or the last column
			//	make line;
			else if (column == 0 || column == (_frameSize.width - 1))
				_frame[row][column] = FrameChar::VerticalStick;
			// else make empty space;
			else
				_frame[row][column] = FrameChar::Space;
		}
	}
}

Frame::Frame(void)
{
	_frameSize = Size();
	_frame = nullptr;
}

Frame::Frame(const Size& gameFrameSize)
{
	_frameSize = gameFrameSize;

	_frame = new FrameChar * [_frameSize.height];
	for (int i = 0; i < _frameSize.height; ++i)
		_frame[i] = new FrameChar[_frameSize.width];

	MakeGameFrame();
}

Frame::Frame(const Frame& other)
{
	this->_frameSize = other._frameSize;

	_frame = new FrameChar * [_frameSize.height];
	for (short i = 0; i < _frameSize.height; ++i)
	{
		_frame[i] = new FrameChar[_frameSize.width];

		for (short j = 0; j < _frameSize.width; ++j)
			this->_frame[i][j] = other._frame[i][j];
	}
}

Frame::~Frame(void)
{
	if (_frame != nullptr)
	{
		for (int i = 0; i < _frameSize.height; ++i)
		{
			if (_frame[i] != nullptr)
			{
				delete[] _frame[i];
				_frame[i] = nullptr;
			}
		}

		delete[] _frame;
		_frame = nullptr;
	}
}

Frame Frame::operator=(const Frame& other)
{
	// free dynamic memory in order to
	//	excape memory leak;
	this->~Frame();

	this->_frameSize = other._frameSize;

	_frame = new FrameChar * [_frameSize.height];
	for (short i = 0; i < _frameSize.height; ++i)
	{
		_frame[i] = new FrameChar[_frameSize.width];

		for (short j = 0; j < _frameSize.width; ++j)
			this->_frame[i][j] = other._frame[i][j];
	}

	return *this;
}

void Frame::SetGameFrameWidth(const short width)
{
	// free dynamic memory in order to
	//	excape memory leak;
	this->~Frame();

	_frameSize.width = width;
	_frame = new FrameChar *[_frameSize.height];
	for (int i = 0; i < _frameSize.height; ++i)
		_frame[i] = new FrameChar[width];

	MakeGameFrame();
}

void Frame::SetGameFrameHeight(const short height)
{
	// free dynamic memory in order to
	//	excape memory leak;
	this->~Frame();

	_frameSize.height = height;
	_frame = new FrameChar * [height];
	for (int i = 0; i < height; ++i)
		_frame[i] = new FrameChar[_frameSize.width];

	MakeGameFrame();
}

Size Frame::GetFrameSize(void) const
{
	return _frameSize;
}

void Frame::DrawFrame(const COORD& startCoord) const
{
	Console::SetCursorPosition(startCoord);
	for (short row = 0; row < _frameSize.height; ++row)
	{
		for (short column = 0; column < _frameSize.width; ++column)
		{
			Console::SetCursorPosition(startCoord.X + column, startCoord.Y + row);
			std::cout << unsigned char(_frame[row][column]);
		}
	}
}

void Frame::DrawFrame(const short coordX, const short coordY) const
{
	DrawFrame(COORD{ coordX, coordY });
}
