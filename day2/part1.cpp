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

        int tracker = 0;
		for(int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
            if(str[i] == c) {
                tracker++;
            }
        }

        if(tracker >= lb && tracker <= rb) {
            numOccur++;
        }
	
	}

	fclose(fptr);

	cout << numOccur << "\n";
	
	return 0;

}