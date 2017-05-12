//
// Created by aleafall on 17-5-6.
//

#include <iostream>

using namespace std;

class Solution {
public:
	bool checkRecord(string s) {
		int a = 0, l = 0;
		for (auto &&item :s) {
			if (item == 'A') {
				++a, l = 0;
				if (a > 1) {
					return 0;
				}
			} else if (item == 'L') {
				++l;
				if (l > 2) {
					return 0;
				}
			} else {
				l = 0;
			}
		}
		return 1;
	}
};
