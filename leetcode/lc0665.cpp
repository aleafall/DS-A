//
// Created by t-xiuyan on 8/29/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int cnt=0;
		for (int i = 0; i < (int) nums.size() - 1; ++i) {
			if (nums[i] > nums[i + 1] ) {
				if (i) {
					if (nums[i - 1] <= nums[i + 1]) {
						++cnt;
					} else {
						return 0;
					}
				} else if (){

				}
			}
		}
		return 1;
	}
};
