//
// Created by aleafall on 17-5-6.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> ans;
		if (num > 8) {
			return ans;
		}
		for (int i = 0; i <= num && i < 4; ++i) {
			vector<int> vi;
			findNum(0, 3, i, 0, vi);
			for (int j = 0; j <= num - i && j < 6; ++j) {

			}
		}
	}

	void findNum(int index, int end, int cnt, int ret, vector<int> &vi) {
		if (cnt <= 0) {
			return;
		}
		for (int i = index; i <= end && i <= cnt; ++i) {
			if (index == cnt) {
				vi.push_back(ret + (1 << index));
				return;
			}
			findNum(i + 1, end, cnt - 1, ret + (1 << index), vi);
		}
	}
};
