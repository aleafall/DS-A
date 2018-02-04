//
// Created by aleafall on 17-9-8.
//

#include<iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int left = 0, right = n - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (isBadVersion(mid + 1)) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		return left;
	}
};
