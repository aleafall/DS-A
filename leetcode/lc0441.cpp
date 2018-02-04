//
// Created by aleafall on 17-5-31.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	int arrangeCoins(int n) {
		return  ((int) sqrt(1.0 + 8.0 * n) - 1) / 2;
	}
};
