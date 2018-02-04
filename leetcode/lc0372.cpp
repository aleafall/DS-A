//
// Created by aleafall on 17-5-30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int superPow(int a, vector<int>& b) {
		if (b.empty()) {
			return 1;
		}
		int last = b.back();
		b.pop_back();
		return Pow(superPow(a, b), 10) * Pow(a, last) % 1337;
	}
	int Pow(int a,int k){
		int base = 1337;
		a %= base;
		int ans = 1;
		for (int i = 0; i < k; ++i) {
			ans = (ans * a) % base;
		}
		return ans;
	}
};
