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

		// now we just have to check the positions of the character in the password and we can do this in one line without a tracker like we had before.
		if((str[lb - 1] == c && str[rb - 1] != c) || (str[lb - 1] != c && str[rb - 1] == c)) {
			numOccur++;
		}
	
	}

	// make sure to close your file!
	fclose(fptr);

	cout << numOccur << "\n";
	
	return 0;
}