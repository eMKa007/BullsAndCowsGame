/*
The game logic (no view code or direct user interaction)
The game is a simple guess the word based on Mastermind.
This file include declarations of:
- FBullCowCount structure
- EGuessStatus enum class
- FBullCowGame class (containing all methods and variables need for game).

*/

#pragma once
#include <string>

// To make syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	INVALID_STATUS,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

class FBullCowGame
{
public:
	FBullCowGame();	//constructor

	bool IsGameWon() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	EGuessStatus CheckGuessValidity(FString Guess) const ;
	
	int32 GetMaxTries() const;

	void Reset();
	
	FBullCowCount SubmitValidGuess(FString Guess);
	void PrintGameSummary();

private:
	int32 UserDefinedWordLength;
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString Word) const;
	bool IsLowercase(FString Word) const;
};