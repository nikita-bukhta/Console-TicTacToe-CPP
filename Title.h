#pragma once

#include <array>
#include <vector>
#include <iostream>
//
//class Title
//{
//public:
//	enum class GraphicsCharacter : wchar_t
//	{
//		Empty = L' ',
//		Vertical = L'▇',
//		Horizontal = L'▃',
//		StairUp = L'▟',
//		StairDown = L'▙',
//		ReversedStairUp = L'▛',
//		ReversedStairDown = L'▜'
//	};
//
//	class Letter
//	{
//	private:
//		friend std::wostream& operator << (std::wostream& wout, Title::Letter object);
//	public:
//		Letter(std::wstring* bigLetter);
//		std::vector<std::vector<wchar_t>> _letter;
//	};
//
//	// u - uppercase;
//	// l - lowercase
//	// Lower case;
//	const static Letter _lA;
//	Letter _lC;
//	Letter _lE;
//	Letter _lI;
//	Letter _lO;
//	// Upper case;
//	Letter _uT;
//
//public:
//	std::vector<Letter> _title;
//
//	Title(std::wstring title);
//
//	void ShowTitle(void);
//};