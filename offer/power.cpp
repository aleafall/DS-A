//
// Created by aleafall on 17-2-26.
//

#include <iostream>

using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		double ans = 1.0;
		bool flag = 0;
		if (exponent == 0) {
			return 1.0;
		} else if (exponent < 0) {
			flag = 1;
		}
		for (int i = 0; i < abs(exponent); ++i) {
			ans *= base;
		}
		return flag ? 1.0 / ans : ans;
	}
};
