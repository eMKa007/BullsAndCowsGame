#pragma once
#include <string>


class FBullCowGame{
public:
	
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuess(std::string Guess);


private:
	int MyCurrentTry;
	int MyMaxTries;
};