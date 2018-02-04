//
// Created by aleafall on 17-5-30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		sort(nums.begin(), nums.end());
		long long ans = INT32_MAX;
		long long sum[nums.size()] = {0};
//		long long tt = accumulate(nums.begin(), nums.end(), 0);
		for (int i = 0; i < nums.size(); ++i) {
			if (i) {
				sum[i] = nums[i] + sum[i - 1];
			} else {
				sum[i] = nums[i];
			}
		}
		long long int now = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (i == 0) {
				now = sum[nums.size() - 1] - (long long)nums[i] * (long long)nums.size();
			} else if (i != nums.size() - 1) {
				now = (long long) nums[i] * i - sum[i - 1] + sum[nums.size() - 1] - sum[i] -
				      (long long) (nums.size() - 1 - i) * nums[i];
			} else {
				now = (long long) nums[i] * i - sum[i - 1];
			}
//			if (now < 0) {
//				cout << "wrong i now " << i << " " << now << endl;
//			}
//			cout << "now " << now << endl;
			ans = min(ans, abs(now));
		}
		return ans;
	}
};


int main() {
	Solution solution;
	vector<int> num{203125577,-349566234,230332704,48321315,66379082,386516853,50986744,-250908656,-425653504,-212123143};
	cout << solution.minMoves2(num) << endl;
    return 0;
}