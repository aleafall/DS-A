//
// Created by aleafall on 17-9-29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i <= s.size(); ++i) {
			if (p[i - 1] == '*') {
				dp[0][i] = dp[0][i - 1];
			}
		}
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = 1; j <= p.size(); ++j) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				} else {
					dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
				}
			}
		}
		return dp[s.size()][p.size()];
	}
};

int main() {
	Solution solution;
	string s = "bbbbabaabbabbababaabaabababaababaaaabaaabbbabbbbbbabbabbabbaaabaababbbababbbaaababbbbaabbaababbabababbbbbbabbbbbaabbabaababbabbbbbbaabbbabbbaabaaababaabaaaabababbababbaaabbaabaabaabbbbbbaabbaaaaaabbabb";
	string p = "aa***bb*b**a***bb***b*b*ba********ba***bbbb*bba*a*b***ba*a*b**aabbba*aba****a*ba*****a*bab**a**b**b*a*";
	cout << s.size() << " " << p.size() << endl;
	cout << solution.isMatch(s, p) << endl;
	/*
	 bool isMatch(string s, string p) {
		return isMatch(s, p, 0, 0);
	}
	bool isMatch(string &s,string &p,int i,int j){
		if (j >= p.size()) {
			return i >= s.size();
		}
		if (p[j] == '*') {
			for (int k = s.size(); k >=i; --k) {
				if (isMatch(s, p, k, j + 1)) {
					return 1;
				}
			}
			return 0;
		} else if (p[j] == '?') {
			return i >= s.size() ? 0 : isMatch(s, p, i + 1, j + 1);
		} else if (i < s.size() && s[i] == p[j]) {
			return isMatch(s, p, i + 1, j + 1);
		}
		return 0;
	}
	 */
	return 0;
}
