//
// Created by aleafall on 16-11-5.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<bool >> vis;
	int X[4]{0, 0, -1, 1}, Y[4]{-1, 1, 0, 0};

	bool exist(vector <vector<char>> &board, string word) {
		if (board.empty() || board[0].empty() || word.empty()) {
			return 0;
		}
		vis = vector < vector < bool >> (board.size(), vector < bool > (board[0].size(), 0));
		bool flag = 0;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == word[0]) {
					vis[i][j] = 1;
					DFS(board, word, i, j, 1, flag);
					vis[i][j] = 0;
					if (flag) {
						return 1;
					}
				}
			}
		}
		return flag;
	}

	void DFS(vector <vector<char>> &board, const string &word, int nowX, int nowY, int index, bool &flag) {
		if (flag) {
			return;
		}
		if (index >= word.size()) {
			flag = 1;
			return;
		}
		for (int i = 0; i < 4; ++i) {
			int newX = nowX + X[i], newY = nowY + Y[i];
			if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() &&
			    vis[newX][newY] == 0 && board[newX][newY] == word[index]) {
				vis[newX][newY] = 1;
				DFS(board, word, newX, newY, index + 1, flag);
				vis[newX][newY] = 0;
			}
		}
	}
};