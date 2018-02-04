//
// Created by aleafall on 17-9-29.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	int ans = 0;
	int X[4]{0, 0, -1, 1}, Y[4]{-1, 1, 0, 0};
	void DFS(int &index,int steps,int &minStep,vector<int> &vi, vector<vector<int>> &forest, int x, int y) {

	}

public:
	int cutOffTree(vector<vector<int>>& forest) {
		vector<pair<int,pair<int,int>>> values;
		for (int i = 0; i < forest.size(); ++i) {
			for (int j = 0; j < forest[0].size(); ++j) {
				if (forest[i][j] > 1) {
					values.push_back({forest[i][j],{i,j}});
				}
			}
		}
		sort(values.begin(),values.end(),[](pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b) {
			return a.first < b.first;
		});
		int index = 0;
	}
};
