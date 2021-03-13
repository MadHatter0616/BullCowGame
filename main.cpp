
#include <iostream>
#include <string>
#include "FBullCowGame.h"
#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using FText = std::string;

bool IsPlay = true;

void PrintIntro();
void Play();
void SummaryGame();
FText GetGuess();
bool AskPlayAgain();
bool GetGuessResult(FText Guess);
FBullCowGame BCGame;


int main() {

	while (IsPlay) {
		system("cls");
		PrintIntro();
		Play();
		IsPlay = AskPlayAgain();
	}

	return 0;
}

void PrintIntro()
{
	//Menu_UI_oneplayer();
	std::cout << "Welcome to Bulls and Cows ,a fun word game. " << std::endl;
	std::cout << "Can you guess the ";
	std::cout << " letter isogram I'm thinking about?\n\n";
	return; //return is a good habit ,althought use void
}

void Play()
{
	BCGame.reset();
	FText  Guess = "";
	FBullCowCount BCCount;

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTries() <= BCGame.GetMaxTries()) {
		
		Guess = GetGuess();
		
		if (GetGuessResult(Guess)) {
			BCCount = BCGame.SubmitGuess(Guess);
			std::cout << "Bulls : " << BCCount.Bull;
			std::cout << " , Cows : " << BCCount.Cow << std::endl;
			std::cout << std::endl;
		}

	}

	SummaryGame();
	return;
}

FText GetGuess()
{
	FText Guess = "";
	std::cout << "Try ." << BCGame.GetCurrentTries() << " of ";
	std::cout << "Your guess is : " << Guess;
	std::getline(std::cin, Guess);
	return Guess;
}

bool GetGuessResult(FText Guess)
{
	EBullCowStatus Status;
	Status = BCGame.CheckGuess(Guess);
	switch (Status)
	{
	case EBullCowStatus::Too_Short:
		std::cout << "Please Enter 4 Number!! Your Input too short!\n\n";
		break;
	case EBullCowStatus::Too_Long:
		std::cout << "Please Enter 4 Number!! Your Input too long!\n\n";
		break;
	case EBullCowStatus::Not_Isogram:
		std::cout << "Please Enter a Isogram!! \n\n";
		break;
	case EBullCowStatus::Not_number:
		std::cout << "Please Enter a Number !!\n\n";
		break;
	case EBullCowStatus::OK:
		return true;
		break;
	default:
		break;
	}
	return false;
}

bool AskPlayAgain()
{
	FText Ans = "";
	std::cout << "Do you want to play again ? (Y/N)";
	std::getline(std::cin, Ans);
	if (Ans[0] != 'Y' && Ans[0] != 'y' && Ans[0] != 'N' && Ans[0] != 'n') {
		return AskPlayAgain();
	}
	return (Ans[0]=='Y' || Ans[0] == 'y');
}


void SummaryGame() {
	if (BCGame.IsGameWon()) {
		std::cout << "You Win This Time !\n" ;
		std::cout << "The Corrent Number is " << BCGame.GetHiddenWord() <<" !!\n"<< std::endl;
	}
	else {
		std::cout << "Sorry You Lose!! Better Luck Next Time!\n";
		std::cout << "The Corrent Number is " << BCGame.GetHiddenWord() << " !!\n" << std::endl;
	}
}

