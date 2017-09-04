//
// Created by t-xiuyan on 6/19/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxDistance(vector<vector<int>>& arrays) {
		int ans = 0;
		int left = arrays[0].front(), right = arrays[0].back();
		for (int i = 1; i < arrays.size(); ++i) {
			ans = max(ans, max(right - arrays[i].front(), arrays[i].back() - left));
			left = min(left, arrays[i].front());
			right = max(right, arrays[i].back());
		}
		return ans;
	}
};
