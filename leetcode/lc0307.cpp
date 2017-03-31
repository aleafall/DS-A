//
// Created by aleafall on 17-2-6.
//

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	vector<int> nums, bit;

	int lowbit(int x){
		return x & (-x);
	}
	NumArray(vector<int> nums) {
		this->nums = nums;
		bit = vector<int>(nums.size() + 1, 0);
		for (int i = 1; i < bit.size(); ++i) {
			for (int j = i; j > i - lowbit(i); --j) {
				bit[i] += nums[j - 1];
			}
		}
	}

	void update(int i, int val) {
		int delta = val - nums[i];
		nums[i] = val;
		for (int j = i + 1; j < bit.size(); j += lowbit(j)) {
			bit[j] += delta;
		}
	}

	int sumRange(int i, int j) {
		int ans1 = 0, ans2 = 0;
		for (int k = j+1; k>0; k-=lowbit(k)) {
			ans1 += bit[k];
		}
		for (int k = i; k > 0; k -= lowbit(k)) {
			ans2 += bit[k];
		}
		return ans1 - ans2;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
