//
// Created by aleafall on 17-10-21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if (matrix.empty() || matrix.front().empty()) {
			return ans;
		}
		int cnt = matrix.size() + matrix.front().size() - 1;
		for (int i = 0; i < cnt; ++i) {
			//from down
			int begR, begC;
			if (i & 1) {
				if (i < matrix[0].size()) {
					begR = 0, begC = i;
				} else {
					begC = matrix[0].size() - 1, begR = i + 1 - matrix[0].size();
				}
				while (begR < matrix.size() && begC >= 0) {
					ans.push_back(matrix[begR++][begC--]);
				}
			} else {
				if (i < matrix.size()) {
					begR = i, begC = 0;
				} else {
					begR = matrix.size() - 1, begC = i + 1 - matrix.size();
				}
				while (begR >= 0 && begC < matrix[0].size()) {
					ans.push_back(matrix[begR--][begC++]);
				}
			}
		}
		return ans;
	}
};