//
// Created by aleafall on 17-10-31.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		if (A.empty() || B.empty()) {
			return 0;
		}
		vector<vector<int>> dp(2, vector<int>(B.size() + 1, 0));
		int now = 0, ans = 0;
		for (int i = 1; i <= A.size(); ++i) {
			for (int j = 1; j <= B.size(); ++j) {
				if (A[i - 1] == B[j - 1]) {
					dp[now][j] = dp[!now][j - 1] + 1;
				} else {
					dp[now][j] = 0;
				}
				ans = max(ans, dp[now][j]);
			}
			now = !now;
		}
		return ans;
	}
};

int main() {
	vector<int> A{1,0,0,0,1,0,0,1,0,0}, B{0,1,1,1,0,1,1,1,0,0};
	Solution solution;
	cout << solution.findLength(A, B) << endl;
    return 0;
}
