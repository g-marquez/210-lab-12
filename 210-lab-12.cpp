//*****************************************************************************
// COMSC-210 | Lab 12 | Gabriel Marquez
// Description: this program exercises a variety of std::array functions by
// tracking 10 kilometer run times over a span of 35 days.
//*****************************************************************************

#include <iostream>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <array>
#include <fstream>
using namespace std;

const int SIZE = 35;

void displayTimes(const array<double, SIZE> &);

int main() {
    //declare std::array of SIZE 35 via reading data from a file,
    //using .size() to loop through the array and .at(i) to
    // populate each element and confirming with .empty()
    cout << "Populating runTimes array..." << endl;
    array<double, SIZE> runTimes;
    ifstream fin("run_times.txt");
    if (fin.good()) {
        for (int i = 0; i < runTimes.size(); ++i)
            fin >> runTimes.at(i);
        fin.close();
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }
    if (!runTimes.empty())
        cout << "Complete!" << endl;

    //loop to display elements in runTimes
    cout << "10 kilometer run times in minutes from the past 35 days:" << endl;
    displayTimes(runTimes);

    return 0;
}

void displayTimes(const array<double, SIZE> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i]; 
        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << endl;
}