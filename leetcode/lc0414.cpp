//
// Created by aleafall on 16-10-25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int flag = 0,  Max = 0;
        long long pre=INT64_MAX;
        for (int i = 0; i < 3; ++i) {
            long long now = INT64_MIN;
            for (size_t j = 0; j < nums.size(); ++j) {
                if (nums[j] > now && nums[j] < pre) {
                    now = nums[j];
                }
            }
            if (now != INT64_MIN) {
                pre = now;
                flag++;
                if (flag == 1) {
                    Max = (int) now;
                }
            }
        }
        if (flag == 3) {
            return (int) pre;
        } else {
            return Max;
        }
    }
};

int main() {
    Solution *solution = new Solution;
    vector<int> vi{1,2,-2147483648};
    cout << solution->thirdMax(vi) << endl;
    delete solution;
    return 0;
}