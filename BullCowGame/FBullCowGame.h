#pragma once
#include <string>


class FBullCowGame{
public:
	FBullCowGame();	//constructor, without any parameters. 

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset();
	bool CheckGuess(std::string Guess);


private:
	int MyCurrentTry;
	int MyMaxTries;
};