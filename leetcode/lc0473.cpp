<<<<<<< HEAD
//
// Created by aleafall on 17-9-2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	bool dfs(vector<int> &sidesLength, const vector<int> &matches, int index, int target) {
		if (index == matches.size())
			return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] &&
			       sidesLength[2] == sidesLength[3];
		for (int i = 0; i < 4; ++i) {
			if (sidesLength[i] + matches[index] > target) {
				continue;
			}
			int j = i;
			for (j--; j >= 0; --j) {
				if (sidesLength[j] == sidesLength[i]) {
					break;
				}
			}
			if (j != -1) {
				continue;
			}
			sidesLength[i] += matches[index];
			if (dfs(sidesLength, matches, index + 1, target))
				return true;
			sidesLength[i] -= matches[index];
		}
		return false;
	}

public:
	bool makesquare(vector<int> &nums) {
		if (nums.empty()) return false;
		vector<int> sidesLength(4, 0);
		int sum = 0;
		for (auto &&item :nums) {
			sum += item;
		}
		if (sum % 4) {
			return 0;
		}
		return dfs(sidesLength, nums, 0, sum / 4);
	}
};
=======
//
// Created by t-xiuyan on 9/3/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool makesquare(vector<int>& nums) {
		int sum=0,Max=0;
		for (auto &&item :nums) {
			sum += item;
			Max = max(Max, item);
		}
		int edge = sum / 4;
		if (sum % 4 || Max > edge) {
			return 0;
		}
		for (int k = 0; k < 3; ++k) {
			vector<vector<int>> dp(nums.size()+ 1, vector<int>(edge+1,0));
			for (int i = 1; i <= nums.size(); ++i) {
				for (int j = nums[i - 1]; j <= edge; ++j) {
					dp[i][j] = max(dp[i - 1][j - nums[i - 1]] + nums[i - 1], dp[i - 1][j]);
				}
			}
			if (dp[nums.size()][edge] != edge) {
				return 0;
			}
			int e = edge;
			for (int i = nums.size(); i > 0; --i) {
				if (dp[i][e] != dp[i - 1][e]) {
					e -= nums[i - 1];
					swap(nums[i - 1], nums.back());
					nums.pop_back();
				}
			}
		}
		return 1;
	}
};
>>>>>>> 758190852492f055a2a6122324716c916e0711bb
