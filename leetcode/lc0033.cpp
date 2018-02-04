//
// Created by aleafall on 16-10-24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
	    int left = 0, right = (int) nums.size() - 1;
	    while (left <= right) {
		    int mid = left + (right - left) / 2;
		    if (nums[mid] == target) {
			    return mid;
		    } else if (nums[mid] >= nums[left]) {
			    if (target >= nums[left] && target < nums[mid]) {
				    right = mid - 1;
			    } else {
				    left = mid + 1;
			    }
		    } else {
			    if (target > nums[mid] && target <= nums[right]) {
				    left = mid + 1;
			    } else {
				    right = mid - 1;
			    }
		    }
	    }
	    return -1;
    }
};

int main() {
	Solution solution;
	vector<int> vi{3, 1};
	int n = 1;
	cout << solution.search(vi, n) << endl;
    return 0;
}