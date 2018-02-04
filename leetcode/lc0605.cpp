//
// Created by aleafall on 17-9-15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int ans = 0;
		for (int i = 0; i < flowerbed.size(); ++i) {
			if (flowerbed[i]==0) {
				int pre = i == 0 ? 0 : flowerbed[i - 1];
				int next = i == flowerbed.size() - 1 ? 0 : flowerbed[i + 1];
				if (!pre && !next) {
					flowerbed[i] = 1;
					++ans;
				}
			}
		}
		return ans >= n;
	}
};
