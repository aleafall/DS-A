//
// Created by aleafall on 17-3-30.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		int ans = 0;
		if (n > 10) {
			n = 10;
		}
		for (int i = n; i > 0; --i) {
			int now = 1;
			for (int j = i; j > 0; --j) {
				if (j == i) {
					now *= 9;
				} else {
					now *= (10 + j - i);
				}
			}
			ans += now;
		}
		return ans + 1;
	}
};

int main() {
	Solution solution;
	cout << solution.countNumbersWithUniqueDigits(0) << endl;
}