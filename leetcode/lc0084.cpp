//
// Created by aleafall on 16-11-8.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &heights) {
		int ans = 0;
		stack<int> st;
		heights.push_back(0);
		for (int i = 0; i < heights.size(); ++i) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				int now = heights[st.top()];
				st.pop();
				int width = st.empty() ? -1 : st.top();
				ans = max(ans, now * (i - width - 1));
			}
			st.push(i);
		}
		return ans;
	}
};

int main() {
	Solution *solution = new Solution;
	vector<int> vi{4, 2, 0, 3, 2, 4, 3, 4};
	vi = {1, 2, 6};
	int ans = solution->largestRectangleArea(vi);
	cout << ans << endl;
	delete solution;
	return 0;
	/*
	 for (size_t i = 0; i < heights.size(); ++i) {
			if (st.empty() || st.top() <= heights[i]) {
				st.push(heights[i]);
			} else {
				int cnt = 0;
				while (!st.empty() && st.top() > heights[i]) {
					cnt++;
					ans = max(ans, st.top() * cnt);
					st.pop();
				}
				while (cnt--) {
					st.push(heights[i]);
				}
				st.push(heights[i]);
			}
		}
		int cnt = 1;
		while (!st.empty()) {
			ans = max(ans, st.top() * cnt);
			cnt++;
			st.pop();
		}
	 * */
}
