#pragma once

#include "Console.h"

class Frame
{
protected:
	// char codes for frame;
	enum class FrameChar : short
	{
		GoLeft			= 185,
		VerticalStick	= 186,
		UpRightCorner	= 187,
		DownRightCorner	= 188,
		DownLeftCorner	= 200,
		UpLeftCorner	= 201,
		GoUp			= 202,
		GoDown			= 203,
		GoRight			= 204,
		HorizontStick	= 205,
		Cross			= 206,
		Space			= 255
	};

	Size _frameSize;
	FrameChar** _frame;

	// fill _frame with characters;
	virtual void MakeGameFrame(void);

public:
	Frame(void);
	Frame(const Size& gameFrameSize);
	Frame(const short width, const short height) : Frame(Size{ width, height }) {}
	Frame(const Frame& other);

	~Frame(void);

	Frame operator= (const Frame& other);

	// Change width of frame;
	void SetGameFrameWidth(const short width);
	// Change height of frame;
	void SetGameFrameHeight(const short height);

	// return size of frame;
	Size GetFrameSize(void);

	// Draw game frame in the console;
	//
	// startCoord - where you want to draw this frame;
	void DrawFrame(const COORD& startCoord);
	// Draw game frame in the console;
	//
	// coordX && coordY - where you want to draw this frame;
	void DrawFrame(const short coordX, const short coordY);
};
