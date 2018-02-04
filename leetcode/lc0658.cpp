//
// Created by aleafall on 17-10-20.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		vector<int> ans;
		int beg = 0, end = 0;
		if (k <= 0||arr.empty()) {
			return ans;
		}
		for (int i = 0; i < arr.size(); ++i) {
			if (end - beg < k) {
				end++;
			} else if (end - beg == k && abs(arr[beg] - x) > abs(arr[i] - x)) {
				end=i+1;
				beg = end - k;
			}
		}
		return vector<int>(arr.begin() + beg, arr.begin() + end);
	}
};

int main() {
	Solution solution;
	vector<int> vi{1,2,3,4,5};
	int k = 4, x = 3;
	auto ans = solution.findClosestElements(vi, k, x);
	for (auto &&item :ans) {
		cout << item << endl;
	}
    return 0;
}