//
// Created by aleafall on 16-11-5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        DFS(cur, ans, 1, k, n);
        return ans;

    }
    void DFS(vector<int> &cur,vector<vector<int>> &ans,int index,int k,int now){
        if (k == 0) {
            if (now == 0) {
                ans.push_back(cur);
            }
            return;
        }
        if (now < 0 || index > now) {
            return;
        }
        for (int i = index; i <= 9; ++i) {
            cur.push_back(i);
            DFS(cur, ans, i + 1, k - 1, now - i);
            cur.pop_back();
        }
    }
};

int main(){
    Solution *solution=new Solution;
    int k=3,n=9;
    vector<vector<int>> ans = solution->combinationSum3(k, n);
    for (size_t i = 0; i <ans.size() ; ++i) {
        for (size_t j = 0; j <ans[i].size() ; ++j) {
            cout << ans[i][j] << " ";
        }
        cout<<endl;
    }
    delete solution;
    return 0;
}
