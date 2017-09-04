//
// Created by t-xiuyan on 7/8/2017.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	bool judgeSquareSum(int c) {
		int sqr = (int) sqrt(1.0 * c);
		for (int i = sqr; i > sqr / 2; --i) {
			int j = (int) sqrt(1.0 * c - i * i);
			if (j * j + i * i == c) {
				return 1;
			}
		}
		return 0;
	}
};
