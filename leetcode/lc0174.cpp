//
// Created by aleafall on 16-11-18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) {
            return 1;
        }
        int s[dungeon.size()][dungeon[0].size()] = {0};
        size_t m = dungeon.size(), n = dungeon[0].size();
        for (int i = m-1; i >=0 ; --i) {
            for (int j = n-1; j >=0 ; --j) {
                if (i==m-1&&j==n-1) {
                    s[i][j] = max(1,1-dungeon[i][j]);
                } else if (i == m - 1) {
                    s[i][j] = max(1, s[i][j+1] - dungeon[i][j]);
                } else if (j == n - 1) {
                    s[i][j] = max(1, s[i + 1][j] - dungeon[i][j]);
                } else {
                    s[i][j] = max(1, min(s[i + 1][j], s[i][j + 1]) - dungeon[i][j]);
                }
            }
        }
        return s[0][0];
    }
};
