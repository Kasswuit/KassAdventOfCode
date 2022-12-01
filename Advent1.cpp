#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[]) {
  /* constants */
  const int SIZE = 10000;

  ifstream inputFile; // the input file
  string calories[SIZE]; // creates an array
  int elves[SIZE]; //
  string line; //stores line
  int i = 0; // counter
  int j = 0; // counter to go through elves array
  int max = 0;

  //Part 2 variables
  int secMax = 0;
  int thrMax = 0;
  int total = 0;

  // Opens input file
  inputFile.open("input.txt");

  while(!inputFile.eof())
  {
    getline(inputFile,line);
    calories[i]=line;
    i++;
  }

  //loop through array to assign each elf calorie counter
  cout << i << "\n";
  for(int k = 0; k <= i; k++)
  {
    if(calories[k] == "")
    {
      
      if (elves[j] >= max)
      {
        thrMax = secMax;
        secMax = max;
        max = elves[j];
      } 
      else if (elves[j] >= secMax)
      {
	thrMax = secMax;
	secMax = elves[j];
      }
      else if (elves[j] >= thrMax)
      {
	thrMax = elves[j];
      }
	j++;
    }
    else
    {
      elves[j] = elves[j] + stoi(calories[k]);
      //cout << k << "\n";
    }

  }
  
  cout<<"First:" << max << "\n";
  cout<<"Second:" << secMax << "\n";
  cout<<"Third:" << thrMax << "\n";
  total = max + secMax + thrMax;
  cout<<"Total:" << total << "\n";
  return 0;
}
