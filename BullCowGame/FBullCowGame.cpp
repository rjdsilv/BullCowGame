#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// If the guess is not an isogram.
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	// If the guess is not all lowercase.
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	// If the guess length is wrong.
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}

	return EGuessStatus::Ok;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;

	return;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 HiddenWordLen = MyHiddenWord.length();
	for (int32 HWChar = 0; HWChar < HiddenWordLen; HWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLen; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[HWChar])
			{
				if (HWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}

	return BullCowCount;
}
