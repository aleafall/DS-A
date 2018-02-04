//
// Created by aleafall on 17-5-29.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end());
		unordered_map<int,vector<int>> mp;
		vector<int> dp(amount + 1, amount+1);
		dp[0] = 0;
		for (int i = 0; i < coins.size(); ++i) {
			for (int j = coins[i]; j <= amount; ++j) {
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
			}
		}
		/*for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j < coins.size(); ++j) {
				if (i >= coins[i]) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}*/
		return dp[amount] <= amount ? dp[amount] : -1;
	}
};

int main() {
	Solution solution;
	vector<int> vi{1,2,5};
	int amount =11;
	cout << solution.coinChange(vi, amount) << endl;
    return 0;
}
