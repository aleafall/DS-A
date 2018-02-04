//
// Created by aleafall on 16-10-25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int> &nums, int target) {
		return vector<int>{lower_bound(nums, target), upper_bound(nums, target) };
	}

	int binarySearch(vector<int> &nums, int target) {
		int l = 0, r = (int) nums.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] > target) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return -1;
	}

	int lower_bound(vector<int> &nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return nums[left] == target ? left : -1;
	}

	int upper_bound(vector<int> &nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] <= target) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return left;
	}
};

int main() {
	vector<int> vi{5, 7, 7, 8, 8, 10}, ans;
	Solution *solution = new Solution;
	ans = solution->searchRange(vi, 9);
	for (auto i:ans) {
		cout << i << endl;
	}
	delete solution;
	return 0;
}