//
// Created by aleafall on 17-10-16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (k <= 0) {
			return 0;
		}
		vector<int> sells(k, 0), buys(k, INT32_MIN);
		for (int i = 0; i < prices.size(); ++i) {
			for (int j = k - 1; j >= 0; --) {
				sells[j] = max(sells[j], prices[i] + buys[j]);
				if (j) {
					buys[j] = max(buys[j], sells[j - 1] - prices[i]);
				} else {
					buys[j] = max(buys[j], -prices[i]);
				}
			}
		}
		return sells.back();
	}
};
