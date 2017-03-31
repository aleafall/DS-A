//
// Created by aleafall on 16-11-18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> ans;
        if (nums.empty()) {
            return ans;
        }
        int cnt=0;
        long long total = 1;
        for (auto item:nums) {
            if (item) {
                total *= item;
            } else {
                cnt++;
            }
        }
        if (cnt > 1) {
            for (size_t i = 0; i <nums.size() ; ++i) {
                ans.push_back(0);
            }
        } else if (cnt == 1) {
            for (auto item:nums) {
                if (item) {
                    ans.push_back(0);
                } else {
                    ans.push_back((const int &) total);
                }
            }
        } else {
            for (auto item:nums) {
                ans.push_back((int &&) (total / item));
            }
        }
        return ans;
    }
};
