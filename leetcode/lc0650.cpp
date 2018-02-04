//
// Created by aleafall on 17-9-12.
//

#include<iostream>
#include <cmath>

using namespace std;

class Solution {
	bool isPrime(int n){
		if (n <= 1) {
			return 0;
		}
		int sqr = (int) sqrt(1.0 * n);
		for (int i = 2; i <= sqr; ++i) {
			if (n % i == 0) {
				return 0;
			}
		}
		return 1;
	}
public:
	int minSteps(int n) {
		if (n == 1) {
			return 0;
		}
		if (isPrime(n)) {
			return n;
		}
		int ans = 0;
		auto sqr = (int) sqrt(1.0 * n);
		for (int i = 2; i <= sqr; ++i) {
			if (n % i == 0) {
				ans += minSteps(i);
				n /= i;
			}
		}
		ans += minSteps(n);
		return ans;
	}
};
