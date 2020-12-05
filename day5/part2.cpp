using namespace std;
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

int getSeatID(string seat) {

    // the row of the airplane.
    uint8_t row = 0;
    // read the first 7 characters of the binary space partition.
    // can get the row using binary operations.
    for(int i = 0; i < 7; i++) {
        // if we need to get the lower half, left shift it by one.
        if(seat[i] == 'F') {
            row <<= 1; 
        }
        // if we need to get the upper half, add a one and left shift it by one.
        else {
            row = (row + 1) << 1;
        }
    }

    // since we are only reading in 7 digits, right shift the final result by one. (uint8_t has 8 bits and we're working with 7)
    row >>= 1;

    // the column of the airplane.
    uint8_t col = 0;
    // read the last 3 characters
    for(int i = 7; i < 10; i++) {
        // if we need to get the lower half, left shift it by one.
        if(seat[i] == 'L') {
            col <<= 1; 
        }
        // if we need to get the upper half, add a one and left shift it by one.
        else {
            col = (col + 1) << 1;
        }
    }

    // since we are only reading in 7 digits, right shift the final result by one. (uint8_t has 8 bits and we're working with 7)
    col >>= 1;

    // the seat ID is the (row * 8) + col
    return (row * 8) + col;

}

int findYourSeat(vector<int> seatIDs) {
    
    // iterate through the seatIDs vector.
    for(size_t i = 1; i < seatIDs.size() - 1; i++) {
        // if your current seat ID is 2 greater than the last one, that means you skipped a seat and that's your seat!
        if(seatIDs[i] == seatIDs[i - 1] + 2) {
            // return the seat you're on minus 1 for your seat. 
            return seatIDs[i] - 1;
        }
    }

    // if we couldn't find the seat, return -1.
    return -1;
}

int main() {

    // the string will track the current seat we are parsing.
    string str;
    // open the seats inputs.
    ifstream seats;
    seats.open("input.txt");

    // keep a vector of our seat IDs.
    vector<int> seatIDs;

    // read in the seat ID and push it onto the vector.
    while(getline(seats, str)) {
        seatIDs.push_back(getSeatID(str));
    }

    // sort the seat IDs for easy comparison to find the missing value.
    sort(seatIDs.begin(), seatIDs.end());

    // call the findYourSeat function to find your seat!
    cout << findYourSeat(seatIDs) << "\n";

    // make sure you close your file!
    seats.close();

    return 0;
}
