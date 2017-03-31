//
// Created by aleafall on 17-3-8.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> ans;
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int> temp;
		for (int i = 0; i < nums.size(); ++i) {
			DFS(nums, temp, i);
		}
		sort(ans.begin(), ans.end());
		int len = 0;
		for (int i = 1; i < ans.size(); ++i) {
			if (i == 0 || ( ans[i] != ans[i - 1])) {
				ans[len++] = ans[i];
			}
		}
		return vector<vector<int>>(ans.begin(), ans.begin() + len);
	}
	void DFS(const vector<int> &nums,vector<int> temp,int index){
		if (index >= nums.size()) {
			return;
		}
		temp.push_back(nums[index]);
		if (temp.size() > 1) {
			ans.push_back(temp);
		}
		for (int i = index+1; i < nums.size(); ++i) {
			if (nums[i] >= temp.back()) {
				DFS(nums, temp, i);
			}
		}
	}
};

int main(){
	vector<int> vi{4, 6, 7, 7};
	Solution solution;
	auto it = solution.findSubsequences(vi);
}