//
// Created by aleafall on 17-2-16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> ans;
		if (sum < 2) {
			return ans;
		}
		int index = sum / 2;
		for (int i = 1; i <= index; ++i) {
			int temp = 0;
			for (int j = 2; temp < sum; ++j) {
				temp = i * j + j * (j - 1) / 2;
				if (temp == sum) {
					vector<int> now;
					for (int k = 0; k < j; ++k) {
						now.push_back(i + k);
					}
					ans.push_back(now);
					break;
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution solution;
	vector<vector<int>> ans = solution.FindContinuousSequence(3);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}