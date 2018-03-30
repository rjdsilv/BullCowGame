#pragma once

#include <string>

class FBullCowGame
{
public:
	/// Constructors.
	FBullCowGame();

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;
};	