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

    // new tracker variable to keep track of how many trees we hit!
    int tracker = 0;
    // initial row and column start.
    size_t row = 1;
    size_t column = 3;
    // iterate through the entire course.
    while(row < courseArr.size()) {
        // if the obstacle is a tree (which is represented as a 0 in courseArr), increment tracker
        if(!courseArr[row][column]) {
            tracker++;
        }
        // increment row.
        row++;
        // since the course has a repeating pattern, we can implement the modulus function to start right back at the beginning if we go over.
        column = (column + 3) % courseArr[0].size();
    }

    cout << tracker << "\n";

    return 0;
}