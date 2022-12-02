#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	const int SIZE = 10000;
	//Part 1 variables
	char oPlays[SIZE]; // Opponent Plays
	char pPlays[SIZE]; // Player Plays
	int roundScores[SIZE] = {0}; // Round scores
	int totalScore = 0; // Total Score
	
	//Part 2 variables
	int secRoundScore[SIZE] = {0};
	int secTotalScore = 0;
	
	ifstream inputFile; // The input file
	string line; // Stores line
	int i = 0; // Counter
	
	//Read input data
	// Opens input file
	inputFile.open("input.txt");

	while(!inputFile.eof())
	{
		getline(inputFile,line);
		if(line.length() > 0)
		{
			oPlays[i]=line.at(0);
			cout << oPlays[i] << "\n";
			pPlays[i]=line.at(2);
			cout << pPlays[i] << "\n";
		}
		// Play game
		
		if(oPlays[i] == 'A')
		{
			//Part 1 Draw, Part 2 Loss
			if(pPlays[i] == 'X')
			{
				roundScores[i] = roundScores[i]+3+1;
				secRoundScore[i] = secRoundScore[i]+3;
				
			}
			//Part 1 Win, Part 2 Draw
			if(pPlays[i] == 'Y')
			{
				roundScores[i] = roundScores[i]+6+2;
				secRoundScore[i] = secRoundScore[i]+3+1;
			}
			//Part 1 Loss, Part 2 Win
			if(pPlays[i] == 'Z')
			{
				roundScores[i] = roundScores[i]+0+3;
				secRoundScore[i] = secRoundScore[i]+6+2;
			}
		} 
		else if (oPlays[i] == 'B')
		{
			//Part 1 Draw, Part 2 Draw
			if(pPlays[i] == 'Y')
			{
				roundScores[i] = roundScores[i]+3+2;
				secRoundScore[i] = secRoundScore[i]+3+2;
			}
			//Part 1 Win, Part 2 Win
			if(pPlays[i] == 'Z')
			{
				roundScores[i] = roundScores[i]+6+3;
				secRoundScore[i] = secRoundScore[i]+6+3;
			}
			//Part 1 Loss, Part 2 Loss
			if(pPlays[i] == 'X')
			{
				roundScores[i] = roundScores[i]+0+1;
				secRoundScore[i] = secRoundScore[i]+0+1;
			}
		}
		else if (oPlays[i] == 'C')
		{
			//Part 1 Draw, Part 2 Win
			if(pPlays[i] == 'Z')
			{
				roundScores[i] = roundScores[i]+3+3;
				secRoundScore[i] = secRoundScore[i]+6+1;
			}
			//Part 1 Win, Part 2 Loss
			if(pPlays[i] == 'X')
			{
				roundScores[i] = roundScores[i]+6+1;
				secRoundScore[i] = secRoundScore[i]+0+2;
			}
			//Part 1 Loss, Part 2 Draw
			if(pPlays[i] == 'Y')
			{
				roundScores[i] = roundScores[i]+0+2;
				secRoundScore[i] = secRoundScore[i]+3+3;
			}
		}
		cout << roundScores[i] << "\n";
		totalScore = totalScore + roundScores[i];

		secTotalScore = secTotalScore + secRoundScore[i];
		i++;
	}
	cout << "totalScore: " << totalScore;
	cout << "\n";
	cout << "secRoundScore: " << secTotalScore;
}
