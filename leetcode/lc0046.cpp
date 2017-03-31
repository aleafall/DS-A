//
// Created by aleafall on 16-11-5.
//

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        if (nums.empty()) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        long long cnt = 1;
        int n = (int) nums.size();
        for (int i = 1; i <= n; ++i) {
            cnt *=(long long)i;
        }
        for (long long i = 0; i < cnt; ++i) {
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
    }
};
int main(){
    vector<int> nums{1,1,2};
    Solution *solution=new Solution;
    vector<vector<int>> ans = solution->permute(nums);
    delete solution;
    for (size_t i = 0; i <ans.size() ; ++i) {
        for (size_t j = 0; j <ans[0].size() ; ++j) {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
