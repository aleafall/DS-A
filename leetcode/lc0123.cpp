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
        int ans=0,Min=INT32_MAX,min_index,max_index;
        for (size_t i = 0; i < prices.size(); ++i) {
            if (Min >= prices[i]) {
                Min = prices[i];
                min_index = (int) i;
            }
            if (prices[i] - Min >= ans) {
                ans=prices[i]-Min;
                max_index = (int) i;
            }
            ans = max(ans, prices[i] - Min);
        }
        return ans;
    }
};
