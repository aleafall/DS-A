//
// Created by aleafall on 17-10-16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool canPartitionKSubsets(vector<int> &nums, int k) {
		if (k <= 0) {
			return 0;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % k) {
			return 0;
		}
		sort(nums.begin(), nums.end());
		int cnt = 0;
		vector<bool> used(nums.size(), 0);
		DFS(0, sum / k, used, nums, k - 1, cnt, 0);
		cout << "cnt " << cnt << endl;
		return cnt >= k - 1;
	}

	void DFS(int index,int target,vector<bool> &used, vector<int> &nums,int k, int &cnt,int sum) {
		if (sum >= target) {
			if (sum == target) {
				++cnt;
			}
			return;
		}
		if (cnt >= k) {
			return;
		}
		for (int i = 0; i < k; ++i) {
			for (int j = index; j < nums.size(); ++j) {
				if (nums[j] + sum > target) {
					break;
				}
				if (!used[j]) {
					used[j] = 1;
					DFS(index + 1, target, used, nums, k, cnt, sum + nums[j]);
					used[j] = 0;
				}
			}
		}
	}
};

int main() {
	Solution solution;
	vector<int> vi{2, 2, 2, 2, 3, 4, 5};
	int k = 4;
	cout << solution.canPartitionKSubsets(vi, k) << endl;
    return 0;
}