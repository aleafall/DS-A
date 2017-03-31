//
// Created by aleafall on 17-2-16.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n) {
		int x = 1, left, right, ans = 0;
		while (n / x) {
			int now = n / x % 10;
			left = n / x / 10;
			right = n % x;
			if (now < 1) {
				ans += left * x;
			} else if (now > 1) {
				ans += (left + 1) * x;
			} else {
				ans += left * x + right + 1;
			}
			x *= 10;
		}
		return ans;
	}
};
