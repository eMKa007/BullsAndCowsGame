#include <iostream>
#include <string>
#include "FBullCowGame.h"

#define WORD_LENGTH		5
#define CHANCES		5

int main(int argc, char * argv[]);

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

int main( int argc, char* argv[])
{
	do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());	// (Response[0] == 'y') || (Response[0] == 'Y');

	return 0;
}

void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I am thinking of?\n";
}

void PlayGame()
{
	// loop for the number of terms asking for message. 
	for (int i = 0; i < CHANCES; i++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess is: " << Guess << std::endl;
	}
}

std::string GetGuess()
{
	//Get Guess from the player.
	std::cout << "\nType in Your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "\nDo You want to play again? :) [y/n]    ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

