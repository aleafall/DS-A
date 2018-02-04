//
// Created by aleafall on 17-9-12.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int ans = 0;
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]; ++j) {
				ans++;
			}
			for (int j = 1; i - j + 1 >= 0 && i + j < s.size() && s[i - j + 1] == s[i + j]; ++j) {
				ans++;
			}
		}
		return ans;
	}
};
