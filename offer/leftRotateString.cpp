//
// Created by aleafall on 17-2-16.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (str.empty()) {
			return str;
		}
		n %= str.size();
		reverse(str.begin(), str.begin() + n);
		reverse(str.begin() + n, str.end());
		reverse(str.begin(), str.end());
		return str;
	}
};
