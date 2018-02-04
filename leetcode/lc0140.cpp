//
// Created by aleafall on 17-5-28.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
	vector<string> ans;
public:
	vector<string> wordBreak(string s, vector<string> &wordDict) {
		unordered_set<string> st;
		vector<bool> dp(s.size() + 1, 0);
		vector<vector<int>> pre(s.size() + 1);
		dp[0] = 1;
		for (auto &&item :wordDict) {
			st.insert(item);
		}
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (dp[j]) {
					string now = s.substr(j, i - j);
					if (st.count(now)) {
						dp[i] = 1;
						pre[i].push_back(j);
					}
				}
			}
		}
		vector<int> vi{s.size()};
		DFS(vi, s, pre);
		return ans;
	}

	void DFS(vector<int> vi, string &s, vector<vector<int>> &pre) {
		if (vi.back() == 0) {
			string now;
			for (int i = (int) vi.size() - 1; i; --i) {
				now += s.substr(vi[i], vi[i - 1] - vi[i]);
				if (i > 1) {
					now += " ";
				}
			}
			ans.push_back(now);
			return;
		}
		for (int i = 0; i < pre[vi.back()].size(); ++i) {
			vi.push_back(pre[vi.back()][i]);
			DFS(vi, s, pre);
			vi.pop_back();
		}
	}
};

