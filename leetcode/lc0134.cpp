//
// Created by aleafall on 17-9-17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int ans = 0, sum = 0;
		int left = 0, right = gas.size() - 1;
		for (; left <= right; ++left) {
			sum += gas[left] - cost[left];
			while (sum < 0 && right >= left) {
				sum += gas[right] - cost[right];
				ans = right--;
			}
			if (sum < 0) {
				break;
			}
		}
		return sum < 0 ? -1 : ans;
	}
};
