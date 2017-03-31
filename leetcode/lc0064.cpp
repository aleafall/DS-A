//
// Created by aleafall on 16-11-18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int s[grid.size()][grid[0].size()] = {0};
        for (size_t i = 0; i <grid.size() ; ++i) {
            if (i) {
                s[i][0] = s[i - 1][0] + grid[i][0];
            } else {
                s[i][0] = grid[i][0];
            }
        }
        for (size_t i = 0; i <grid[0].size() ; ++i) {
            if (i) {
                s[0][i] = s[0][i - 1] + grid[0][i];
            } else {
                s[0][i] = grid[0][i];
            }
        }
        for (size_t i = 0; i <grid.size() ; ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (i && j) {
                    s[i][j] = min(s[i - 1][j], s[i][j - 1]) + grid[i][j];
                }
            }
        }
        return s[grid.size() - 1][grid[0].size() - 1];
    }
};
