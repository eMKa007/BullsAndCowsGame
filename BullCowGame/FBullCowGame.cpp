#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); } // Deafult constructor

int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const 
{
	TMap<int32, int32> WordLengthToMaxTries { {3,4}, {4,7}, {5,10}, {6,15}, {7, 20} };
						//			WordLength ^  ^
									//	          MaxTries
	return WordLengthToMaxTries[MyHiddenWord.length()];


}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if( !IsIsogram(Guess) )
		return EGuessStatus::Not_Isogram;
	else if( !IsLowercase(Guess) )								// TODO write function
		return EGuessStatus::Not_Lowercase;
	else if( Guess.length() != GetHiddenWordLenght() )	// if the guess length is wrong
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
	for( int32 MHWChar =0; MHWChar< WordLength; MHWChar++ )	// MHWChar- MyHiddenWordChar
	{
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < WordLength; GChar++)	// GChar- GuessChar
		{
			// if they match
			if(Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if(MHWChar == GChar)	//if they are in the same place
				{
					BullCowCount.Bulls++;	// increment bulls
					break;
				}
				else
					BullCowCount.Cows++;	//Increment cows
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

	for( auto Letter : Word)	// Check all letters in a loop. 
	{
		Letter = tolower(Letter);
		
		if( LetterSeen[Letter] ) // Set true to map for every new letter in guess.
			return false;
		else
			LetterSeen[Letter] = true;
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{	
	for (auto Letter : Word)	// Check all letters in a loop. 
	{
		if ( !islower(Letter) )	// If Letter is lowercase, check next character.
			return false;
	}
	return true;
}
