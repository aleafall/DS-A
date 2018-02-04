//
// Created by aleafall on 17-11-20.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	bool selfDividing(int n){
		string str = to_string(n);
		for (auto &&item :str) {
			if (item == '0' || n % (item - '0')) {
				return 0;
			}
		}
		return 1;
	}
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ans;
		for (int i = left; i <= right; ++i) {
			if (selfDividing(i)) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};
