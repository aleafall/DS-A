//
// Created by aleafall on 16-11-18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= num; ++i) {
            int now = ans[i >> 1] + (i & 1);
            ans.push_back(now);
        }
        return ans;
    }
};
