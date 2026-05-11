#ifndef MAIN_HPP
#define MAIN_HPP

// Construct an array-of-records from a multi-column data file (babyname.txt)
// and search for matching names by state and starting character.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int N = 5000;

int makeNameRecord(string[], string[], int[], string[], int[]);
void printoutallrecords(int, string[], string[], int[], string[], int[]);
int findNames(int, string[], string[], int[], string[], int[], char, string);
void printoutcontents(string, string, int, string, int);

int makeNameRecord(string state[], string gender[], int year[], string name[], int count[])
{
    // TODO: open "babyname.txt", read each line into the parallel arrays,
    ifstream inputFile("babyname.txt");
    if (!inputFile) {
        cout << "Cannot open babyname.txt" << endl;
        return 1;
    }

    int _count = 0;
    while (inputFile >> state[_count] >> gender[_count] >> year[_count] >> name[_count] >> count[_count]) {
        _count += 1;
    }
    inputFile.close();
    return _count;
}

int findNames(int cnt, string state[], string gender[], int year[], string name[], int count[], char starting, string stname)
{
    // TODO: print each record where the state matches `stname` and the name
    int match = 0;
    for (int i = 0; i < cnt; i++) {
        if (state[i] == stname) {
            if (name[i].rfind(string(1, starting), 0) == 0) {
                printoutcontents(state[i], gender[i], year[i], name[i], count[i]);
                match += 1;
            }
        }
    }
    cout << "total lines: " << match << endl;
    return match;
}

void printoutallrecords(int cnt, string state[], string gender[], int year[], string name[], int count[])
{
    for (int i = 0; i < cnt; i++)
        printoutcontents(state[i], gender[i], year[i], name[i], count[i]);
    cout << "total lines: " << cnt << endl;
}

void printoutcontents(string statename, string sex, int year, string name, int count)
{
    cout << setw(5) << statename << "\t";
    cout << setw(3) << sex << "\t";
    cout << setw(5) << year << "\t";
    cout << setw(10) << name << "\t\t";
    cout << setw(5) << count << endl;
}

#endif
