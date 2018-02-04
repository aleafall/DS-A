//
// Created by aleafall on 17-5-30.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		unordered_map<int, int> mp;
		vector<int> ans;
		int cnt=0,index= -1;
		vector<int> dp(nums.size(), 1);
		for (int i = 0; i < nums.size(); ++i) {
			mp[i] = -1;
			for (int j = 0; j < i; ++j) {
				if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					mp[i] = j;
				}
			}
			if (cnt < dp[i]) {
				cnt = dp[i];
				index = i;
			}
		}
		while (index != -1) {
			ans.push_back(nums[index]);
			index = mp[index];
		}
		return ans;
	}
};

int main() {
	vector<int> vi{};
	Solution solution;
	auto ans = solution.largestDivisibleSubset(vi);
	for (auto &&item :ans) {
		cout << item << endl;
	}
    return 0;
}