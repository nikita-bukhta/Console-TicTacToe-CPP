#include "Player.h"

short Player::_playerCount = 0;

Player::Player(void)
{
	++_playerCount;
	_name = L"Player " + std::to_wstring(_playerCount);
	_playingChar = PlayingChar::Empty;
}

Player::Player(PlayingChar playingChar) : Player()
{
	_playingChar = playingChar;
}

Player::Player(std::wstring name, PlayingChar playingChar)
{
	++_playerCount;
	_name = name;
	_playingChar = playingChar;
}

void Player::SetPlayingChar(PlayingChar playingChar)
{
	_playingChar = playingChar;
}

Player::PlayingChar Player::GetPlayingChar(void) const
{
	return _playingChar;
}

void Player::SetName(std::wstring name)
{
	_name = name;
}

std::wstring Player::GetName(void) const
{
	return _name;
}
