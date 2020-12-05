using namespace std;
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

int getSeatID(string seat) {

    uint8_t row = 0;
    // read the first 7 characters of the binary space partition.
    for(int i = 0; i < 7; i++) {
        if(seat[i] == 'F') {
            row <<= 1; 
        }
        else {
            row = (row + 1) << 1;
        }
    }

    row >>= 1;

    uint8_t col = 0;
    // read the last 3 characters
    for(int i = 7; i < 10; i++) {
        if(seat[i] == 'L') {
            col<<= 1;
        }
        else {
            col = (col + 1) << 1;
        }
    }

    col >>= 1;

    return (row * 8) + col;

}

int main() {

    string str;
    ifstream seats;
    seats.open("input.txt");
    int seatMax = 0;

    while(getline(seats, str)) {
        seatMax = max(seatMax, getSeatID(str));
    }

    cout << seatMax << "\n";
	return 0;
}
