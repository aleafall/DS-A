//
// Created by aleafall on 18-1-27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
		vector<vector<int>> vi(N, vector<int>(N, 1));
		for (auto &&item :mines) {
			vi[item.front()][item.back()] = 0;
		}
		int ans = 0;
		for (int i = 0; i < vi.size(); ++i) {
			for (int j = 0; j < vi[i].size(); ++j) {
				if (vi[i][j]) {
					ans = max(ans, getLen(i, j, vi));
				}
			}
		}
		return ans;
	}
	int getLen(int i,int j,vector<vector<int>> &vi){
		int X[4] = {0, 0, -1, 1};
		int Y[4] = {-1, 1, 0, 0};
		int offset = 1;
		while (1) {
			bool pass = 1;
			for (int k = 0; k < 4; ++k) {
				int newX = i + offset * X[k];
				int newY = j + offset * Y[k];
				if (newX < 0 || newX >= vi.size() || newY < 0 || newY >= vi[0].size() || vi[newX][newY] == 0) {
					pass = 0;
					break;
				}
			}
			if (!pass) {
				break;
			}
			offset++;
		}
		return offset;
	}
};
