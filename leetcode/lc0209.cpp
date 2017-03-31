//
// Created by aleafall on 17-2-5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int> &nums) {
		int ans = INT32_MAX;
		if (nums.empty()) {
			return ans;
		}
		int i = 0, j = 0, sum = 0;
		while (i<=j&&j < nums.size()) {
			while (j < nums.size() && sum < s) {
				sum += nums[j++];
			}
			cout << "i j " << i << " " << j << endl;
			ans = min(ans, j - i);
			sum -= nums[i++];
			/*sum += nums[j];
			if (sum < s) {
				++j;
			} else {
				cout << "i j " << i << " " << j << endl;
				cout << "sum " << sum << endl;
				ans = min(ans, j - i + 1);
				sum -= nums[i++];
			}*/
		}
		return ans;
	}
};
