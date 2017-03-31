//
// Created by aleafall on 17-3-6.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findLonelyPixel(vector<vector<char>>& picture) {
		vector<int> sumOfLines(picture.size(), 0), sumOfCols(picture[0].size(), 0);
		for (int i = 0; i < picture.size(); ++i) {
			for (int j = 0; j < picture[0].size(); ++j) {
				if (picture[i][j] == 'B') {
					sumOfLines[i]++;
					sumOfCols[j]++;
				}
			}
		}
//		for (int i = 0; i < picture.size(); ++i) {
//			cout << sumOfLines[i] << endl;
//		}
//		for (int i = 0; i < picture[0].size(); ++i) {
//			cout << sumOfCols[i] << endl;
//		}
		int ans = 0;
		for (int i = 0; i < picture.size(); ++i) {
			for (int j = 0; j < picture[0].size(); ++j) {
				if (picture[i][j] == 'B' && sumOfLines[i] == 1 && sumOfCols[j] == 1) {
					++ans;
				}
			}
		}
		return ans;
	}
};
