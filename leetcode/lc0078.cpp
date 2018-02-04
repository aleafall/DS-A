//
// Created by aleafall on 16-10-16.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
	    sort(nums.begin(), nums.end());
	    int cnt = (1 << nums.size());
	    vector<vector<int>> ans(cnt);
	    for (int i = 0; i < nums.size(); ++i) {
		    for (int j = 0; j < cnt; ++j) {
			    if ((j >> i) & 1) {
				    ans[j].push_back(nums[i]);
			    }
		    }
	    }
	    return ans;
    }
};
