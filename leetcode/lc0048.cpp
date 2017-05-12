//
// Created by aleafall on 16-11-2.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		int n = (int) matrix.size() - 1;
		for (int i = 0, temp = 0; i <= n / 2; ++i) {
			for (int j = i; j < n - i; ++j) {
				temp = matrix[j][n - i];
				cout << "temp " << temp << endl;
				matrix[j][n - i] = matrix[i][j];
				matrix[i][j] = matrix[n - j][i];
				matrix[n - j][i] = matrix[n - i][n - j];
				matrix[n - i][n - j] = temp;
			}
		}
	}
};

int main() {
	Solution solution;
	vector<vector<int>> vi(3, vector<int>(3));
	for (int i = 0; i < vi.size(); ++i) {
		for (int j = 0; j < vi[0].size(); ++j) {
			vi[i][j] = i * 3 + j + 1;
			cout << vi[i][j] << " ";
		}
		cout << endl;
	}
	solution.rotate(vi);
	for (int i = 0; i < vi.size(); ++i) {
		for (int j = 0; j < vi[0].size(); ++j) {
			cout << vi[i][j] << " ";
		}
		cout << endl;
	}
}