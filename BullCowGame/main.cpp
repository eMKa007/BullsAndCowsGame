/* 
This is the console executable, that makes use of Bull & Cows class.
This acts as the viev in a MVC pattern, and is responsible for
user interaction. For game logic see FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FString GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;	// Instance of game

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
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I am thinking of?\n";
	// TODO Add some ASCII graphics of bull nad cow. 
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of terms asking for message. 
	// TODO change from FOR to WHILE loop, once we are validating tries.
	for (int32 i = 0; i < MaxTries; i++)
	{
		FString Guess = GetGuess();	// TODO make loop checking valid guesses
		
		//Submit Valid guess to the game.
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//Print number of bulls and cows. 
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

	}

	// TODO Summarize game here. 
}

FString GetGuess()
{	
	//Get Guess from the player.
	std::cout << "\nTry " << BCGame.GetCurrentTry();
	std::cout << ". Type in Your guess: ";
	FString Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "\nDo You want to play again? :) [y/n]    ";
	FString Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

