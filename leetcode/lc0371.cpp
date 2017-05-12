//
// Created by aleafall on 17-4-29.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
	}
};
