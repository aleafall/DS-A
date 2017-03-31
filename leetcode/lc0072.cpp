//
// Created by aleafall on 17-3-12.
//

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i <= word1.size(); ++i) {
			dp[i][0] = i;
		}
		for (int i = 0; i <= word2.size(); ++i) {
			dp[0][i] = i;
		}
		for (int i = 1; i <= word1.size(); ++i) {
			for (int j = 1; j <= word2.size(); ++j) {
				int now = 0;
				if (word1[i - 1] == word2[j - 1]) {
					now = dp[i - 1][j - 1];
				} else {
					now = now = dp[i - 1][j - 1] + 1;
				}
				now = min(now, dp[i - 1][j] + 1);
				dp[i][j] = min(now, dp[i][j - 1] + 1);
			}
		}
		return dp[word1.size()][word2.size()];
	}
};
