//
// Created by aleafall on 17-9-16.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
	int X[4]{-1, 1, 0, 0};
	int Y[4]{0, 0, -1, 1};
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> ans;
		if (board.empty() || board[0].empty()) {
			return ans;
		}
		vector<vector<bool >> vis(board.size(), vector<bool>(board[0].size(), 0));
		unordered_set<string> st;
		vector<pair<int, int>> index[256];
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				index[board[i][j]].emplace_back(i, j);
			}
		}
		for (int i = 0; i < words.size(); ++i) {
			bool found = 0;
			for (int j = 0; j < index[words[i][0]].size(); ++j) {
				int x = index[words[i][0]][j].first, y = index[words[i][0]][j].second;
				vis[x][y] = 1;
				DFS(board, words[i], found, x, y, 1, vis);
				vis[x][y] = 0;
				if (found) {
					st.insert(words[i]);
					break;
				}
			}
		}
		for (auto &&item :st) {
			ans.push_back(item);
		}
		return ans;
	}

	void DFS(vector<vector<char>> &board, string &word, bool &found,int x,int y,int index,vector<vector<bool>> &vis){
		if (found) {
			return;
		}
		if (index >= word.size()) {
			found = 1;
			return;
		}
		for (int i = 0; i < 4; ++i) {
			int newX = x + X[i], newY = y + Y[i];
			if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size()&&!vis[newX][newY] &&
			    board[newX][newY] == word[index])  {
				vis[newX][newY] = 1;
				DFS(board, word, found, newX, newY, index + 1, vis);
				vis[newX][newY] = 0;
			}
		}
	}
};

int main() {
    Solution solution;
	vector<vector<char>> board{{'a', 'a'}};
	vector<string> words{"aaa"};
	auto ans = solution.findWords(board, words);
	for (auto &&item :ans) {
		cout << item << endl;
	}
    return 0;
}