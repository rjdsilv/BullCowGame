#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();

int main()
{
	constexpr int NUMBER_OF_TURNS = 5;

	PrintIntro();

	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		// Repeat the guess back to the player.
		cout << "Your guess was: " << GetGuess() << endl;
		cout << endl;
	}

	return 0;
}

void PrintIntro()
{
	// Introduce the game.
	constexpr int WORLD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of?" << endl;
	cout << endl;
	return;
}

string GetGuess()
{
	// Get a guess from the player.
	string Guess = "";
	cout << "Please, enter your guess: ";
	getline(cin, Guess);
	return Guess;
}