//
// Created by aleafall on 17-10-2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty()) {
			return 0;
		}
		const int mod = 1000000007;
		long long pre = 1, ans = cal(s.substr(0, 1));
		for (int i = 1; i < s.size(); ++i) {
			long long now = ans * cal(s.substr(i, 1)) + pre * cal(s.substr(i - 1, 2));
			pre = ans;
			ans = static_cast<int>(now % mod);
		}
		return static_cast<int>(ans);
	}

	int cal(string &&s) {
		if (s.size() == 1) {
			if (s == "*") {
				return 9;
			}
			return s == "0" ? 0 : 1;
		}
		if (s == "**") {
			return 15;
		} else if (s[0] == '*') {
			return s[1] <= '6' ? 2 : 1;
		} else if (s[1] == '*') {
			if (s[0] == '1') {
				return 9;
			} else if (s[0] == '2') {
				return 6;
			}
			return 0;
		} else {
			return s >= "10" && s <= "26" ? 1 : 0;
		}
	}
};

int main() {
	Solution solution;
	string s = "********************";
	cout << solution.numDecodings(s) << endl;
	return 0;
}
