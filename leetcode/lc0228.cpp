//
// Created by aleafall on 16-11-20.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) {
            return ans;
        }
        int begin=0,end=0;
        while (end < nums.size()) {
            while (end + 1 < nums.size() && nums[end+1] == nums[begin] + 1) {
                ++end;
            }
            if (end != begin) {
                ans.push_back(to_string(nums[begin]) + "->" + to_string(nums[end]));
            } else {
                ans.push_back(to_string(nums[begin]));
            }
            ++end;
            begin = end;
        }
        return ans;
    }
};
