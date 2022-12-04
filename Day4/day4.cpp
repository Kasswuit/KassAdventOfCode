#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    //Part 1 Variables
    ifstream inputFile; // The input file
    string line; // Stores line
    string leftElf;
    string rightElf;
    int overlaps = 0;
    int commaIndex;
    int leftDashIndex;
    int rightDashIndex;
    int leftLower;
    int leftUpper;
    int rightLower;
    int rightUpper;
    //Part 2 Variables
    int partialOverlaps = 0;

    //Logic
    inputFile.open("input.txt");
    while(!inputFile.eof())
	{
        getline(inputFile,line);
        //Find comma 
        commaIndex = line.find(",");
        //get in strings
        leftElf = line.substr(0,commaIndex);
        rightElf = line.substr(commaIndex+1,line.length()-commaIndex);
        //Find dash
        leftDashIndex = leftElf.find("-");
        rightDashIndex = rightElf.find("-");
        //Get into integers
        leftLower = stoi(leftElf.substr(0,leftDashIndex));
        leftUpper = stoi(leftElf.substr(leftDashIndex+1,leftElf.length()-leftDashIndex));
        rightLower = stoi(rightElf.substr(0,rightDashIndex));
        rightUpper = stoi(rightElf.substr(rightDashIndex+1,rightElf.length()-rightDashIndex));
        if((leftLower >= rightLower && leftUpper <= rightUpper) || (rightLower >= leftLower && rightUpper <= leftUpper))
            overlaps = overlaps + 1;
        if((leftLower >= rightLower && leftLower <= rightUpper) || (rightLower >= leftLower && rightLower <= leftUpper))
            partialOverlaps = partialOverlaps + 1;
        else if((leftUpper >= rightLower && leftUpper <= rightUpper) || (rightUpper >= leftLower && rightUpper <= leftUpper))
            partialOverlaps = partialOverlaps + 1;
    }
    cout << "Total overlaps: " << overlaps << endl;
    cout << "Partial overlaps: " << partialOverlaps << endl;
}
