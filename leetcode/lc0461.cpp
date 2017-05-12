//
// Created by aleafall on 17-4-29.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int ans = 0;
		x ^= y;
		while (x) {
			x &= (x - 1);
			++ans;
		}
		return ans;
	}
};
