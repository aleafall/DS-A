//
// Created by aleafall on 17-9-17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int dp[amount + 1] = {0};
		int cnt[amount + 1] = {1};
		int ans = 0;
		for (int i = 0; i < coins.size(); ++i) {
			for (int j = coins[i]; j <= amount; ++j) {
				if (dp[j] < dp[j - coins[i]] + coins[i]) {
					cnt[j] = cnt[j - coins[i]];
					dp[j] = dp[j - coins[i]] + coins[i];
				} else if (dp[j] == dp[j - coins[i]] + coins[i]) {
					cnt[j] += cnt[j - coins[i]];
				}
			}
		}
		return cnt[amount];
	}
};

int main() {
	Solution solution;
	vector<int> coins{ 2};
	int amount = 3;
	cout << solution.change(amount, coins) << endl;
    return 0;
}