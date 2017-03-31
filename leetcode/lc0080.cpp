//
// Created by aleafall on 16-11-18.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int index = 0,cnt=0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[index++] = nums[i];
                cnt=1;
            } else if (cnt < 2) {
                nums[index++] = nums[i];
                cnt=2;
            }
        }
        return index;
    }
};
