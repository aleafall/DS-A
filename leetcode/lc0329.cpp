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
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		vector<vector<int>> vis(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				Max = max(Max,DFS(i, j, matrix, 1, vis));
			}
		}
		return Max;
	}

	int DFS(int endX, int endY, vector<vector<int>> &matrix, int cnt, vector<vector<int>> &vis) {
		if (vis[endX][endY]) {
			return vis[endX][endY];
		}
		int ans = 0;
		int Y[4] = {-1, 1, 0, 0}, X[4] = {0, 0, -1, 1};
		for (int i = 0; i < 4; ++i) {
			int newX = endX + X[i], newY = endY + Y[i];
			if (newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size()) {
				if (matrix[newX][newY] > matrix[endX][endY]) {
					ans = max(ans, DFS(newX, newY, matrix, cnt + 1, vis));
				}
			}
		}
		vis[endX][endY] = ans + 1;
		return ans+1;
	}
};

int main() {
	Solution solution;
	vector<vector<int>> vi{};

	cout << solution.longestIncreasingPath(vi) << endl;
	return 0;
}
