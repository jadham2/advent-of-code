#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

int main() {
	std::vector<int> v;
	FILE* fptr = fopen("input.txt", "r");

	// read file into a vector.
	while(!feof(fptr)) {
		int num;
		fscanf(fptr, "%d\n", &num);
		v.push_back(num);
	}


	fclose(fptr);

	std::sort(v.begin(), v.end());

	int ans = 0;
	for(size_t i = 0; i < v.size(); i++) {
		for(size_t j = i + 1; j < v.size(); j++) {
			if(v[i] + v[j] == 2020) {
				ans = v[i] * v[j];
			}
		}
		if(ans) {
			break;
		}
	}

	std::cout << ans << "\n";
	
	return 0;
	}
