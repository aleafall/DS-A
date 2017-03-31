//
// Created by aleafall on 16-11-16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int n;
    bool h[9][10],v[9][10],b[9][10];
    void solveSudoku(vector<vector<char>>& board) {
        n = (int) board.size();
        fill(h[0], h[0] + 9 * 10, 0);
        fill(v[0], v[0] + 9 * 10, 0);
        fill(b[0], b[0] + 9 * 10, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.') {
                    h[i][board[i][j]-'0']=1;
                    v[j][board[i][j] - '0']=1;
                    b[i / 3 * 3 + j / 3][board[i][j] - '0'] = 1;
                }
            }
        }
        solve(0, 0, board);
    }

    bool solve(int i, int j, vector<vector<char>> &board){
        if (i == n) {
            return 1;
        }
        if (j == n) {
            return solve(i + 1, 0, board);
        }
        if (board[i][j] != '.') {
            return solve(i, j + 1, board);
        }
        for (int k = 1; k <= 9; ++k) {
            if (!h[i][k] && !v[j][k] && !b[i / 3 * 3 + j / 3][k]) {
                board[i][j] = (char) ('0' + k);
                h[i][k]=1;v[j][k]=1;
                b[i / 3 * 3 + j / 3][k] = 1;
                if (solve(i, j + 1, board)) {
                    return 1;
                }
                h[i][k]=0;v[j][k]=0;
                b[i / 3 * 3 + j / 3][k] = 0;
                board[i][j] = '.';
            }
        }
        return 0;
    }
};

int main(){
    return 0;
}