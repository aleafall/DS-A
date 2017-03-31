//
// Created by aleafall on 17-2-16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty() || array[0].empty()) {
			return 0;
		}
		int i = 0, j = array[0].size() - 1;
		while (i < array.size() && j >= 0) {
			if (array[i][j] == target) {
				return 1;
			} else if (array[i][j] > target) {
				--j;
			} else {
				++i;
			}
		}
		return 0;
	}
};
