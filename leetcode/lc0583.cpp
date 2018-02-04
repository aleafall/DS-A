//
// Created by aleafall on 17-5-20.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int dp[word1.size() + 1][word2.size() + 1];
		dp[0][0] = word1[0] == word2[0];
		for (int i = 0; i <= word1.size(); ++i) {
			for (int j = 0; j <= word2.size(); ++j) {
				if (i == 0 || j == 0) {
					dp[i][j] = 0;
				} else {
					dp[i][j] = max(dp[i - 1][j - 1] + (int) (word1[i - 1] == word2[j - 1]),
					               max(dp[i - 1][j], dp[i][j - 1]));
				}
			}
		}
		return word1.size() - dp[word1.size()][word2.size()] + word2.size() - dp[word1.size()][word2.size()];
	}
};
