//
// Created by aleafall on 17-2-18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> ans;
		if (matrix.empty()) {
			return ans;
		}
		int nowR, nowC, minR = 0, maxR = matrix.size(), minC = 0, maxC = matrix[0].size();
		int index = 0,total= (int) (matrix.size() * matrix[0].size());
		while (index < total) {
			for (nowR = minR, nowC = minC; nowC < maxC && index < total; ++nowC, ++index) {
				ans.push_back(matrix[nowR][nowC]);
			}
			++minR;
			for (nowC = maxC - 1, nowR = minR; nowR < maxR && index < total; ++nowR, ++index) {
				ans.push_back(matrix[nowR][nowC]);
			}
			--maxC;
			for (nowR = maxR - 1, nowC = maxC - 1; nowC >= minC && index < total; --nowC, ++index) {
				ans.push_back(matrix[nowR][nowC]);
			}
			--maxR;
			for (nowC = minC, nowR = maxR - 1; nowR >= minR && index < total; --nowR, ++index) {
				ans.push_back(matrix[nowR][nowC]);
			}
			++minC;
		}
		return ans;
	}
};
