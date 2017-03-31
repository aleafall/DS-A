//
// Created by aleafall on 17-3-8.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int Max;

	int longestIncreasingPath(vector<vector<int>> &matrix) {
		Max = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				vector<pair<int, int>> vi;
				vi.push_back(make_pair(i, j));
				DFS(vi, matrix);
			}
		}
		return Max;
	}

	void DFS(vector<pair<int, int>> temp, vector<vector<int>> &matrix) {
		if (temp.size() > Max) {
			int begX = temp.front().first, begY = temp.front().second, endX = temp.back().first, endY = temp.back().second;
			if (temp.size() <= 2 || abs(begX - endX) + abs(begY - endY) > 1) {
				Max = (int) temp.size();
			}
		}
		int Y[4] = {-1, 1, 0, 0}, X[4] = {0, 0, -1, 1};
		for (int i = 0; i < 4; ++i) {
			int endX = temp.back().first, endY = temp.back().second;
			int newX = endX + X[i], newY = endY + Y[i];
			if (newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size()) {
				if (matrix[newX][newY] > matrix[endX][endY]) {
					temp.push_back(make_pair(newX, newY));
					DFS(temp, matrix);
				}
			}
		}
	}
};

