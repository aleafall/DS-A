//
// Created by aleafall on 17-4-29.
//

//use log or get the max of 3^n int the range of int
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		return fmod(log10(n)/log10(3),1)==0;
	}
};
