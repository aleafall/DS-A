//
// Created by aleafall on 16-10-24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (size_t i = 0; i <nums.size() ; ++i) {
            if (nums[i] == target) {
                return (int) i;
            }
        }
        return -1;
    }
};
