//
// Created by aleafall on 16-10-18.
//
//todo
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
	    if (x == 0) {
		    return n == 0 ? 1 : 0;
	    }
	    if (n == 0) {
		    return 1;
	    }
	    long long exp = abs((long long) n);
	    double ans = f(x, exp);
	    return n < 0 ? 1.0 / ans : ans;
    }
	double f(double x,long long exp){
		if (exp == 0) {
			return 1;
		}
		double half = f(x, exp / 2);
		return exp & 1 ? x * half * half : half * half;
	}
};

int main() {
    Solution *solution = new Solution;
    double x = 0.00001;
    int n = 2147483647;
    cout << solution->myPow(x, n) << endl;
    delete solution;
    return 0;
}
