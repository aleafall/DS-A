//
// Created by aleafall on 17-12-12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	vector<int> d;
	vector<bool> vis;
	vector<vector<int>> g;

	void Dijkstra(int st, int N) {
		d[st] = 0;
		for (int i = 1; i <= N; ++i) {
			int u = -1, inf = 0x3fffffff;
			for (int j = 1; j <= N; ++j) {
				if (!vis[j] && d[j] < inf) {
					u = j;
					inf = d[j];
				}
			}
			if (u == -1) {
				return;
			}
			vis[u] = 1;
			for (int v = 1; v <= N; ++v) {
				if (g[u][v] != 0x3fffffff && d[u] + g[u][v] < d[v]) {
					d[v] = d[u] + g[u][v];
				}
			}
		}
	}

public:

	int networkDelayTime(vector<vector<int>> &times, int N, int K) {
		d = vector<int>(N + 1, 0x3fffffff);
		vis = vector<bool>(N + 1, 0);
		g = vector<vector<int>>(N + 1, vector<int>(N + 1, 0x3fffffff));
		for (int i = 0; i < times.size(); ++i) {
			g[times[i][0]][times[i][1]] = times[i][2];
		}
		Dijkstra(K, N);
		int ans = *max_element(d.begin() + 1, d.end());
		return ans != 0x3fffffff ? ans : -1;
	}
};

int main() {
	Solution solution;
	vector<vector<int>> times{{2, 1, 1},
	                          {2, 3, 1},
	                          {3, 4, 1}};
	int N = 4, K = 2;
	cout << solution.networkDelayTime(times, N, K) << endl;
	return 0;
}