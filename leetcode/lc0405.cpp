//
// Created by aleafall on 17-4-30.
//

#include <iostream>

using namespace std;

class Solution {
public:
	string toHex(int num) {
		string str("0123456789abcdef"), ans;
		ans.resize(8);
		int flag = (1 << 31);
		for (int i = 0; i < 8; ++i) {
			int now = 0;
			for (int j = 0; j < 4; ++j) {
				now <<= 1;
				if (flag & num) {
					++now;
				}
				flag >>= 1;
			}
			cout << "now " << now << endl;
			ans[i] = str[now];
		}
		return ans;
	}
};

int main() {
	Solution solution;
	cout << solution.toHex(26) << endl;
	return 0;
}
