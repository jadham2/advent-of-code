#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	
	FILE* fptr = fopen("input.txt", "r");
	
	// variable to track the valid passwords.
	int numOccur = 0;
	while(!feof(fptr)) {
		// upper and lower bound variables.
		int lb, rb;
		// the character to check in the password.
		char c;
		// the password with a character limit of 100.
		char str [100];
		// scan the character in to the variables.
		fscanf(fptr, "%d-%d %c: ", &lb ,&rb, &c);

		// get the password itself.
		fgets(str, 100, fptr);

		// tracker to count the occurences in the password.
    	int tracker = 0;
		for(int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        	if(str[i] == c) {
            	tracker++;
        	}
    	}

		// check the tracker against the upper and lower bound.
		// if it is within, then the password is valid and we increment numOccur.
    	if(tracker >= lb && tracker <= rb) {
        	numOccur++;
    	}
	
	}

	// make sure you close the file!
	fclose(fptr);

	cout << numOccur << "\n";
	
	return 0;
}