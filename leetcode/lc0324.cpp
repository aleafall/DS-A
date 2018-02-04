//
// Created by aleafall on 16-10-17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define A(i) nums[(1+2*(i)) % (n|1)]

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int n = (int) nums.size();

        // Find a median.
        auto midPtr = nums.begin() + n / 2;
        nth_element(nums.begin(), midPtr, nums.end());
        int mid = *midPtr;

        // Index-rewiring.
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
	        if (A(j) > mid) {
		        cout << "A(i) A(j) " << A(i) << " " << A(j) << endl;
		        swap(A(i++), A(j++));
	        } else if (A(j) < mid) {
		        cout << "A(i) A(k) " << A(i) << " " << A(k) << endl;
		        swap(A(j), A(k--));
	        } else {
		        j++;
	        }
        }

    }
};

int main() {
	vector<int> nums{1, 5, 1, 1, 6, 4};
    Solution *solution = new Solution;
    solution->wiggleSort(nums);
    delete solution;
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
