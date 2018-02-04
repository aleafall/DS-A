//
// Created by aleafall on 17-10-8.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>> &grid) {
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}
		int ans = 0;
		int X[4]{0, 0, -1, 1};
		int Y[4]{-1, 1, 0, 0};
		queue<pair<int, int>> q;
		vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 1) {
					q.push({i, j});
					vis[i][j] = 1;
					while (!q.empty()) {
						auto now = q.front();
						q.pop();
						int cnt = 4;
						for (int k = 0; k < 4; ++k) {
							int x = now.first + X[k], y = now.second + Y[k];
							if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() &&
							    grid[x][y]) {
								cnt--;
								if (!vis[x][y]) {
									vis[x][y] = 1;
									q.push({x, y});
								}
							}
						}
						ans += cnt;
					}
					return ans;
				}
			}
		}
	}
};
