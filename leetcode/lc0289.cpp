//
// Created by t-xiuyan on 6/17/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty() || board[0].empty()) {
			return;
		}
		int X[]{0, 0, -1, 1, -1, 1, -1, 1};
		int Y[]{-1, 1, 0, 0, 1, 1, -1, -1};
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				int liveCnt = 0;
				for (int k = 0; k < 8; ++k) {
					int newI = i + X[k], newJ = j + Y[k];
					if (newI >= 0 && newI < board.size() && newJ >= 0 && newJ < board[i].size()) {
						liveCnt += (int) (board[newI][newJ] > 0);
					}
				}
				if (board[i][j]) {
					board[i][j] = liveCnt == 2 || liveCnt == 3 ? 3 : 2;
				} else {
					if (liveCnt == 3) {
						board[i][j] = -1;
					}
				}
			}
		}
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				board[i][j] = board[i][j] == 2 || board[i][j] == 0 ? 0 : 1;
			}
		}
	}
};
