//
// Created by aleafall on 16-11-9.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int ans = 1;
        sort(nums.begin(), nums.end());
        vector<int> vi(nums.size() + 1, 1);
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i) {
                if (nums[i] == nums[i - 1] + 1) {
                    vi[i] = vi[i - 1] + 1;
                } else if (nums[i] == nums[i - 1]) {
                    vi[i] = vi[i - 1] ;
                }
                ans = max(ans, vi[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> nums{100, 4, 200, 1, 3, 2};
    cout<<solution.longestConsecutive(nums)<<endl;
    return 0;
}


