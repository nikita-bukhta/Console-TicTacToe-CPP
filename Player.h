#pragma once

#include <string>

class Player
{
public:
	// players' playing figures;
	static enum class PlayingChar : char
	{
		Empty = 0,
		X = 'X',
		Y = 'Y'
	};

private:
	std::wstring _name;
	PlayingChar _playingChar;
	static short _playerCount; // how many players play;

public:
	Player(void);
	Player(PlayingChar playingChar);
	Player(std::wstring name, PlayingChar playingChar);

	// which figure player mast make a turn;
	void SetPlayingChar(PlayingChar playingChar);
	// return figure, which player turns;
	PlayingChar GetPlayingChar(void);
	
	// Set player's name;
	void SetName(std::wstring name);
	// Get player's name;
	std::wstring GetName(void);
};
