//
// Created by aleafall on 16-10-24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int Min=INT32_MAX;
        for (size_t i = 0; i <nums.size() ; ++i) {
            if (Min > nums[i]) {
                Min = nums[i];
            }
        }
        return Min;
    }
};
