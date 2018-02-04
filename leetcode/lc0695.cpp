//
// Created by aleafall on 17-10-8.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}
		int ans = 0;
		int X[4]{0, 0, -1, 1};
		int Y[4]{-1, 1, 0, 0};
		vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));
		queue<pair<int,int>> q;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (!vis[i][j] && grid[i][j]) {
					int cnt = 0;
					q.push({i, j});
					vis[i][j] = 1;
					while (!q.empty()) {
						auto now = q.front();
						q.pop();
						cnt++;
						for (int k = 0; k < 4; ++k) {
							int x = now.first + X[k], y = now.second + Y[k];
							if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !vis[x][y] && grid[x][y]) {
								vis[x][y] = 1;
								q.push({x, y});
							}
						}
					}
					ans = max(ans, cnt);
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution solution;
	vector<vector<int>> vi{{1, 1, 0, 0, 0},
	                       {1, 1, 0, 0, 0},
	                       {0, 0, 0, 1, 1},
	                       {0, 0, 0, 1, 1}};
	cout << solution.maxAreaOfIsland(vi) << endl;
    return 0;
}