//
// Created by aleafall on 17-2-26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.empty()) {
			return 0;
		}
		int hashTable[15] = {0};
		int Max = -1, Min = 14;
		for (int i = 0; i < numbers.size(); ++i) {
			if (numbers[i]) {
				hashTable[numbers[i]]++;
				if (hashTable[numbers[i]] > 1) {
					return 0;
				}
				Min = min(Min, numbers[i]);
				Max = max(Max, numbers[i]);
			}
		}
		return Max - Min <= numbers.size() - 1;
	}
};

int main() {
	Solution solution;
	vector<int> vi{1, 3, 0, 0, 5};
	cout << solution.IsContinuous(vi) << endl;
}