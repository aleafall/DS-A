//
// Created by aleafall on 17-5-29.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
		unordered_set<string> st(words.begin(), words.end());
		vector<string> ans;
		for (auto &&item :words) {
			vector<bool> dp(item.size() + 1, 0);
			dp[0] = 1;
			for (int i = 1; i <= item.size(); ++i) {
				for (int j = i - 1; j >= 0; --j) {
					if (dp[j] && (j || i != item.size())) {
						string now = item.substr(j, i - j);
						if (st.count(now)) {
							dp[i] = 1;
							break;
						}
					}
				}
			}
			if (!item.empty() && dp[item.size()]) {
				ans.push_back(item);
			}
		}
		return ans;
	}
};

int main() {
	Solution solution;
	vector<string> words{""};
	auto ans = solution.findAllConcatenatedWordsInADict(words);
	cout << ans.size() << endl;
	return 0;
}