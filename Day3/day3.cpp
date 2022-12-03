#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    //Part 1 Variables
    ifstream inputFile; // The input file
	  string line; // Stores line
    string leftRucksack; // Stores left rucksack
    string rightRucksack; // Stores right rucksack
    char leftItem; // Stores item temporarily to compare
    char rightItem; // Also stores item temporarily to compare
    char duplicate; // Stores the duplicate item temporarily
    int lineSize; // Line Size
    int rucksackSize; // Rucksack Size
    int prioVal = 0; // Priority Value of each duplicate
    int prioSum = 0; // Priority Value Sums
    bool iterator = true; //To break out of loop soon


    //Part 2 Variables
    char badge; // Stores suspected badge
    char chr1; // Stores item temporarily to compare
    char chr2; // Stores item temporarily to compare
    char chr3; // Stores item temporarily to compare
    string line2; // Stores second elf rucksack
    string line3; // Stores third elf rucksack
    int secPrioSum; // Stores second priority sum
    int lineSize2; // Second line size
    int lineSize3; //Third line size

    inputFile.open("input.txt");
    //Part 1 Looping (can't be used for part 2 due to iterator and rucksack navigation)
    while(!inputFile.eof())
	{
        getline(inputFile,line);
        lineSize = line.length();
        rucksackSize = lineSize/2; // Rucksack size
        leftRucksack = line.substr(0,rucksackSize);
        rightRucksack = line.substr(rucksackSize,rucksackSize);
        // Check duplicates
        for(int i = 0; i < rucksackSize && iterator; i++)
        {
            leftItem = leftRucksack.at(i);
            // Compares each item in the left Rucksack with each item on right one
            for(int j = 0; j < rucksackSize && iterator; j++)
            {
                rightItem = rightRucksack.at(j);
                if(leftItem == rightItem)
                {
                    duplicate = rightItem;
                    iterator = false;
                }
            }
        }
        // Because of weird formatting
        if (!iterator)
        {
            iterator = true;
            // At this point, the duplicate should be in char duplicate
            if (duplicate >= 'a' && duplicate <= 'z')
            {
                prioVal = duplicate-96;
            }
            else if (duplicate >= 'A' && duplicate <= 'Z')
            {
                prioVal = duplicate-38;
            }
            prioSum = prioSum + prioVal;
        }
    }
    inputFile.close();
    inputFile.open("input.txt");
    //Part 2 Looping
    while(!inputFile.eof())
	  {
        getline(inputFile,line);
        getline(inputFile,line2);
        getline(inputFile,line3);
        lineSize = line.length();
        lineSize2 = line2.length();
        lineSize3 = line3.length();
        cout << "Group: " << endl;
        cout << line << endl;
        cout << line2 << endl;
        cout << line3 << endl;
        // Check duplicates
        for(int i = 0; i < lineSize && iterator; i++)
        {
            chr1 = line.at(i);
            for(int j = 0; j < lineSize2 && iterator; j++)
            {
                chr2 = line2.at(j);
                for(int k = 0; k < lineSize3 && iterator; k++)
                {
                    chr3 = line3.at(k);
                    if(chr1 == chr2 && chr2 == chr3)
                    {
                        badge = chr3;
                        iterator = false;
                    }
                }
            }
        }
        // Because of weird formatting
        if (!iterator)
        {
            iterator = true;
            // At this point, the duplicate should be in char duplicate
            if (badge >= 'a' && badge <= 'z')
            {
                prioVal = badge-96;
            }
            else if (badge >= 'A' && badge <= 'Z')
            {
                prioVal = badge-38;
            }
            secPrioSum = secPrioSum + prioVal;
        }
    }
    cout << "Priority Sum 1: " << prioSum << endl;
    cout << "Priority Sum 2: " << secPrioSum << endl;
}
