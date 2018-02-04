//
// Created by aleafall on 17-4-8.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) {
			return 0;
		}
		bool dp[s1.size() + 1][s2.size() + 1] = {0};
		for (int i = 0; i <= s1.size(); ++i) {
			for (int j = 0; j <= s2.size(); ++j) {
				if (i == 0 && j == 0) {
					dp[i][j] = 1;
				} else if (i == 0) {
					dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
				} else if (j == 0) {
					dp[i][j] = dp[i-1][j] && s1[i - 1] == s3[i + j - 1];
				} else {
					dp[i][j]=(dp[i-1][j]&&s1[i-1]==s3[i+j-1])||(dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
				}
			}
		}
		return dp[s1.size()][s2.size()];
	}
	bool canSep(string &s1,string &s2,string &s3){
		vector<bool> vis(s3.size(), 0);
		int index = 0;
		for (int i = 0; i < s3.size(); ++i) {
			if (s3[i] == s1[index]) {
				++index;
				vis[i] = 1;
			}
		}
		if (index < s1.size()) {
			return 0;
		}
		index = 0;
		for (int i = 0; i < s3.size(); ++i) {
			if (vis[i] == 0 && s3[i] == s2[index]) {
				index++;
			}
		}
		return index >= s2.size();
	}
};

