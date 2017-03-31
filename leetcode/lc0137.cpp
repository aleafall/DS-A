//
// Created by aleafall on 17-3-6.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0, xthree = 0;
		for (int i = 0; i < nums.size(); ++i) {
			twos |= (ones & nums[i]);
			ones ^= nums[i];
			xthree = ~(ones & twos);
			ones &= xthree;
			twos &= xthree;
		}
		return ones;
	}
};
