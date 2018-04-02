#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	}
	while (AskToPlayAgain());

	return 0;
}

void PrintIntro()
{
	// Introduce the game.
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	for (int32 i = 0; i < BCGame.GetMaxTries(); i++)
	{
		FText Guess = GetGuess();
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		if (Status == EGuessStatus::OK)
		{
			FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
			std::cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << std::endl;
		}
	}
}

FText GetGuess()
{
	// Get a guess from the player.
	FText Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Please, enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you wanna play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return ('Y' == Response[0]) || ('y' == Response[0]);
}
