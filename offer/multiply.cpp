//
// Created by aleafall on 17-2-25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int> &A) {
		vector<int> ans;
		if (A.empty()) {
			return ans;
		}
		ans.push_back(1);
		for (int i = 0; i < A.size() - 1; ++i) {
			ans.push_back(ans.back() * A[i]);
		}
		int temp = 1;
		for (int i = A.size() - 1; i >= 0; --i) {
			ans[i] *= temp;
			temp *= A[i];
		}
		return ans;
	}
};

int main() {
	Solution solution;
	vector<int> A{0, 0, 3, 4, 5};
	vector<int> ans = solution.multiply(A);
	for (auto &&item  :ans) {
		cout << item << endl;
	}
}