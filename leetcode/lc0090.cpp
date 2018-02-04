//
// Created by aleafall on 16-10-16.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		vector<int> vi;
		DFS(ans, nums, vi, 0);
		return ans;
	}

	void DFS(vector<vector<int>> &ans, vector<int> &nums, vector<int> &vi, int index) {
		ans.push_back(vi);
		for (int i = index; i < nums.size(); ++i) {
			if (i == index || nums[i] != nums[i - 1]) {
				vi.push_back(nums[i]);
				DFS(ans, nums, vi, i + 1);
				vi.pop_back();
			}
		}
	}
};

int main() {
	vector<vector<int>> ans;
//	vector<int> nums{4, 4, 4, 1, 4};
	vector<int> nums{1, 2, 2};
	Solution *solution = new Solution;
	ans = solution->subsetsWithDup(nums);
	delete solution;
	cout << "ans.size() " << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
};