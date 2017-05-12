//
// Created by aleafall on 17-4-29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int ans = 0, len = 0;
		for (auto &&item :nums) {
			if (item) {
				++len;
			} else {
				ans = max(ans, len);
				len = 0;
			}
		}
		return max(ans, len);
	}
};

