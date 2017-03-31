//
// Created by aleafall on 17-2-16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array,int sum) {
		vector<int> ans;
		if (array.size() < 1) {
			return ans;
		}
		int i = 0, j = array.size() - 1;
		while (i < j) {
			if (array[i] + array[j] < sum) {
				++i;
			} else if (array[i] + array[j] > sum) {
				--j;
			} else {
				if (ans.empty()) {
					ans = vector<int>{array[i], array[j]};
				} else if (array[i] * array[j] < ans[0] * ans[1]) {
					ans[0] = array[i], ans[1] = array[j];
				}
				++i;
			}
		}
		return ans;
	}
};
