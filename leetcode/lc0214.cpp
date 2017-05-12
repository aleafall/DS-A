//
// Created by aleafall on 17-4-10.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	string shortestPalindrome(string s) {
		/*string ans;
		if (s.empty()) {
			return ans;
		}
		int last = s.size();
		while (last > 1) {
			if (check(s, last)) {
				break;
			}
			--last;
		}
		ans = s.substr(last , s.size() - last);
		reverse(ans.begin(), ans.end());
		return ans + s;*/
		if (s.empty()) {
			return "";
		}
		int j = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] == s[j]) {
				++j;
			}
		}
		if (j >= s.size()) {
			return s;
		}
		string ans = s.substr(j, s.size()-j);
		string pre = ans;
		reverse(pre.begin(), pre.end());
		return pre + shortestPalindrome(s.substr(0,j))+ans;
	}

	bool check(const string &str, int last) {
		for (int i = 0; i < last / 2; ++i) {
			if (str[i] != str[last - i - 1]) {
				return 0;
			}
		}
		return 1;
	}
};
