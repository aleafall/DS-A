//
// Created by aleafall on 16-11-5.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<int> cur;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        DFS(cur,ans,candidates, 0, 0, target);
        return ans;
    }
    void DFS(vector<int> &cur,vector<vector<int>> &ans ,vector<int> &vi,int index,int sum,int target){
        if (sum >= target) {
            if (sum == target) {
                ans.push_back(cur);
            }
            return;
        }
        if (index >= vi.size()) {
            return;
        }
        for (int i = index; i < vi.size(); ++i) {
            if (i > index && vi[i] == vi[i - 1]) {
                continue;
            }
            if (vi[i] > target) {
                return;
            }
            cur.push_back(vi[i]);
            DFS(cur,ans,vi, i+1, sum + vi[i], target);
            cur.pop_back();
        }
    }
};

int main(){
    Solution *solution=new Solution;
    vector<int> vi{10, 1, 2, 7, 6,1, 5};
    sort(vi.begin(), vi.end());
    int target=8;
    vector<vector<int>> ans = solution->combinationSum2(vi, target);
    for (size_t i = 0; i <ans.size() ; ++i) {
        for (size_t j = 0; j <ans[i].size() ; ++j) {
            cout << ans[i][j] << " ";
        }
        cout<<endl;
    }
    delete solution;
    return 0;
}

