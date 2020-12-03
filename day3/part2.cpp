#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ifstream course;
    course.open("input.txt");
    vector<vector<short>> courseArr;
    vector<short> curr;
    string str;

    while(getline(course, str)) {
        for(int i = 0; str[i] != '\0'; i++) {
            if(str[i] == '.') {
                curr.push_back(1);
            }
            else {
                curr.push_back(0);
            }
        }
        courseArr.push_back(curr);
        curr.clear();
    }

    course.close();

    long tracker = 1;
    vector<vector<short>> slopes {
        {1,1},
        {3,1},
        {5,1},
        {7,1},
        {1,2}
    };
    for(auto j : slopes) {
        int currTracker = 0;
        size_t row = j[1];
        size_t column = j[0];
        while(row < courseArr.size()) {
            // if the obstacle is a tree, increment tracker
            if(!courseArr[row][column]) {
                currTracker++;
            }
            row = row + j[1];
            column = (column + j[0]) % courseArr[0].size();
        }
        tracker *= currTracker;
    }

    cout << tracker << "\n";

    return 0;
}