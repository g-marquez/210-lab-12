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

int main() {
    //declare std::array of SIZE 35 via reading data from a file,
    //using .size() to loop through the array and populate
    array<double, SIZE> runTimes;
    ifstream fin("run_times.txt");
    if (fin.good()) {
        for (int i = 0; i < runTimes.size(); ++i)
            fin >> runTimes[i];
        fin.close();
    }
    else {
        cout << "ERROR! Please verify file name/directory and restart program.";
        return 1;
    }

    return 0;
}