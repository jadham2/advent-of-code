using namespace std;
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

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

int main() {

    // the string will track the current seat we are parsing.
    string str;
    // open the seats inputs.
    ifstream seats;
    seats.open("input.txt");

    // variable to track the maximum seat ID
    int seatMax = 0;

    // read in the seats file.
    while(getline(seats, str)) {
        // the largest seat ID is the maximum of the current one and the one we are reading in.
        seatMax = max(seatMax, getSeatID(str));
    }

    cout << seatMax << "\n";

    // make sure to close your file!
    seats.close();

	return 0;
}
