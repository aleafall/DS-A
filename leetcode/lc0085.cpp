//
// Created by aleafall on 17-3-11.
//

#include<iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		vector<vector<int>> heights(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				heights[i][j] = matrix[i][j] - '0';
			}
		}
		return maxRectanle(heights);
	}

	int maxRectanle(vector<vector<int>> &heights) {
		int ans = 0;
		for (int i = 0; i < heights.size(); ++i) {
			if (i) {
				for (int j = 0; j < heights[0].size(); ++j) {
					if (heights[i][j] == 1) {
						heights[i][j] += heights[i - 1][j];
					}
				}
			}
			ans = max(ans, getLargestArea(heights[i]));
		}
		return ans;
	}
	int getLargestArea(vector<int> &height){
		int ans = 0;
		stack<int> st;
		height.push_back(0);
		for (int i = 0; i < height.size(); ++i) {
			if (st.empty() || st.top() < height[i]) {
				st.push(height[i]);
			} else {
				int cnt = 0;
				while (!st.empty() && st.top() > height[i]) {
					++cnt;
					ans = max(ans, st.top() * cnt);
					st.pop();
				}
				while (cnt--) {
					st.push(height[i]);
				}
				st.push(height[i]);
			}
		}
		height.pop_back();
		return ans;
	}
};
