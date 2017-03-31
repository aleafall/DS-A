//
// Created by aleafall on 16-11-5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combine(int n, int k) {
//        vector<int> cur((unsigned long) k, 0);
        vector<int> cur;
        DFS(cur, n, 0,1,k);
        return ans;
    }

    void DFS(vector<int> &cur, int n, int index,int next,int k) {
//        if (index  == cur.size()) {
//            ans.push_back(cur);
//            return;
//        }
//        for (int i = next; i <= n; ++i) {
//            cur[index] = i;
//            DFS(cur, n, index + 1,next+1);
//        }
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        for (int i = next; i <= n; ++i) {
            cur.push_back(i);
            DFS(cur, n, i + 1, i+1, k);
            cur.pop_back();
        }
    }
};

int main() {
    Solution *solution = new Solution;
    vector<vector<int>> ans = solution->combine(4, 4);
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    delete solution;
    return 0;
}