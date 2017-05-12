//
// Created by aleafall on 17-2-6.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
/*	int maxSubArray(vector<int>& nums) {
		int ans = nums[0];
		int a[nums.size() + 1] = {0};
		for (int i = 1; i <=nums.size(); ++i) {
			if (i) {
				a[i] = max(nums[i - 1], a[i - 1] + nums[i - 1]);
			} else {
				a[i] = nums[i - 1];
			}
			ans = max(ans, a[i]);
		}
		return ans;*/
//	}
	int maxSubArray(vector<int>& nums) {
		int ans = INT32_MIN, pre = INT32_MIN;
		for(auto item:nums){
			pre=(int)max((long long)item,(long long)item+pre);
			ans=max(ans,pre);
		}
		return ans;
	}
};

int main(){
	Solution solution;
	vector<int> vi{-2147483648};
	cout << solution.maxSubArray(vi) << endl;
}