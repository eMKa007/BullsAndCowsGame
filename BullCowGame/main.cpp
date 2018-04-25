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
FString GetValidGuess();
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
	std::cout << "\n\nWelcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght() << " letter isogram I am thinking of?\n";
	// TODO Add some ASCII graphics of bull nad cow. 
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while game is NOT won
	// and there are still tries remaining

	while( !BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries )
	{
		FString Guess = GetValidGuess();

		//Submit Valid guess to the game, and recieve counts.
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	}
	
	BCGame.PrintGameSummary();

	return;
}

// Loop continually until user gives a valid guess.
FString GetValidGuess()
{	
	EGuessStatus Status = EGuessStatus::INVALID_STATUS;
	FString Guess = "";
	do
	{
		//Get Guess from the player.
		std::cout << "\nTry " << BCGame.GetCurrentTry();
		std::cout << ". Type in Your guess: ";
		
		std::getline(std::cin, Guess);
	
		//Check Status and give feedback:
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
			case EGuessStatus::Wrong_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLenght() << " letter word. \n";
				break;
			case EGuessStatus::Not_Isogram:
				std::cout << "Please enter an isogram word. Word without repeating letters..\n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "Please enter an all lowercase word.\n";
				break;
			default: 
				break;		// We assumeing guess is valid.
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "\nDo You want to play again? :) [y/n]    ";
	FString Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

