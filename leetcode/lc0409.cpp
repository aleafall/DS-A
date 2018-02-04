//
// Created by aleafall on 17-9-22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		int cnt[256] = {0};
		for (auto &&item :s) {
			cnt[item]++;
		}
		int one = 0, ans = 0;
		for (int i = 0; i < 256; ++i) {
			if (cnt[i] & 1) {
				one = 1;
			}
			ans += cnt[i] / 2 * 2;
		}
		return ans + one;
	}
};
