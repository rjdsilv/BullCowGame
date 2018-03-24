#include <iostream>
#include <string>

using namespace std;

int main()
{
	constexpr int WORLD_LENGTH = 5;

	// Introduce the game.
	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of?" << endl;
	cout << endl;

	// Get a guess from the player.
	string Guess = "";
	cout << "Please, enter your guess: ";
	getline(cin, Guess);

	// Repeat the guess back to the player.
	cout << "Your guess was: " << Guess << endl;
	cout << endl;

	return 0;
}