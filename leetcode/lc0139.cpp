//
// Created by aleafall on 16-12-11.
//
// go back char by char
#include<iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string> &wordDict) {
unordered_set<string> st;
		for (auto &&item :wordDict) {
			st.insert(item);
		}
		vector<bool> dp(s.size() + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (dp[j]) {
					string now = s.substr(j, i - j);
					if (st.count(now)) {
						dp[i] = 1;
						break;
					}
				}
			}
		}
		return dp[s.size()];
	}
};

