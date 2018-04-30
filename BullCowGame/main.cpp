/* 
This is the console executable, that makes use of Bull & Cows class.
This acts as the viev in a MVC pattern, and is responsible for
user interaction. For game logic see FBullCowGame class.
*/

#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// To make syntax Unreal friendly
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
	} while (AskToPlayAgain());

	std::cout << "\nFarewell Cowboy #Moo\n\n";

	return 0; //exit the application
}

void PrintIntro()
{
	std::cout << " .========================================================================.\n";
	std::cout << "//                  Welcome in Bulls & Cows Word Game                     \\\\\n";
	std::cout << "||                                    _ _ _ _ _ _ _ _ _                   ||\n";
	std::cout << "||                   __n__n__       /  Can you guess   \\                  ||\n";
	std::cout << "||            .------`-\\00/-' : : :/     what word am I \\                 ||\n";
	std::cout << "||           /  ##  ## (oo)        \\  thinking of? #Moo /                 ||\n";
	std::cout << "||          / \\## __   ./           \\ * * * * * * * * */                  ||\n";
	std::cout << "||             |//YY \\|/                           Betty                  ||\n";
	std::cout << "||             |||   |||                                                  ||\n";
	std::cout << "||                                                                        ||\n";
	std::cout << "|} - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  {|\n";
	std::cout << "||                                                                        ||\n";
	std::cout << "||         Can You find out what is Betty thinking about?                 ||\n";
	std::cout << "||         Rules are simple:                                              ||\n";
	std::cout << "||            * You have 5 chances to guess the word.                     ||\n";
	std::cout << "||            * Word is 6 letters long.                                   ||\n";
	std::cout << "||            * Enter isogram word ( word without repeating letter ).     ||\n";
	std::cout << "||            * Enter all lowercase word.                                 ||\n";
	std::cout << "||                                                                        ||\n";
	std::cout << "|} - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  {|\n";
	std::cout << "\\\\                        G O O D   L U C K ! ! !                         //\n";
	std::cout << " * ====================================================================== *\n";
	
	return;
}

// plays a single game to complition.
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

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

FString GetValidGuess()
{	
	EGuessStatus Status = EGuessStatus::INVALID_STATUS;
	FString Guess = "";
	do
	{
		std::cout << "\nTry " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries();
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
				break;
		}
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
