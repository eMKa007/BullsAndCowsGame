#pragma once
#include <iostream>


class FBullCowGame{
public:
	//void Reset();	//TODO, make a more rich return value.
	//int GetMaxTries();
	//void RollWord();
	//std::string Guess = GetGuess();
	//bool CheckAnswer();
	//void PrintBullsAndCows();
	//void PrintIntro();
	//void PrintWin();
	//int GetMaxTriesNumber();

	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuess(string Guess);


private:
	int MyCurrentTry;
	int MyMaxTries;
};