//
// Created by aleafall on 17-4-20.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int ans = 0;
		for (int i = 0; i < s.size(); ++i) {
			ans = ans * 26 + s[i] - 'A' + 1;
		}
		return ans;
	}
};

int main() {
	string str = "RFU";
	Solution solution;
	cout << solution.titleToNumber(str) << endl;
	return 0;
}
