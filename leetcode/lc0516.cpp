//
// Created by aleafall on 17-3-14.
//

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		if (s.empty()) {
			return 0;
		}
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
		for (int i = (int) s.size() - 1; i >= 0; --i) {
			dp[i][i] = 1;
			for (int j = i + 1; j < s.size(); ++j) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				} else {
					dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
				}
			}
		}
		return dp[0][s.size() - 1];
	}
};

int main() {
	Solution solution;
	string s;
	s = "1";
	cout << solution.longestPalindromeSubseq(s) << endl;
    return 0;
}
