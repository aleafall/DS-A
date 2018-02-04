//
// Created by aleafall on 17-9-15.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int> &nums) {
		int len = nums.size();
		stack<int> st;
		vector<int> ans(len, -1);
		for (int i = 0; i < 2 * len; ++i) {
			int now = nums[i % len];
			while (!st.empty() && nums[st.top()] < now) {
				ans[st.top()] = now;
				st.pop();
			}
			if (i < len) {
				st.push(i);
			}
		}
		return ans;
	}
};
