//
// Created by aleafall on 17-4-18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> ans;
		if (nums.empty() || lower > upper) {
			return ans;
		}
	/*	int beg = 0, end = 0, index = 0;
		while (index < nums.size()) {
			if (end != nums[index]) {
				beg = index ? nums[index - 1] + 1 : 0;
				end = nums[index] - 1;
				if (beg != end) {
					ans.push_back(to_string(beg) + string("->") + to_string(end));
				} else {
					ans.push_back(to_string(beg));
				}
				++index;
			}
			while (nums[index] == end) {
				++index, ++end;
			}
		}
		if (nums.back() < upper) {
			beg = nums.back() + 1;
			end = upper;
		}
		return ans;*/
		int left = lower;
		for (int i = 0; i <= nums.size(); ++i) {
			int right = i < nums.size() && nums[i] <= upper ? nums[i] : upper + 1;
			if (left == right) {
				++left;
			} else {
				ans.push_back(right - left == 1 ? to_string(left) : to_string(left) + "->" + to_string(right - 1));
				left = right + 1;
			}
		}
		return ans;
	}
};

int main() {
    Solution solution;
	vector<int> vi{0, 1, 3, 50, 75};
	auto ans = solution.findMissingRanges(vi, 0, 99);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
    return 0;
}
