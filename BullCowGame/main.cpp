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
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght() << " letter isogram I am thinking of?\n";
	// TODO Add some ASCII graphics of bull nad cow. 
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of terms asking for message. 
	for (int32 i = 0; i < MaxTries; i++)	// TODO change from FOR to WHILE loop, once we are validating tries.
	{
		FString Guess = GetValidGuess();	
		
		//Submit Valid guess to the game, and recieve counts.
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
 
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	}

	// TODO Summarize game here. 
}

// Loop continually until user gives a valid guess.
FString GetValidGuess()
{	
	EGuessStatus Status = EGuessStatus::INVALID_STATUS;
	do
	{
		//Get Guess from the player.
		std::cout << "\nTry " << BCGame.GetCurrentTry();
		std::cout << ". Type in Your guess: ";
		FString Guess = "";
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
			default: return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	
	
}

bool AskToPlayAgain()
{
	std::cout << "\nDo You want to play again? :) [y/n]    ";
	FString Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

