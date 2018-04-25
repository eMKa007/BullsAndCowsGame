#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}
//Constructor:
FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if( false )										//  TODO write function
		return EGuessStatus::Not_Isogram;
	else if( false )								// TODO write function
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
		printf("Well done. You got it!\n", MyHiddenWord);
	}
	else
	{
		printf("Mayby next time :) Keep going!\n");
	}
}
