//
// Created by aleafall on 16-10-29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return (int) nums.size();
        }
        int pre = nums[0],ans=1;
        for (size_t i = 1; i <nums.size() ; ++i) {
            if (nums[i] != pre) {
                nums[ans++] = nums[i];
                pre = nums[i];
            }
        }
        return ans;
    }
};
