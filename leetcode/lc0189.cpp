//
// Created by aleafall on 16-10-20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = (int) nums.size();
        if (n == 0) return;
        k %= n;
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

