//
// Created by aleafall on 17-9-9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	const int mod = 1000000007;
public:
	int findPaths(int m, int n, int N, int i, int j) {
		uint dp[51][50][50] = {0};
		for (int k = 1; k <= N; ++k) {
			for (int x = 0; x < m; ++x) {
				for (int y = 0; y < n; ++y) {
					dp[k][x][y] = ((x == 0 ? 1 : dp[k - 1][x - 1][y]) + (x == m - 1 ? 1 : dp[k - 1][x + 1][y]) +
					               (y == 0 ? 1 : dp[k - 1][x][y - 1]) + (y == n - 1 ? 1 : dp[k - 1][x][y + 1]))%mod;
				}
			}
		}
		return dp[N][i][j];
	}
};

int main() {
    Solution solution;
	int m = 2, n = 2, N = 2, i = 0, j = 0;
	cout << solution.findPaths(m, n, N, i, j) << endl;
    return 0;
}
