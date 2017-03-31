//
// Created by aleafall on 17-3-9.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	int integerBreak(int n) {
		/*vector<int> dp(n + 1, 1);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= i + 1; ++j) {
				if (i + j <= n) {
					dp[i + j] = max(max(dp[i], i) * max(dp[j], j), dp[i + j]);
				}
			}
		}
		return dp[n];*/
		if (n <= 3) {
			return n - 1;
		}
		int mod = n % 3;
		if (mod == 0) {
			return pow(3, n / 3);
		} else if (mod == 1) {
			return 4 * pow(3, (n - 4) / 3);
		} else {
			return 2 * pow(3, n / 3);
		}
	}
};
