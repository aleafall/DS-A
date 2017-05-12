//
// Created by aleafall on 17-3-5.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> ans;
		if (k <= 0) {
			return ans;
		}
		ans.reserve(k);
		int i = 0, j = 0;
		k = (int) (nums1.size() + nums2.size());
		while (k) {
			ans.push_back(nums1[i] > nums2[j] ? nums1[i++] : nums2[j++]);
			--k;
		}
		return ans;
	}
};

int main(){
	Solution solution;
	vector<int> v1{3, 4, 6, 5}, v2{9, 1, 2, 5, 8, 3};
	int k = 5;
	vector<int> ans = solution.maxNumber(v1, v2, k);
	for (auto &&item :ans) {
		cout << item << " ";
	}
	cout << endl;
}
