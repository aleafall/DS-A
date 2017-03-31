//
// Created by aleafall on 16-11-14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for (size_t i = 0; i <nums.size() ; ++i) {
            if (i) {
                ans ^= nums[i];
            } else {
                ans = nums[i];
            }
        }
        return ans;
    }
};
