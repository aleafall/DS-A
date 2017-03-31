//
// Created by aleafall on 17-2-26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty()) {
			return 0;
		}
		int left = 0, right = rotateArray.size() - 1, mid = 0;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (rotateArray[mid] > rotateArray[right]) {
				left = mid + 1;
			} else if (rotateArray[mid] == rotateArray[right]) {
				--right;
			} else {
				right = mid;
			}
		}
		return rotateArray[left];
	}
};

int main(){
	Solution solution;
	vector<int> vi{1, 1, 1, 1, 0,1};
	cout << solution.minNumberInRotateArray(vi) << endl;
};
