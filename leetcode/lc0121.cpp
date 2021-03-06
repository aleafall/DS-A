//
// Created by aleafall on 16-11-17.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
	    int ans = 0, Min = INT32_MAX;
        for (size_t i = 0; i < prices.size(); ++i) {
            Min = min(Min, prices[i]);
            ans = max(ans, prices[i] - Min);
        }
        return ans;
    }
};
