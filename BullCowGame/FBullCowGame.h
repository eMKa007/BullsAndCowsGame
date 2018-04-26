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

enum class EGuessStatusMoja
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
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	EGuessStatus CheckGuessValidity(FString Guess) const ;
	
	void Reset();					// TODO, make a more rich return value
	
	FBullCowCount SubmitValidGuess(FString Guess);
	void PrintGameSummary();

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString Word) const;
};