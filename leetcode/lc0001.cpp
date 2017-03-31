//
// Created by aleafall on 16-10-5.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {

        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (target == nums[i] + nums[j]) {
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    return ans;
                }
            }
        }
    }
};

int main() {
    vector<int> ans, nums{2, 7, 11, 15};
    int target = 9;
    Solution *solution = new Solution();
    ans = solution->twoSum(nums, target);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
