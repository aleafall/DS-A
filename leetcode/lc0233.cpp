//
// Created by aleafall on 17-3-9.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		if (n <= 0) {
			return 0;
		}
		long x = 1, now, left, right, ans = 0;
		while (n / x) {
			now = n / x % 10;
			left = n / x / 10;
			right = n % x;
			if (now < 1) {
				ans += left * x;
			} else if (now == 1) {
				ans += left * x + right + 1;
			} else {
				ans += (left + 1) * x;
			}
			x *= 10;
		}
		return ans;
	}
};
