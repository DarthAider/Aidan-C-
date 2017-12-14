//*****************************************************************************
// File Name:  03_DNAClasses.h
// Author:	   Aidan Lindsey
// Date:	   3/9/2016
// Class:	   CS250-02
// Assignment: Assignment 03_DNAClasses
// Purpose:	   Creates an DNA object that can store a 1D array full of DNA 
//             bases, print the original two copies, print the reverse, print
//             the reverse reverse, print the reverse compliment and then 
//             print most similar DNA strands
//*****************************************************************************
#include "InterfaceDNA.h"
#include <iostream>
#include <istream>
#include <fstream>
using namespace std;

int main()
{
    DNA cDNAObject;
    char DNAStrandArray [100];
    char ReverseStrandArray [100];
    char SecondReverseStrandArray [100];
    char ReverseComplimentStrandArray [100];
    char UserStrandArray [100];
    char ReverseUserArray [100];
    char SecondReverseUserArray [100];
    char ReverseComplimentUserArray [100];

    bool properData = true;
    int NumberBases = 0;
    int NumberStrands = 0;
    ifstream inputFile;
    ofstream outputFile;

    ifstream inFile;
    inFile.open("DNA.txt");

    if (!inFile)
    {
        cout << "Error: could not open dnastrings,.txt\n\n";
        return EXIT_FAILURE;
    }
    NumberStrands = cDNAObject.numberStrands(inFile);
    if (NumberStrands <= 1)
    {
        cout << "Error: Not DNA Strands in File" << endl << endl;
        return EXIT_FAILURE;
    }
    inFile.close();

    inFile.open("DNA.txt");
    NumberBases = cDNAObject.numberBases(inFile);
    inFile.close();

    inFile.open("DNA.txt");
    properData = cDNAObject.properData(inFile, NumberBases, NumberStrands);
    if (properData == false)
    {
        cout << "Error: The strands in the file are invalid" << endl << endl;
        return EXIT_FAILURE;
    }
    cDNAObject.displayHeading();
    inFile.close();
    inFile.open("DNA.txt");

    cDNAObject.readDNAFile(inFile, cDNAObject, NumberBases, NumberStrands);
    cDNAObject.readUserDNAStrand(cout, cin, NumberBases);
    cDNAObject.printOriginal(cout, cDNAObject, DNAStrandArray, UserStrandArray, NumberBases);
    cDNAObject.createReverse(cout, cDNAObject, DNAStrandArray, ReverseStrandArray, ReverseUserArray, UserStrandArray, NumberBases);
    cDNAObject.secondReverse(cout, SecondReverseStrandArray, ReverseStrandArray, ReverseUserArray,
                             SecondReverseUserArray, NumberBases);
    cDNAObject.createReverseCompliment(cout, cDNAObject, ReverseStrandArray, ReverseUserArray, NumberBases,
        ReverseComplimentStrandArray, ReverseComplimentUserArray);
    inFile.close();

    inFile.open("DNA.txt");
    cDNAObject.pStat(cout, inFile, cDNAObject, UserStrandArray, NumberBases, NumberStrands);
    inFile.close();
    return EXIT_SUCCESS;
}