//
// Created by aleafall on 16-11-5.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> cur;
    vector<vector<int>> ans;

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<bool> vis(nums.size(), 0);
//        DFS(nums, vis);
	    helper(nums, 0);
        return ans;
    }

    void helper(vector<int> &nums,int index){
	    if (index == nums.size() - 1) {
		    ans.push_back(nums);
		    return;
	    }
	    for (int i = index; i < nums.size(); ++i) {
		    if (i != index && nums[i] == nums[index]) {
			    continue;
		    }
		    swap(nums[index], nums[i]);
		    helper(nums, index + 1);
	    }
    }
    void DFS(vector<int> &nums, vector<bool> &vis) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (!vis[i]) {
                if (i == nums.size() - 1 || nums[i] != nums[i + 1] || vis[i + 1]) {
                    cur.push_back(nums[i]);
                    vis[i] = 1;
                    DFS(nums, vis);
                    vis[i] = 0;
                    cur.pop_back();
                }
            }
        }
    }

};

int main() {
    vector<int> nums{1, 1, 2};
    Solution *solution = new Solution;
    vector<vector<int>> ans = solution->permuteUnique(nums);
    delete solution;
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}