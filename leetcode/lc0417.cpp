//
// Created by aleafall on 17-9-9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int X[4]{0, 0, -1, 1};
	int Y[4]{-1, 1, 0, 0};
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int,int>> ans;
		if (matrix.empty() || matrix[0].empty()) {
			return ans;
		}
		vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
		dp.front().front() = 1;
		dp.back().back() = 2;
		int xxx = 3;
		cout << "test " << (xxx & 1) << endl;
		for (int times = 0; times < 2; ++times) {
			for (int i = times?matrix.size()-1:0;times?i>=0: i < matrix.size(); times?--i: ++i) {
				for (int j = times ? matrix[0].size() - 1 : 0; times ? j >= 0 : j < matrix[0].size(); times ? --j
						                                                                                            : ++j) {
					for (int k = 0; k < 4; ++k) {
						int newX = i + X[k], newY = j + Y[k];
						if (newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size()&&matrix[newX][newY]<=matrix[i][j]) {
							int t1 = dp[i][j] & 1, t2 = dp[i][j] & 2, n1 = dp[newX][newY] & 1, n2 = dp[newX][newY] & 2;
							dp[i][j] = max(t1, n1) + max(t2, n2);
						}
					}
				}
			}
		}
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				cout << "i j " << i << " " << j << " " << dp[i][j] << endl;
				if (dp[i][j] == 3) {
					ans.emplace_back(i,j);
				}
			}
		}
		return ans;
	}
};

int main() {
    Solution solution;
	vector<vector<int>> vi{{1, 2, 2, 3, 5},
	                       {3, 2, 3, 4, 4},
	                       {2, 4, 5, 3, 1},
	                       {6, 7, 1, 4, 5},
	                       {5, 1, 1, 2, 4}};
	solution.pacificAtlantic(vi);
    return 0;
}
