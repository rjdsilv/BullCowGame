#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{
public:
	/// Constructors.
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidity(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
};	