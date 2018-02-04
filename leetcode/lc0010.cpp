//
// Created by aleafall on 17-3-1.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, 0));
		dp[0][0] = 1;
		for (int i = 2; i <= p.size(); ++i) {
			if (p[i - 1] == '*') {
				dp[0][i] = dp[0][i - 2];
			}
		}
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = 1; j <= p.size(); ++j) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
				} else {
					dp[i][j] = (p[j - 1] == '.' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1];
				}
//				cout << "i j " << i << " " << j << " " << dp[i][j] << endl;
			}
		}
		return dp[s.size()][p.size()];
	}
};

int main() {
	string s = "ab";
	string p = ".*";
	Solution solution;
	cout << solution.isMatch(s, p) << endl;
	return 0;
}