#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct  FBullCowCount
{
	int32 Bull = 0;
	int32 Cow  = 0;
};

enum class EBullCowStatus
{
	Too_Short,
	Too_Long,
	Not_Isogram,
	Not_number,
	OK
};

class FBullCowGame
{
public:
	
	FBullCowGame();//rest
	void reset();//set MaxTries¡BCurrentTries¡BGameWin¡BHiddenWord
	FString RandomHiddenworld();
	FString GetHiddenWord();
	int32 GetCurrentTries()const;
	int32 GetMaxTries()const;
	int32 GetHiddenWordLength()const;
	bool IsAllNumber(FString)const;//Check Guess 
	bool IsIsogram(FString)const;//Check Guess 
	bool IsGameWon() const;//SubmitGuess

	EBullCowStatus CheckGuess(FString);
	
	FBullCowCount SubmitGuess(FString);//check bull & cow count + check gamewin

	


private:
	int32 MyCurrentTries;
	int32 MyMaxTries;
	bool IsGameWin;
	FString HiddenWord;

};



