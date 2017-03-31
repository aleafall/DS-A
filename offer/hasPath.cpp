//
// Created by aleafall on 17-2-23.
//

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
	bool **vis;
	int X[4]{0, 0, -1, 1}, Y[4]{-1, 1, 0, 0};

	bool hasPath(char *matrix, int rows, int cols, char *str) {
		if (!matrix || rows <= 0 || cols <= 0 || !str) {
			return 0;
		}
		int len = strlen(str);
		bool flag = 0;
		vis = new bool *[rows + 1];
		for (int i = 0; i < rows + 1; ++i) {
			vis[i] = new bool[cols + 1]{0};
		}
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (!flag) {
					DFS(rows, cols, i, j, 0, len, matrix, str, flag);
				}
			}
		}
		for (int i = 0; i < rows + 1; ++i) {
			delete[] vis[i];
		}
		delete[] vis;
		return flag;
	}

	void DFS(int rows,int cols,int x, int y, int step, int len, char *matrix, char *str, bool &flag) {
		if (x < 0 || x >= rows || y < 0 || y >= cols || vis[x][y] || flag || matrix[x * cols + y] != str[step]) {
			return;
		}
		if (step == len - 1) {
			flag = 1;
			return;
		}
		vis[x][y] = 1;
		for (int i = 0; i < 4; ++i) {
			int newX = x + X[i], newY = y + Y[i];
			DFS(rows, cols, newX, newY, step + 1, len, matrix, str, flag);
		}
		vis[x][y] = 0;
	}

};

int main(){
	Solution solution;
	char *matrix = (char *) "abcesfcsadee";
	int rows = 3, cols = 4;
	char *str = (char *) "abcd";
	cout << solution.hasPath(matrix, rows, cols, str) << endl;
	return 0;
}
