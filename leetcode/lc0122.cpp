//
// Created by aleafall on 16-11-17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if (prices.empty()) {
            return 0;
        }
        for (size_t i = 1; i <prices.size() ; ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                ans += prices[i] - prices[i - 1];
            }
        }
        return ans;
    }
};
