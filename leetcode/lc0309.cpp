//
// Created by aleafall on 17-10-16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() < 2) {
			return 0;
		}
		int ans = 0;
		vector<int> sells(prices.size(), 0);
		vector<int> buys(prices.size(), 0);
		buys.front() = -prices.front();
		buys[1] = -prices[1];
		for (int i = 1; i < prices.size(); ++i) {
			int delta = prices[i] - prices[i - 1];
			sells[i] = max(buys[i - 1] + prices[i], sells[i - 1] + delta);
			if (i > 1) {
				buys[i] = max(sells[i - 2] - prices[i], buys[i - 1] - delta);
			}
			ans = max(ans, sells[i]);
		}
		return sells.back();
	}
};

int main() {
	Solution solution;
	vector<int> vi{1, 2, 3, 0, 2};
	cout << solution.maxProfit(vi) << endl;
	return 0;
}
