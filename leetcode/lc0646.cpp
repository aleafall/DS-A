<<<<<<< HEAD
//
// Created by aleafall on 17-9-8.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		unordered_map<string,int> mp;
		sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b) {
			if (a.front() != b.front()) {
				return a.front() < b.front();
			}
			return a.back() < b.back();
		});
		int ans = 1;
		vector<int> dp(pairs.size() + 1, 1);
		for (int i = 1; i < pairs.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (pairs[i].front() > pairs[j].back()) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};
=======
//
// Created by t-xiuyan on 7/23/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) {
			if (a.front() != b.back()) {
				return a.front() > b.back();
			}
			return a.back() < b.front();
		});
		int ans = 0;
		vector<int> dp(pairs.size() + 1, 1);
		for (int i = 0; i < pairs.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (pairs[j].front() > pairs[i].back()) {
					dp[i + 1] = max(dp[i + 1], dp[j + 1] + 1);
				}
			}
			ans = max(ans, dp[i + 1]);
		}
		return ans;
	}
};

>>>>>>> 758190852492f055a2a6122324716c916e0711bb
