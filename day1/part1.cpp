#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	// vector to store expenses.
	vector<int> v;
	FILE* fptr = fopen("input.txt", "r");

	// read the file of expenses into a vector.
	while(!feof(fptr)) {
		int num;
		fscanf(fptr, "%d\n", &num);
		v.push_back(num);
	}


	fclose(fptr);

	// sort the file for faster possible location.
	sort(v.begin(), v.end());

	int ans = 0;
	// O(n^2) soln, could be optimized to O(n) w/ hashmap but it's a small dataset.
	// A simple knapsack problem. Compare the current value with subsequent values in the vector and check which sum to 2020.
	// this solution is not optimized but the dataset is relatively small.
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

	cout << ans << "\n";
	
	return 0;
}
