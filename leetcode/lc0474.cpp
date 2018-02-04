//
// Created by aleafall on 17-3-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (auto &&item :strs) {
			int cnt[2] = {0};
			for (auto &&c:item) {
				cnt[c - '0']++;
			}
			for (int i = m; i >= cnt[0]; --i) {
				for (int j = n; j >=cnt[1] ; --j) {
					dp[i][j] = max(dp[i][j], dp[i - cnt[0]][j - cnt[1]] + 1);
				}
			}
		}
		return dp[m][n];
	}
};

int main() {
	Solution solution;
	vector<string> vs{"0", "00", "1"};
	int m = 1, n = 0;
	cout << solution.findMaxForm(vs, m, n) << endl;
    return 0;
}
