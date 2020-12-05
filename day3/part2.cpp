#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {

    // starting to use proper file handling in C++!
    ifstream course;
    course.open("input.txt");

    // 2d vector to store the toboggan course. 
    vector<vector<short>> courseArr;
    // the current toboggan horizontal segment.
    vector<short> curr;
    
    // string to store the toboggan course.
    string str;

    // for each row of the toboggan course file, read it into str.
    while(getline(course, str)) {
        // check if each index in the row is a valid path or a tree.
        for(int i = 0; str[i] != '\0'; i++) {

            // if it is a valid path, push one, else, push a 0 since it's an invalid move.
            if(str[i] == '.') {
                curr.push_back(1);
            }
            else {
                curr.push_back(0);
            }
        }
        // once we are finished reading in the row, push it back to the file.
        courseArr.push_back(curr);

        // clear our vector to store the 1's and 0's.
        curr.clear();
    }

    // make sure to close your file!
    course.close();

    // tracker variable to keep track of how many trees we hit.
    long tracker = 1;

    // since we have multiple slopes to test, I store them in a 2D vector.
    vector<vector<short>> slopes {
        {1,1},
        {3,1},
        {5,1},
        {7,1},
        {1,2}
    };

    // learned how to use the auto type!
    // go through each slope
    for(auto j : slopes) {
        // tracker for the current slope, needs to reset to 0 for each run.
        int currTracker = 0;
        // start the row and column at wherever the slope is since that's the first value we are comparing.
        size_t row = j[1];
        size_t column = j[0];
        // increment through each row of the course.
        while(row < courseArr.size()) {
            // if the obstacle is a tree, increment tracker
            if(!courseArr[row][column]) {
                currTracker++;
            }
            // increment the rows and columns by the current slope.
            row = row + j[1];
            column = (column + j[0]) % courseArr[0].size();
        }

        // multiplies the number of trees hit for each slope. tracker starts at one instead of zero so that we get a legitimate product!
        tracker *= currTracker;
    }

    cout << tracker << "\n";

    return 0;
}