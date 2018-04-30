#pragma once

#include "FBullCowGame.h"
#include <map>

// To make syntax Unreal friendly
#define TMap std::map 
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // Deafult constructor

int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const 
{
	TMap<int32, int32> WordLengthToMaxTries { {3,4}, {4,7}, {5,10}, {6,15}, {7, 20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";	//this MUST be an isogram. 
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if( !IsIsogram(Guess) )
		return EGuessStatus::Not_Isogram;
	else if( !IsLowercase(Guess) )
		return EGuessStatus::Not_Lowercase;
	else if( Guess.length() != GetHiddenWordLenght() )
		return EGuessStatus::Wrong_Length;
	else
		return EGuessStatus::OK;
}

// Receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();

	// loop through all letters in the guess
	for( int32 HiddenWordChar =0; HiddenWordChar< WordLength; HiddenWordChar++ )
	{
		for (int32 GuessChar = 0; GuessChar < WordLength; GuessChar++)
		{
			if(Guess[GuessChar] == MyHiddenWord[HiddenWordChar])
			{
				if(HiddenWordChar == GuessChar)
				{
					BullCowCount.Bulls++;
					break;
				}
				else
					BullCowCount.Cows++;
			}
		}
	}

	if( BullCowCount.Bulls == WordLength ) 
		bGameIsWon = true; 
	else 
		bGameIsWon = false;

	return BullCowCount;
}

void FBullCowGame::PrintGameSummary()
{
	if( bGameIsWon )
	{
		printf("Well done. You got it!\n");
	}
	else
	{
		printf("Mayby next time :) Keep going!\n");
	}
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//Treat 0 or 1 letter word as isogram 
	if( Word.length() <= 1 ) { return true; }

	TMap<char, bool> LetterSeen;	// Setup our map

	for( auto Letter : Word)
	{
		Letter = tolower(Letter);
		
		if( LetterSeen[Letter] )
			return false;
		else
			LetterSeen[Letter] = true;
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{	
	for (auto Letter : Word)
	{
		if ( !islower(Letter) )
			return false;
	}
	return true;
}
