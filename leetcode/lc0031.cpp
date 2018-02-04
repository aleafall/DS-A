//
// Created by aleafall on 16-10-10.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &nums) {
		int index = (int) nums.size() - 1;
		while (index && nums[index] <= nums[index - 1]) {
			--index;
		}
		if (index == 0) {
			sort(nums.begin(), nums.end());
			return;
		}
		int now = index - 1;
		while (index < nums.size() && nums[index] > nums[now]) {
			++index;
		}
		--index;
		swap(nums[index], nums[now]);
		sort(nums.begin() + now + 1, nums.end());
	}
};

int main() {
	vector<int> nums{6, 5, 4, 8, 7, 5, 1};
	Solution *solution = new Solution;
	solution->nextPermutation(nums);
	delete solution;
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << endl;
	}
	return 0;
}
