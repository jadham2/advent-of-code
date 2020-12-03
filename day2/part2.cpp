#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	
	FILE* fptr = fopen("input.txt", "r");
	int numOccur = 0;
	
	while(!feof(fptr)) {
		int lb, rb;
		char c;
		char str [100];
		fscanf(fptr, "%d-%d %c: ", &lb ,&rb, &c);

		fgets(str, 100, fptr);

		if((str[lb - 1] == c && str[rb - 1] != c) || (str[lb - 1] != c && str[rb - 1] == c)) {
			numOccur++;
		}
	
	}

	fclose(fptr);

	cout << numOccur << "\n";
	
	return 0;
}