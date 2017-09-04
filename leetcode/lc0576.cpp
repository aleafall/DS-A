//
// Created by t-xiuyan on 7/22/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	long long ans;
	int X[4] = {0, 0, -1, 1};
	int Y[4] = {-1, 1, 0, 0};

	int findPaths(int m, int n, int N, int i, int j) {
		ans = 0;
		DFS(m, n, N, i, j);
		return ans % (1000000007);
	}

	void DFS(int m, int n, int N, int i, int j) {
		if (N < 0) {
			return;
		}
		if (i < 0 || i >= m || j < 0 || j >= n) {
			++ans;
			return;
		}
		for (int k = 0; k < 4; ++k) {
			int x = i + X[k], y = j + Y[k];
			DFS(m, n, N - 1, x, y);
		}
	}
};
