//
// Created by aleafall on 17-3-10.
//

#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>> &envelopes) {
		int ans = 0;
		if (envelopes.empty()) {
			return 0;
		}
		sort(envelopes.begin(), envelopes.end());
		int dp[envelopes.size()];
		fill(dp, dp + envelopes.size(), 1);
		for (int i = 0; i < envelopes.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
					dp[i] = max(dp[i], dp[j] + 1);
					if (dp[i] == 4) {
						cout << "I " << i << endl;
					}
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};

