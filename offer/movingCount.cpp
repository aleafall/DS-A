//
// Created by aleafall on 17-2-23.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int **vis;
	int rows,cols;
	unordered_set<int> ust;
	int dir[4][2]{{-1, 0},
	              {1,  0},
	              {0,  1},
	              {0,  -1}};
	int movingCount(int threshold, int rows, int cols) {
		if (rows <= 0 || cols <= 0) {
			return 0;
		}
		this->rows = rows, this->cols = cols;
		vis = new int *[rows + 1];
		for (int i = 0; i < rows + 1; ++i) {
			vis[i] = new int[cols]{0};
		}
		if (isCanEnter(threshold, 0, 0)) {
			DFS(threshold, 0, 0);
		}
		for (int i = 0; i < rows + 1; ++i) {
			delete[] vis[i];
		}
		delete[] vis;
		return (int) ust.size();
	}
	void DFS(int threshold,int x,int y){
		vis[x][y] = 1;
//		cout << "tst " << x << "," << y << endl;
		ust.insert(x * cols + y);
		for (int i = 0; i < 4; ++i) {
			int newX = x + dir[i][0], newY = y + dir[i][1];
			if (isCanEnter(threshold, newX, newY)) {
				DFS(threshold, newX, newY);
//				vis[newX][newY] = 0;
			}
		}
//		vis[x][y] = 0;
	}

	bool isCanEnter(int threshold, int x, int y){
		if (x < 0 || x >= rows || y < 0 || y >= cols || vis[x][y]) {
			return 0;
		}
		auto f = [](int x) {
			int ans = 0;
			string str = to_string(x);
			for (auto &&item : str) {
				ans += item - '0';
			}
			return ans;
		};
		int now = f(x) + f(y);
		return now <= threshold;
	}
};
int main(){
	Solution solution;
	int ans = solution.movingCount(-10, 10, 10);
	cout << ans << endl;
}
