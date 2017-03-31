//
// Created by aleafall on 16-11-16.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n= (int) board.size();
        bool h[9][10] = {0}, v[9][10] = {0}, b[9][10] = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    int index = c - '1';
                    if (h[i][index] || v[j][index] || b[i / 3 * 3 + j / 3][index]) {
                        return 0;
                    } else {
                        h[i][index]=1;
                        v[j][index]=1;
                        b[i/3*3+j/3][index]=1;
                    }
                }
            }
        }
        return 1;

    }
};
