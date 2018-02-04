//
// Created by aleafall on 17-5-29.
//

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
	vector<vector<int>> dp;
public:
	NumMatrix(vector<vector<int>> matrix) {
		size_t col = matrix.empty() ? 0 : matrix[0].size();
		dp = vector<vector<int>>(matrix.size() + 1, vector<int>(col + 1, 0));
		for (int i = 1; i <= matrix.size(); ++i) {
			for (int j = 1; j <= matrix[0].size(); ++j) {
				dp[i][j] = matrix[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return dp[row2 + 1][col2 + 1] - dp[row2 + 1][col1] - dp[row1][col2 + 1] + dp[row1][col1];
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */


int main() {
	vector<vector<int>> vi{{3, 0, 1, 4, 2},
	                       {5, 6, 3, 2, 1},
	                       {1, 2, 0, 1, 5},
	                       {4, 1, 0, 1, 7},
	                       {1, 0, 3, 0, 5}};
	vector<vector<int>> vs{{-4,-5}};
	NumMatrix numMatrix(vs);
	int row1 = 0, col1 = 0, row2 = 0, col2 = 1;
	cout << numMatrix.sumRegion(row1, col1, row2, col2) << endl;
	return 0;
}
