/*
This file contains declarations of:
	- FBullCowCount structure (used to count down bulls and cows)
	- EGuessStatus enum class (used to check guess validity)
	- FBullCowGame class (instance of game)
*/

#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount //All variables initialized to 0.
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
	FBullCowGame();	//constructor, without any parameters. 

	bool IsGameWon() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	EGuessStatus CheckGuessValidity(FString Guess) const ;
	
	int32 GetMaxTries(int32 WordLength) const;

	void SerGameDifficulty();

	void Reset();					// TODO, make a more rich return value
	
	FBullCowCount SubmitValidGuess(FString Guess);

	void PrintGameSummary();

private:
	int32 Difficulty;
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString Word) const;
	bool IsLowercase(FString Word) const;
};