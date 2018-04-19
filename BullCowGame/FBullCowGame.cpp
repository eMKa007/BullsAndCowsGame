#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuess(FString)
{
	return false;
}

// Receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//Increment the Turn #
	MyCurrentTry++;

	// Setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 MyHiddenWordLength = MyHiddenWord.length();
	for( int32 i =0; i< MyHiddenWordLength; i++ )
	{
		// compare letters against the hidden word
		for (int32 j = 0; j < MyHiddenWordLength; j++)
		{
			// if they match
			if(Guess[i] == MyHiddenWord[j])
			{
				if( i == j )	//if they are in the same place
				{
					BullCowCount.Bulls++;	// increment bulls
					break;
				}
				else
					BullCowCount.Cows++;	//Increment cows
			}
		}
	}


	return BullCowCount;
}
