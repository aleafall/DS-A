//
// Created by aleafall on 17-3-11.
//

#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		string ans;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				ans += s[i] - 'A' + 'a';
			} else if ((s[i] >= 'a' && s[i] <= 'z')||(s[i]>='0'&&s[i]<='9')) {
				ans += s[i];
			}
		}
		for (int i = 0; i < ans.size()/2; ++i) {
			if (ans[i] != ans[ans.size() - i - 1]) {
				return 0;
			}
		}
		return 1;
	}
};
