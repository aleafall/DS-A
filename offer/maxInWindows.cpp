//
// Created by aleafall on 17-2-22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
		vector<int> ans;
		if (num.empty() || !size||size>num.size()) {
			return ans;
		}
		int Max = INT32_MIN, cnt = 1;
		int beg = 0, end = size;
		for (int i = 0; i < size; ++i) {
			if (num[i] > Max) {
				Max = num[i];
				cnt = 1;
			} else if (num[i] == Max) {
				++cnt;
			}
		}
		ans.push_back(Max);
		while (end < num.size()) {
			if (num[beg++] == Max) {
				--cnt;
			}
			++end;
			if (Max == num[end - 1]) {
				++cnt;
			} else if (Max < num[end - 1]) {
				Max = num[end - 1];
				cnt = 1;
			} else if (!cnt) {
				Max = *max_element(num.begin() + beg, num.begin() + end);
				cnt = 1;
			}
//			cout << "beg end Max " << beg << " " << end << " " << Max <<endl;
//			cout << cnt << endl;
			ans.push_back(Max);
		}
		return ans;
	}
};

int main() {
	Solution solution;
	vector<int> vi{16,14,12,10,8,6,4};
	vector<int> ans = solution.maxInWindows(vi, 8);
	for (auto &&item :ans) {
		cout << item << endl;
	}
	return 0;
}