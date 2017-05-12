//
// Created by aleafall on 17-4-9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		int ans = 0;
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); ++i) {
			if (matrix[i][0] == '1') {
				ans = 1;
				dp[i][0] = 1;
			}
		}
		for (int i = 0; i < matrix[0].size(); ++i) {
			if (matrix[0][i] == '1') {
				dp[0][i] = 1;
				ans = 1;
			}
		}
		for (int i = 1; i < matrix.size(); ++i) {
			for (int j = 1; j < matrix[0].size(); ++j) {
				if (matrix[i][j] == '0') {
					dp[i][j] = 0;
				} else {
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					ans = max(ans, dp[i][j]);
				}
			}
		}
		return ans * ans;
	}
};
