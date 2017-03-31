//
// Created by aleafall on 17-2-7.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		string ans;
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		int carry = 0;
		for (int i = 0; i < max(num1.size(), num2.size()); ++i) {
			int now = 0;
			if (i < min(num1.size(), num2.size())) {
				now = (num1[i] + num2[i] - '0' - '0' + carry) % 10;
				carry= (num1[i] + num2[i] - '0' - '0' + carry) / 10;
			} else if (i < num1.size()) {
				now = (num1[i] - '0' + carry) % 10;
				carry= (num1[i]  - '0' + carry) / 10;
			} else {
				now = (num2[i] - '0' + carry) % 10;
				carry= (num2[i]  - '0' + carry) / 10;
			}
			ans += to_string(now);
		}
		if (carry) {
			ans += to_string(carry);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
