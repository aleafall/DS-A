//
// Created by aleafall on 17-10-14.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	unordered_map<int,bool> mp;
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		if (maxChoosableInteger >= desiredTotal) {
			return 1;
		}
		if (maxChoosableInteger * (1 + maxChoosableInteger) / 2 < desiredTotal) {
			return 0;
		}
		return DFS(desiredTotal, 0, maxChoosableInteger);
	}

	bool DFS(int target, int visited,int Max) {
		if (mp.count(visited)) {
			return mp[visited];
		}
		for (int i = 1; i <= Max; ++i) {
			int mask = (1 << i);
			if ((visited & mask) == 0 && (i >= target || DFS(target - i, mask | visited, Max) == 0)) {
				mp[visited] = 1;
				return 1;
			}
		}
		mp[visited] = 0;
		return 0;
	}
};
