//
// Created by aleafall on 16-11-20.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.empty()) {
            return 0;
        }
        vector<vector<int>> ans = triangle;
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    ans[i][j] += ans[i - 1][j];
                } else if (j == ans[i].size() - 1) {
                    ans[i][j] += ans[i - 1][j - 1];
                } else {
                    ans[i][j] += min(ans[i - 1][j - 1], ans[i - 1][j]);
                }
            }
        }
        int res=INT32_MAX;
        for (int i = 0; i < ans[ans.size()-1].size(); ++i) {
            res = min(res, ans[ans.size() - 1][i]);
        }
        return res;
    }
};
