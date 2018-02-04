//
// Created by aleafall on 17-9-11.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minCut(string s) {
		int len = s.size();
		int dp[s.size() + 1];
		for (int i = 0; i <= len; ++i) {
			dp[i] = i - 1;
		}
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j <= i && j + i < len && s[i - j] == s[i + j]; ++j) {
				dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
			}
			for (int j = 1; i - j + 1 >= 0 && i + j < len && s[i - j + 1] == s[i + j]; ++j) {
				dp[i + j + 1] = min(dp[i + j + 1], dp[i - j + 1] + 1);
			}
		}
		return dp[len];
	}
};

int main() {
	string s;
	s = "ababababababababababababcbabababababababababababa";
	Solution solution{};
	cout << solution.minCut(s) << endl;
	return 0;
}