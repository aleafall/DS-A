//
// Created by aleafall on 17-3-6.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int ans;
	int findTargetSumWays(vector<int>& nums, int S) {
		ans = 0;
		DFS(0, nums, 0, S);
		return ans;
	}
	void DFS(int tempSum,const vector<int> &nums,int index,int S){
		if (index >= nums.size()) {
			if (tempSum == S) {
				++ans;
			}
			return;
		}
		int temp=tempSum;
		tempSum += nums[index];
		DFS(tempSum, nums, index + 1, S);
		temp -= nums[index];
		DFS(temp, nums, index + 1, S);
	}
};
