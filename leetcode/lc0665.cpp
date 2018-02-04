<<<<<<< HEAD
//
// Created by aleafall on 17-9-13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int cnt = 0;
		for (int i = 1; i < nums.size() && cnt < 2; ++i) {
			if (nums[i - 1] > nums[i]) {
				++cnt;
				if (i - 2 < 0 || nums[i - 2] <= nums[i]) {
					nums[i - 1] = nums[i];
				} else {
					nums[i] = nums[i - 1];
				}
			}
		}
		return cnt < 2;
	}
};

int main() {
    return 0;
}
=======
//
// Created by t-xiuyan on 8/29/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int cnt=0;
		for (int i = 0; i < (int) nums.size() - 1; ++i) {
			if (nums[i] > nums[i + 1] ) {
				if (i) {
					if (nums[i - 1] <= nums[i + 1]) {
						++cnt;
					} else {
						return 0;
					}
				} else if (){

				}
			}
		}
		return 1;
	}
};
>>>>>>> 758190852492f055a2a6122324716c916e0711bb
