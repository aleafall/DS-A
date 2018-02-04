//
// Created by aleafall on 17-5-28.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		vector<string> ans;
		unordered_map<string,int> mp;
		for (int i = 0; i < list1.size(); ++i) {
			mp[list1[i]] = i;
		}
		int Min = 0x3fffffff;
		for (int i = 0; i < list2.size(); ++i) {
			if (mp.count(list2[i])) {
				mp[list2[i]] += (i + 2017);
				Min = min(Min, mp[list2[i]]);
			}
		}
		for (auto &&item :mp) {
			if (item.second > 2016 && item.second == Min) {
				ans.push_back(item.first);
			}
		}
		return ans;
	}
};
