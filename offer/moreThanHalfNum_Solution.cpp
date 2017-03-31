//
// Created by aleafall on 17-2-26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty()) {
			return 0;
		}
		int now = *numbers.begin(), cnt = 1;
		for (int i = 1; i < numbers.size(); ++i) {
			numbers[i] == now ? ++cnt : --cnt;
			if (cnt <= 0) {
				now = numbers[i];
			}
		}
		cnt = 0;
		for (int i = 0; i < numbers.size(); ++i) {
			if (numbers[i] == now) {
				++cnt;
			}
		}
		return cnt * 2 > numbers.size() ? now : 0;
	}
};
