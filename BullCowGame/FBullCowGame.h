#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount //All variables initialized to 0.
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame{
public:
	FBullCowGame();	//constructor, without any parameters. 

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset();					// TODO, make a more rich return value
	bool CheckGuess(FString Guess);
	FBullCowCount SubmitGuess(FString Guess);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};