//
// Created by t-xiuyan on 6/24/2017.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * just look at Single Number II.
 *
 * */

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int hold1 = INT32_MIN, hold2 = INT32_MIN, release1 = 0, release2 = 0;
		for (auto &&item :prices) {
			release2 = max(release2, hold2 + item);
			hold2 = max(hold2, release1 - item);
			release1 = max(release1, hold1 + item);
			hold1 = max(hold1, -item);
		}
		return release2;
	}
};

