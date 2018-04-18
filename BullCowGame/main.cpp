#include <iostream>
#include <string>
#include "main.h"

using namespace std;

#define WORD_LENGTH		5
#define CHANCES		5

int main(int argc, char * argv[]);

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

int main( int argc, char* argv[])
{
	bool PlayAgain;
	do
	{
		PrintIntro();
		PlayGame();
		PlayAgain = AskToPlayAgain();
	} while (PlayAgain);

	return 0;
}

void PrintIntro()
{
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I am thinking of?\n";
}

void PlayGame()
{
	// loop for the number of terms asking for message. 
	for (int i = 0; i < CHANCES; i++)
	{
		string Guess = GetGuess();
		cout << "Your guess is: " << Guess << endl;
	}
}

string GetGuess()
{
	//Get Guess from the player.
	cout << "\nType in Your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "\nDo You want to play again? :) [y/n]    ";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

