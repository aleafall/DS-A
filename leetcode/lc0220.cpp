//
// Created by aleafall on 17-5-23.
//

#include <iostream>
#include <vector>
#include <set>
#include <set>

using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<long long > st;
		for (int i = 0; i < nums.size(); ++i) {
			if (i > k) {
				st.erase(nums[i - k - 1]);
			}
			auto pos = st.lower_bound((long long)nums[i]-t);
			if (pos != st.end() && (long long)*pos-nums[i] <= t) {
				return 1;
			}
			st.insert((long long)nums[i]);
		}
		return 0;
	}
};

int main(){
	Solution solution;
	vector<int> vi{2147483647,-2147483647};
	int k = 3, t = 3;
	cout << solution.containsNearbyAlmostDuplicate(vi, k, t) << endl;
}
