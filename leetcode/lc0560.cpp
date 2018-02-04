//
// Created by aleafall on 17-5-22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int ans = 0;
		vector<int> a(nums.size(), 0);
		for (int i = 0; i < nums.size(); ++i) {
			if (i == 0) {
				a[i] = nums[i];
			} else {
				a[i] = nums[i] + a[i - 1];
			}
		}
		int a_i_j = 0;

		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i; j < nums.size(); ++j) {
				if (i == 0) {
					a_i_j = a[j];
				} else {
					a_i_j = a[j] - a[i - 1];
				}
				if (a_i_j == k) {
					++ans;
				}
			}
		}
		return ans;
	}
};
