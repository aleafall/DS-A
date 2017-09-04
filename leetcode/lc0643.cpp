//
// Created by t-xiuyan on 7/22/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int> &nums, int k) {
		double max_value = -9 * 1e8;
		double sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			if (i + 1 >= k) {
				if (i + 1 > k) {
					sum -= nums[i - k];
				}
				max_value = max(max_value, sum);
			}
		}
		return max_value / k;
	}
};
