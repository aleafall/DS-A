//
// Created by aleafall on 17-9-26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> ans;
		int i = 0, j = n;
		while (i <= j) {
			if (k > 1) {
				ans.push_back(k-- % 2 ? i++ : j--);
			} else {
				ans.push_back(i++);
			}
		}
		return ans;
	}
};
