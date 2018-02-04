//
// Created by aleafall on 17-12-13.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int deleteAndEarn(vector<int> &nums) {
		const int maxn = 20005;
		int a[maxn] = {0};
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (i > 1) {
				a[i] = max(a[i-1], nums[i]+ a[i - 2]);
			} else if (i) {
				a[i] = max(a[i - 1], nums[i]);
			} else {
				a[i] = nums[i];
			}
			ans = max(ans, a[i]);
		}
		return ans;
	}
};

int main() {
    vector<int> vi{23,23,34,34,34,34,23,34,45,56,34,54,34,45,645,3443,456,3434,546,34,454,634,456,5634,5464,4545,45};
	Solution solution;
	cout << solution.deleteAndEarn(vi) << endl;
    return 0;
}
