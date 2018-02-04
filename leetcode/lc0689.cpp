//
// Created by aleafall on 17-10-2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<int> vi(nums.size()-k);
		int pre = 0;
		for (int i = 0; i < k; ++i) {
			pre += nums[i];
		}
		for (int i = 0; i < vi.size(); ++i) {
			if (i) {
				vi[i] =vi[i-1]+ nums[k + i - 1] - vi[i - 1];
			} else {
				vi[i] = pre;
			}
		}
	}
};