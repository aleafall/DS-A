//
// Created by aleafall on 17-3-14.
//

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
			return 0;
		}
		vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
		for (int i = 0; i < dp.size(); ++i) {
			for (int j = 0; j < dp[0].size(); ++j) {
				if (i == 0 && j == 0) {
					dp[i][j] = !obstacleGrid[i][j];
				} else if (i == 0) {
					dp[i][j] = min(dp[i][j - 1],(int) !obstacleGrid[i][j]);
				} else if (j == 0) {
					dp[i][j] = min(dp[i-1][j],(int) !obstacleGrid[i][j]);
				} else if (obstacleGrid[i][j] == 0) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp.back().back();
	}
};
