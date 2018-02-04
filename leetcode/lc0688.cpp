//
// Created by aleafall on 17-10-1.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int X[8]{-2, -2, -1, 1, 2, 2, 1, -1}, Y[8]{-1, 1, 2, 2, 1, -1, -2, -2};
	int N, K;

	double DFS(int x, int y, int steps, vector<vector<double>> &vis) {
		if (vis[x][y] != 0) {
			return vis[x][y];
		}
		if (steps == K) {
			vis[x][y]++;
			return vis[x][y];
		}
		for (int i = 0; i < 8; ++i) {
			int newX = X[i] + x, newY = Y[i] + y;
			if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
				vis[x][y] += DFS(newX, newY, steps + 1, vis);
			}
		}
		return vis[x][y];
	}

public:
	double knightProbability(int N, int K, int r, int c) {
		vector<vector<double>> dp(N, vector<double>(N, 1));
		for (int k = 0; k < K; ++k) {
			vector<vector<double >> now(N, vector<double>(N, 0));
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					for (int l = 0; l < 8; ++l) {
						int newX = i + X[l], newY = j + Y[l];
						if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
							now[i][j] += dp[newX][newY];
						}
					}
				}
			}
			dp = now;
		}
		for (int i = 0; i < K; ++i) {
			dp[r][c] /= (1 << 3);
		}
		return dp[r][c];
	}
};

int main() {
	Solution solution;
	int N = 8, K = 30, r = 6, c = 4;
	cout << solution.knightProbability(N, K, r, c) << endl;
	return 0;
}