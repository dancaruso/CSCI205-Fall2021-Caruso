/*
    Assignment:   CSCI205 Week 1 Lab
    main.cpp - main function for fraction class lab

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/8/2021
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Fraction.h"
using namespace std;

// Additional function declarations
Fraction find_largest(vector<Fraction> fracVec);
void print(vector<Fraction>);

// Main
int main(){
    
    // fracVec - a vector to store all fractions pulled in from fractions.txt
    std::vector<Fraction> fracVec;
    
    // Pull in data from fractions.txt, convert each line to a fraction
    // I'm sure there's a more elegant way to do this, but based on my research here's what I've put together:
    fstream newFile;                            // open file stream
    newFile.open("fractions.txt", ios::in);     // open fractions.txt, create input stream
    if (newFile.is_open()) {
        string inputFrac;                       // assign each line as a string inputFrac

        while (getline(newFile, inputFrac)) {       // while its possible to read a new line, assign it as a string to inputFrac
            stringstream inputStream(inputFrac);    // create a stringstream called inputStream to read string inputFrac
            vector<int> fracNums;                   // create an int vector called fracNums

            while (inputStream.good()) {            
                string substr;                      // create a substring substr
                getline(inputStream, substr, ',');  // while reading inputStream, assign the string to substr, split at comma
                int tempInt = stoi(substr);         // convert substr to an int tempInt
                fracNums.push_back(tempInt);        // add tempInt to the end of fracNums vector. This should occur twice with each line (num and den)
            }
            Fraction tempFrac(fracNums[0], fracNums[1]);    // create a Fraction object with fracNums[0] as the num and [1] as the den
            fracVec.push_back(tempFrac);                    // add newly created Fraction object to fracVec vector!
        }
    }

    // Find and print the largest fraction in fractions.txt
    Fraction largest = find_largest(fracVec);
    cout << "Largest Fraction in fractions.txt = " << largest << endl;
    cout << endl;

    // Print out full list of fractions from fractions.txt, five fractions per line
    cout << "Complete list of fractions from fractions.txt:" << endl;
    print(fracVec);
    cout << endl;

    // Example of getNumerator and setNumerator
    cout << "Numerator for first fraction in list = " << fracVec[0].getNumerator() << endl;
    cout << "Denominator for first fraction in list = " << fracVec[0].getDenominator() << endl;
    cout << endl;

    cout << "Tests for math operators:" << endl;
    // Example of + operator
    cout << fracVec[80] << " + " << fracVec[39] << " = " << (fracVec[80]) + (fracVec[39]) << endl;

    // Example of - operator
    cout << fracVec[11] << " - " << fracVec[25] << " = " << (fracVec[11]) - (fracVec[25]) << endl;

    // Example of * operator
    cout << fracVec[44] << " * " << fracVec[66] << " = " << (fracVec[44]) * (fracVec[66]) << endl; 

    // Example of / operator
    cout << fracVec[53] << " / " << fracVec[99] << " = " << (fracVec[53]) / (fracVec[99]) << endl;

    // Example of += operator
    cout << fracVec[8] << " += " << fracVec[9] << " = " << (fracVec[8] += fracVec[9]) << endl;
    cout << endl;

    cout << "Tests for comparison operators (1 = true, 0 = false):" << endl;
    // Example of > operator true
    cout << "Is " << fracVec[23] << " greater than " << fracVec[84] << "?: " << (fracVec[23] > fracVec[84]) << endl;

    // Example of > operator false
    cout << "Is " << fracVec[84] << " greater than " << fracVec[23] << "?: " << (fracVec[84] > fracVec[23]) << endl;

    // Example of >= operator true
    cout << "Is " << fracVec[23] << " greater than or equal to " << fracVec[23] << "?: " << (fracVec[23] >= fracVec[23]) << endl;

    // Example of >= operator true
    cout << "Is " << fracVec[24] << " greater than or equal to " << fracVec[23] << "?: " << (fracVec[24] >= fracVec[23]) << endl;

    // Example of >= operator false
    cout << "Is " << fracVec[23] << " greater than or equal to " << fracVec[24] << "?: " << (fracVec[23] >= fracVec[24]) << endl;
    
    // Example of < operator true
    cout << "Is " << fracVec[48] << " less than " << fracVec[32] << "?: " << (fracVec[48] < fracVec[32]) << endl;

    // Example of < operator false
    cout << "Is " << fracVec[32] << " less than " << fracVec[48] << "?: " << (fracVec[32] < fracVec[48]) << endl;

    // Example of <= operator true
    cout << "Is " << fracVec[48] << " less than or equal to " << fracVec[48] << "?: " << (fracVec[48] <= fracVec[48]) << endl;

    // Example of <= operator true
    cout << "Is " << fracVec[48] << " less than or equal to " << fracVec[49] << "?: " << (fracVec[48] <= fracVec[49]) << endl;

    // Example of <= operator false
    cout << "Is " << fracVec[49] << " less than or equal to " << fracVec[48] << "?: " << (fracVec[49] <= fracVec[48]) << endl;

    // Example of == operator true
    cout << "Is " << fracVec[60] << " equal to " << fracVec[60] << "?: " << (fracVec[60] == fracVec[60]) << endl;

    // Example of == operator false
    cout << "Is " << fracVec[60] << " equal to " << fracVec[61] << "?: " << (fracVec[60] == fracVec[61]) << endl;

    // Example of != operator true
    cout << "Is " << fracVec[75] << " not equal to " << fracVec[87] << "?: " << (fracVec[75] != fracVec[87]) << endl;

    // Example of != operator false
    cout << "Is " << fracVec[75] << " not equal to " << fracVec[75] << "?: " << (fracVec[75] != fracVec[75]) << endl;

    return 0;
}

// Additional function definitions
// find_largest - finds the largest fraction in a given vector of fraction objects 
Fraction find_largest(vector<Fraction> fracVec) {
    Fraction largest = fracVec[0];
    for (unsigned int i = 1; i < fracVec.size(); i++) {  // vector.size() returns an unsigned int, compiler throws a warning when using int
        if (fracVec[i] > largest) {
            largest = fracVec[i];
        }
    }
    return largest;
}

// print - prints out contents of a vector of fraction objects with up to 5 fractions per line
void print(vector<Fraction> fracVec) {
    int counter = 1;
    for (unsigned int i = 0; i < fracVec.size(); i++) {
        cout << fracVec[i] << "  ";
        if ((counter % 5) == 0) {
            cout << endl;
            counter += 1;
        }
        else {
            counter += 1;
        }
    }   
}
