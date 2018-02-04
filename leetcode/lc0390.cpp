//
// Created by aleafall on 17-9-28.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int lastRemaining(int n) {
		int remaining = n;
		int head = 1, step = 1;
		bool left = 1;
		while (remaining > 1) {
			if (left || (remaining & 1)) {
				head += step;
			}
			remaining >>= 1;
			step <<= 1;
			left = !left;
		}
		return head;
	}
};

int main() {
	Solution solution;
	for (int i = 1; i <=50 ; ++i) {
		cout << solution.lastRemaining(i) << endl;
	}
    return 0;
}
