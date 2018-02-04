//
// Created by aleafall on 17-5-23.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> st, temp;
		vector<int> ans;
		for (auto &&item :nums1) {
			st.insert(item);
		}
		for (auto &&item :nums2) {
			if (st.count(item) && !temp.count(item)) {
				temp.insert(item);
				ans.push_back(item);
			}
		}
		return ans;
	}
};
