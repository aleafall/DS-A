//
// Created by aleafall on 17-2-10.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		int cnt = (1 << n);
		vector<int> ans((unsigned long) cnt);
		for (int i = 0; i < cnt; ++i) {
			ans[i] = (i ^ (i >> 1));
		}
		return ans;
	}
};
