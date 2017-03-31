//
// Created by aleafall on 16-11-5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> cur;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        DFS(candidates, 0, 0, target);
        return ans;
    }
    void DFS(vector<int> &vi,int index,int sum,int target){
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
            cur.push_back(vi[i]);
            DFS(vi, i, sum + vi[i], target);
            cur.pop_back();
        }
    }
};

int main(){
    Solution *solution=new Solution;
    vector<int> vi{2, 3, 6, 7};
    int target=7;
    vector<vector<int>> ans = solution->combinationSum(vi, target);
    for (size_t i = 0; i <ans.size() ; ++i) {
        for (size_t j = 0; j <ans[i].size() ; ++j) {
            cout << ans[i][j] << " ";
        }
        cout<<endl;
    }
    delete solution;
    return 0;
}