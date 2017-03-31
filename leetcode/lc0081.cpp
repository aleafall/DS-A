//
// Created by aleafall on 16-10-25.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (size_t i = 0; i <nums.size() ; ++i) {
            if (target == nums[i]) {
                return 1;
            }
        }
        return 0;
    }
};
