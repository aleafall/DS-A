//
// Created by aleafall on 17-5-14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> g;
	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		int Max = *max_element(pid.begin(), pid.end());
		Max = max(Max, *max_element(ppid.begin(), ppid.end()));
		g = vector<vector<int>>(Max + 1, vector<int>(0));
		vector<int> ans;
		for (int i = 0; i < pid.size(); ++i) {
			g[ppid[i]].push_back(pid[i]);
		}
		DFS(ans, kill);
		return ans;
	}
	void DFS(vector<int> &ans,int kill){
		ans.push_back(kill);
		for (int i = 0; i < g[kill].size(); ++i) {
			DFS(ans, g[kill][i]);
		}
	}
};
