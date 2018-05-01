/*
	Declarations of functions and methods defined here can be found in 
	FBullCowGame.h file. 
*/

#include "FBullCowGame.h"
#include <iostream>
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); } // Deafult constructor

int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries(int32 WordLength) const 
{
	TMap<int32, int32> WordLengthToMaxTries { {4,5}, {5,7}, {6,10}};
	return WordLengthToMaxTries[WordLength];
}

void FBullCowGame::SerGameDifficulty()
{
	FString DifficultyChoose = "";
	int32 Difficult = 0;
	do
	{
		std::cout << "\nSet difficulty: <1-3>\n\t1- Easy (4 characters, 5 chances)\n\t2- Medium (5 characters, 7 chances)\n\t3- Hard (6 characters, 10 chances)\n";
		std::getline(std::cin, DifficultyChoose);
		
		try
		{
			Difficult = std::stoi(DifficultyChoose);
		}
		catch (const std::invalid_argument ) 
		{
			std::cerr << "\nInvalid argument.";
		}
		catch ( const std::out_of_range )
		{
			std::cerr << "\nInserted value out of allowed range.";
		}

		if ( Difficult < 1 || Difficult > 3 )
		{
			std::cout << "\nPlease enter proper value between 1 and 3.. \n";
		}

	} while (Difficult < 1 || Difficult > 3);

	FBullCowGame::Difficulty = Difficult;
	return;
}


void FBullCowGame::Reset()
{
	const FString EasyHiddenWord[] = { "agio", "aims", "airs", "amir", "amis", "arms", "gams", "gars", "giro", "goas", "gram", "grim", "magi", "mags", "mair", "mars", "migs", "mirs",  "miso", "moas", "mogs", "mora", "mors", "oars", "ogam", "osar", "ragi", "rags", "rami", "rams", "rias", "rigs", "rims", "roam", "roms", "sago", "sari", "sima", "smog", "soar", "soma", "sora", "sori" };
	const FString MediumHiddenWord[] = { "agios", "agism", "amigo", "amirs", "giros", "gismo", "grams", "imago", "mairs", "moira", "moras", "ogams", "ragis", "roams", "sigma", "simar", "dater", "dates", "datos", "datum", "daube", "daubs", "dauby", "daunt", "dauts", "daven", "davit", "dawen", "dawks", "dawns", "dawts", "dazes", "deair", "deals", "dealt", "deans", "dears", "deary", "deash", "death", "debar", "debit", "debts", "debug", "debut", "decaf", "decal", "decay", "decks", "decor", "decos", "decoy", "decry", "defat", "defis", "defog", "degas", "degum", "deify", "deign", "deils", "deism", "deist", "deity", "delay", "delfs", "delft", "delis", "delta", "delts", "demit" };
	const FString HardHiddenWord[] = { "gambes", "gambir", "gambit", "gamble", "gambol", "gamely", "gamers", "gamest", "amier", "gamily", "gamine", "gamins", "gamuts", "gander", "ganefs", "ganevs", "ganofs", "ganoid", "gantry", "gaoled", "keblah", "kefirs", "kelims", "keloid", "kelson", "kelvin", "kenafs", "kendos", "kermis", "ketols", "kevils", "keying", "keypad", "paired", "palest", "palets", "palier", "paling", "palish", "palmed", "palmer", "palter", "paltry", "pander", "pandit", "panels", "panfry", "panful", "panged", "panics", "panier", "panted", "pantie", "pantos", "pantry", "panzer", "parcel", "pardie", "pardon", "parent", "pareos", "pareus", "parged", "parges", "parget", "pargos", "paries", "paring", "parish", "parity", "parked"};

	if(Difficulty == 1)
	{
		MyHiddenWord = EasyHiddenWord[rand() % ( sizeof(EasyHiddenWord)/sizeof(FString) ) ];
	}
	else if( Difficulty == 2)
	{
		MyHiddenWord = MediumHiddenWord[rand() % ( sizeof(MediumHiddenWord) / sizeof(FString) ) ];
	}
	else
	{
		MyHiddenWord = HardHiddenWord[rand() % ( sizeof(HardHiddenWord) / sizeof(FString) ) ];
	}
	
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

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();

	
	for( int32 HiddenWordChar =0; HiddenWordChar< WordLength; HiddenWordChar++ )
	{
		// compare letters against the hidden word
		for (int32 GuessChar = 0; GuessChar < WordLength; GuessChar++)
		{
			// if they match
			if(Guess[GuessChar] == MyHiddenWord[HiddenWordChar])
			{
				if(HiddenWordChar == GuessChar)	//if they are in the same place
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
		std::cout << "\nWell done. You got it!\n";
	}
	else
	{
		std::cout << "\nMayby next time, Your hidden word was: \"" << MyHiddenWord << "\". Keep going! :)\n";
		
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
		if ( !islower(Letter) )	// If Letter is lowercase, check next character.
			return false;
	}
	return true;
}
