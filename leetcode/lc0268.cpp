//
// Created by aleafall on 16-10-10.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        long long sum = 0;
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        return (int)((long long)n*(n+1)/2-sum);
    }
};
