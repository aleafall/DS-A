//
// Created by aleafall on 17-10-8.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool hasAlternatingBits(int n) {
		if (!n) {
			return 0;
		}
		unsigned int end = (1 << 31);
		while (!(end & n)) {
			end >>= 1;
		}
		bool pre = 1;
		int cnt = 0;
		end >>= 1;
		while (end) {
			bool now = end & n;
			if (!(pre ^ now)) {
				return 0;
			}
			cnt++;
			pre = now;
			end >>= 1;
		}
		return 1;
	}
};

int main() {
	Solution solution;
	int n = 1;
	cout << solution.hasAlternatingBits(n) << endl;
	return 0;
}
