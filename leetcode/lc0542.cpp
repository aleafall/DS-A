//
// Created by t-xiuyan on 9/1/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int X[4]{0, 0, -1, 1}, Y[4]{-1, 1, 0, 0};
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(),0))
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				ans[i][j] = findZero(i, j, -1, -1, matrix);
			}
		}
		return ans;
	}

	int findZero(int i, int j, int preI, int preJ, vector<vector<int>> &matrix) {
		if (matrix[i][j] == 0) {
			return 0;
		}
		int Min=0x3fffffff;
		for (int k = 0; k < 4; ++k) {
			int newI = i + X[k], newJ = j + Y[k];
			if (newI >= 0 && newI < matrix.size() && newJ >= 0 && newJ < matrix[0].size() &&
			    !(newI == preI && newJ == preJ)) {
				Min = min(Min, findZero(newI, newJ, i, j, matrix));
			}
		}
		return Min+1;
	}
};

int main() {
	vector<vector<int>> matrix{{0, 1, 1},
	                           {1, 1, 1},
	                           {1, 1, 1}};
	Solution solution;
	auto ans = solution.updateMatrix(matrix);
	cout << "end" << endl;
    return 0;
}