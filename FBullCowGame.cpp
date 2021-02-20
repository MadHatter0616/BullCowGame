#include "FBullCowGame.h"
#include <string>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { reset(); }
int32 FBullCowGame::GetCurrentTries() const { return MyCurrentTries; }
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetHiddenWordLength()const { return HiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return IsGameWin; }

void FBullCowGame::reset()
{
	MyCurrentTries = 1;
	MyMaxTries = 7;
	HiddenWord = "1047";
	IsGameWin = false;
}


BullCowStatus FBullCowGame::CheckGuess(FString Guess)
{
	if (Guess.length() < GetHiddenWordLength()) {return BullCowStatus::Too_Short;}
	if (Guess.length() > GetHiddenWordLength()) { return BullCowStatus::Too_Long;}
	if (!IsAllNumber(Guess)) { return BullCowStatus::Not_number; }
	if (!IsIsogram(Guess)) { return BullCowStatus::Not_Isogram; }

	return BullCowStatus::OK;
}


bool FBullCowGame::IsAllNumber(FString Guess)const
{
	for (auto letter:Guess) {
		if (letter < '0' || letter >'9') {
			return false;
		}
	}
	return true;
}

bool FBullCowGame::IsIsogram(FString Guess)const
{
	TMap<char,bool> LetterSeen;
	for (auto letter : Guess) {
		if (LetterSeen[letter]) {
			return false;
		}
		else {
			LetterSeen[letter] = true;
		}
	}
	
	return true;
}


BullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTries++;

	BullCowCount BCcount;

	for (int i = 0; i < Guess.length(); i++) {
		for (int j = 0; j < GetHiddenWordLength(); j++) {

			if (Guess[i] == HiddenWord[j]) {
				if (i == j) {BCcount.Bull++;} //Bull in the right location
				else {BCcount.Cow++;}//Cow in the wrong location
			}

		}
	}

	//Check if game WIN
	if (BCcount.Bull == GetHiddenWordLength()) {
		IsGameWin = true;
	}
	else {
		IsGameWin = false;
	}

	return BCcount;
}