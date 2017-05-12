//
// Created by aleafall on 17-5-9.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int ans = 0;
		if (n <= 0) {
			return 0;
		}
		while (n) {
			ans += n / 5;
			n /= 5;
		}
		return ans;
	}
};
