//
// Created by aleafall on 17-2-16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int ans = INT32_MIN;
		if (array.empty()) {
			return 0;
		}
		int *dp = new int[array.size() + 1];
		for (int i = 0; i < array.size(); ++i) {
			if (i) {
				dp[i] = max(dp[i - 1] + array[i], array[i]);
			} else {
				dp[i] = array[i];
			}
			ans = max(ans, dp[i]);
		}
		delete dp;
		return ans;
	}
};
int main(){
	Solution solution;
	vector<int> vi{6,-3,-2,7,-15,1,2,2};
	cout << solution.FindGreatestSumOfSubArray(vi) << endl;
	return 0;
}
