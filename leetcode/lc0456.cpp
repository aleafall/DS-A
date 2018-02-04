//
// Created by aleafall on 17-4-27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
	bool find132pattern(vector<int> &nums) {
		int s2 = INT32_MIN;
		stack<int> st;
		for (int i = (int) nums.size() - 1; i >= 0; --i) {
			if (nums[i] < s2) {
				return 1;
			} else {
				while (!st.empty() && nums[i] > st.top()) {
					s2 = st.top();
					st.pop();
				}
			}
			st.push(nums[i]);
		}
		return 0;
	}
};

int main() {
	Solution solution;
	vector<int> vi{1, 0, 1, -4, -3};
	cout << solution.find132pattern(vi) << endl;
	return 0;
}
