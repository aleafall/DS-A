//
// Created by aleafall on 17-3-14.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1,INT32_MAX);
		for (int i = 0; i * i <= n; ++i) {
			dp[i * i] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; i + j * j <= n; ++j) {
				dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
			}
		}
		return dp[n];
	}
};

int main(){
	Solution solution;
//	cout << solution.numSquares(13) << endl;
	for (int i = 1; i < 10; ++i) {
		cout << (i & 7) << endl;
	}
}
