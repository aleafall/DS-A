//
// Created by aleafall on 17-2-6.
//

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		for (int i = 0; i < nums.size(); ++i) {
			if (i) {
				tempSum.push_back(tempSum[i - 1] + nums[i]);
			} else {
				tempSum.push_back(nums[i]);
			}
		}

	}

	vector<int> tempSum;
	int sumRange(int i, int j) {
		if (i) {
			return tempSum[j] - tempSum[i - 1];
		} else {
			return tempSum[j];
		}
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
