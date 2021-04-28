#include<iostream>
#include<ctime>
using namespace std;

void PrintIntroduction();
void PrintInstructions(int);
bool PlayGame(int);
void FinalMessage(int, int, int);
void LevelHint(int, int, int, int, int);
int DifficultySelection();

int main()
{
	int LevelDifficulty = 1;
	int MaxDifficulty;
	int NumOfFails = 3;
	
	srand((unsigned)time(0));
	PrintIntroduction();
	MaxDifficulty = DifficultySelection();
	PrintInstructions(MaxDifficulty);

	while (LevelDifficulty <= MaxDifficulty && NumOfFails > 0)
	{	//loop the game until all level are copleted
		bool bLevelComplete = PlayGame(LevelDifficulty);
		cin.clear();
		cin.ignore();

		if (bLevelComplete) 
		{	//increase level difficulty
			cout << "You are now on level " << ++LevelDifficulty << endl;
		}
		else
		{
			NumOfFails--; // life loss
			if (NumOfFails > 0)
				cout << "Be caraefull, you have " << NumOfFails << " more time/s." << endl;
			else
				cout << "No more tries." << endl;
		}
	}
	FinalMessage(LevelDifficulty, MaxDifficulty,NumOfFails);
	return 0;
}

void PrintIntroduction()
{	//Prints opening messages to the terminal
	cout << "\n  ______     _       __          _  __";
	cout << "\n /_  __/____(_)___  / /__       | |/ /";
	cout << "\n  / / / ___/ / __ \\/ / _ \\______|   / ";
	cout << "\n / / / /  / / /_/ / /  __/_____/   |  ";
	cout << "\n/_/ /_/  /_/ .___/_/\\___/     /_/|_|  ";
	cout << "\n          /_/                         " << endl;
}

void PrintInstructions(int levels)
{
	cout << "===============================================================================" << endl;
	cout << "|| You are a secret agent breaking into a secured server Bunker.             ||" << endl;
	cout << "|| There are " << levels << " levels and each level has a secret code.       ||" << endl;
	cout << "|| On every level you'll get 2 Hints that will help you to crack the code.   ||" << endl;
	cout << "|| The code consists of 3 numbers.                                           ||" << endl;
	cout << "|| Enter the numbers separated with space and hit Enter to continue.         ||" << endl;
	cout << "===============================================================================" << endl;
}

bool PlayGame(int Difficulty)
{
	//Generating random #'s for the code
	const int CodeA{ rand() % Difficulty + Difficulty };
	const int CodeB{ rand() % Difficulty + Difficulty };
	const int CodeC{ rand() % Difficulty + Difficulty };

	const int CodeSum{ CodeA + CodeB + CodeC };//Hint 1
	const int CodeProduct{ CodeA * CodeB * CodeC };//Hint 2
	int GuessA, GuessB, GuessC; //vars to keep user geusses
	int GuessSum, GuessProduct; //vars to check if player entered correct values

	//Prints the hints for the current level
	LevelHint(CodeA, CodeB, CodeC, CodeSum, CodeProduct);

	cout << "Enter your guess: ";
	cin >> GuessA;
	cin >> GuessB;
	cin >> GuessC;
	cout << "You entered: " << GuessA << "," << GuessB << "," << GuessC << endl;
	cout << "--------------------------------------" << endl;

	GuessSum = GuessA + GuessB + GuessC; //calcultaing sum of numbers user entered
	GuessProduct = GuessA * GuessB * GuessC; //calculating product of numbers

	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{ //if the entered code is correct
		cout << "You win." << endl;
		return true;
	}
	else
	{ //if the entered code is wrong
		cout << "You lose" << endl;
		return false;
	}
}

void LevelHint(int NumA, int NumB, int NumC, int CodeSum, int CodeProduct)
{ // printing the hints of the current level
	cout << endl << "--------------------------------" << endl;
	cout << "Sum of numbers is:\t" << CodeSum << endl;
	cout << "Product of numbers is:\t" << CodeProduct << endl;
	cout << "--------------------------------" << endl;
}

void FinalMessage(int LevelDifficulty, int MaxDifficulty, int NumOffails)
{
	cout << endl;
	if (LevelDifficulty == MaxDifficulty && NumOffails != 0)
	{// if the player Competes the game
		cout << "=======================================================================" << endl;
		cout << "|| MISSION SUCCEEDED! You got all the files. \nNow get out of there! ||" << endl;
		cout << "=======================================================================" << endl;
	}
	else
	{ // if the player lost all lives
		cout << "=========================================================================" << endl;
		cout << "|| MISSION FAILED!  Pack-up and get out of there before they find you! ||" << endl;
		cout << "=========================================================================" << endl;
	}
}

int DifficultySelection()
{
	int selection;
	cout << "Please choose difficulty:" << endl;
	cout << "[1] Easy     (5  Levels)." << endl;
	cout << "[2] Medium.  (10 Levels)." << endl;
	cout << "[3] Hard.    (15 Levels)." << endl;
	cout << "[4] Extreme. (20 Levels)." << endl;
	cout << "My selection: ";
	cin >> selection;

	while (selection < 1 || selection>4)
	{ //loop to guarentee that user enters a valid choice
		cout << "Invalid choice. Please try again." << endl;
		cout << "My selection: ";
		cin >> selection;
	}
	// more levels means more complicated codes to guess
	return selection * 5;
}