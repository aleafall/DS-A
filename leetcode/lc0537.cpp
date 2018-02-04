//
// Created by aleafall on 17-9-27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		string ans;
		int first[2], second[2];
		int index = 0;
		while (index < a.size() && a[index] != '+') {
			++index;
		}
		first[0] = stoi(a.substr(0, index));
		first[1] = stoi(a.substr(index + 1, a.size() - index - 2));
		index = 0;
		while (index < b.size() && b[index] != '+') {
			++index;
		}
		second[0] = stoi(b.substr(0, index));
		second[1] = stoi(b.substr(index + 1, b.size() - index - 2));
		ans = to_string(first[0] * second[0] - first[1] * second[1]) + "+" +
		      to_string(first[0] * second[1] + first[1] * second[0]) + "i";
		return ans;
	}
};
