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

    int tracker = 0;
    size_t row = 1;
    size_t column = 3;
    while(row < courseArr.size()) {
        // if the obstacle is a tree, increment tracker
        if(!courseArr[row][column]) {
            tracker++;
        }
        row++;
        column = (column + 3) % courseArr[0].size();
    }

    cout << tracker << "\n";

	return 0;
	}