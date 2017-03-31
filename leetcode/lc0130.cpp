//
// Created by aleafall on 16-11-17.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        for (size_t i = 0; i <board[0].size() ; ++i) {
            check(board, 0, (int) i);
            check(board, (int)board.size() - 1, (int) i);
        }
        for (size_t i = 0; i <board.size() ; ++i) {
            check(board, i, 0);
            check(board, i, (int) board[0].size() - 1);
        }
        for (size_t i = 0; i <board.size() ; ++i) {
            for (size_t j = 0; j <board[0].size() ; ++j) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void check(vector<vector<char>> &board,int i,int j){
        if (board[i][j] != 'O') {
            return;
        }
        board[i][j] = '#';
        int X[4] = {0, 0, -1, 1};
        int Y[4] = {-1, 1, 0, 0};
        struct Node {
            int x, y;
        } node;
        node.x = i, node.y = j;
        queue<Node> q;
        q.push(node);
        while (!q.empty()) {
            Node root = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int newX = root.x + X[k];
                int newY = root.y + Y[k];
                if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size()) {
                    if (board[newX][newY] == 'O') {
                        board[newX][newY] = '#';
                        node.x=newX,node.y =newY;
                        q.push(node);
                    }
                }
            }
        }
    }
};

int main(){
    Solution solution;
    vector<vector<char>> board{{"XXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXOOOXXXXXXXX", "XXXXXOOOXOXOXXXXXXXX", "XXXXXOXOXOXOOOXXXXXX", "XXXXXOXOOOXXXXXXXXXX", "XXXXXOXXXXXXXXXXXXXX"}};
    solution.solve(board);
    return 0;
};