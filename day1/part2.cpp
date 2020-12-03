#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	FILE* fptr = fopen("input.txt", "r");

	// read file into a vector.
	while(!feof(fptr)) {
		int num;
		fscanf(fptr, "%d\n", &num);
		v.push_back(num);
	}


	fclose(fptr);

	sort(v.begin(), v.end());

	int ans = 0;
	
	// O(n^3) soln, could be optimized using a hashmap but it's a small dataset.
	for(size_t i = 0; i < v.size(); i++) {
		for(size_t j = i + 1; j < v.size(); j++) {
			for(size_t k = j + 1; k < v.size(); k++) {
				if(v[k] + v[j] + v[i] == 2020) {
					ans = v[k] * v[j] * v[i];
					break;
				}
			}
			if(ans) {
				break;
			}
		}
		if(ans) {
			break;
		}
	}

	cout << ans << "\n";
	
	return 0;
}