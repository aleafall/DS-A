//
// Created by aleafall on 17-5-23.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> mp1, mp2;
		vector<int> ans;
		for (auto &&item :nums1) {
			mp1[item]++;
		}
		for (auto &&item :nums2) {
			mp2[item]++;
		}
		for (auto &&item :mp1) {
			if (mp2.count(item.first)) {
				for (int i = 0; i < min(item.second, mp2[item.first]); ++i) {
					ans.push_back(item.first);
				}
			}
		}
		return ans;
	}
};
