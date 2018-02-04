//
// Created by aleafall on 17-9-16.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int leastBricks(vector<vector<int>> &wall) {
		int cnt = 0;
		unordered_map<int, int> mp;
		for (int i = 0; i < wall.size(); ++i) {
			int now = 0;
			for (int j = 0; j < wall[i].size()-1; ++j) {
				now += wall[i][j];
				mp[now]++;
				cnt = max(cnt, mp[now]);
			}
		}
		return (int) wall.size() - cnt;
	}
};
