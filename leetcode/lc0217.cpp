//
// Created by aleafall on 17-2-5.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> st;
		for (int i = 0; i < nums.size(); ++i) {
			st.insert(nums[i]);
			if (st.size() < i + 1) {
				return 1;
			}
		}
		return 0;
	}
};
