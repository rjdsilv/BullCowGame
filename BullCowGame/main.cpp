#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

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
	constexpr int WORLD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		// Repeat the guess back to the player.
		std::cout << "Your guess was: " << GetGuess() << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess()
{
	// Get a guess from the player.
	std::string Guess = "";
	std::cout << "Please, enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you wanna play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return ('Y' == Response[0]) || ('y' == Response[0]);
}
