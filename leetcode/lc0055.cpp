//
// Created by aleafall on 16-11-17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool ans=0;
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 1;
        }
        int rightMost=0;
        for (size_t i = 0; i <nums.size() ; ++i) {
            if (rightMost < i + 1) {
                break;
            }
            rightMost = max(rightMost, (const int &) (i + nums[i]));
        }
        return rightMost>=nums.size()-1;
    }

    void DFS(vector<int> &nums, int next) {
        if (ans) {
            return;
        }
        if (next == nums.size() - 1) {
            ans = 1;
            return;
        }
        if (nums[next] == 0) {
            return;
        }
        for (int i = (int) min(nums.size() - 1, (const unsigned long &) (next + nums[next])); i > next; --i) {
            DFS(nums, i);
        }
    }
};
