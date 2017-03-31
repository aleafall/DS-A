//
// Created by aleafall on 17-3-11.
//

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		vector<vector<int>> vi(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				if (matrix[i][j] == '1') {

				}
			}
		}
	}
};
