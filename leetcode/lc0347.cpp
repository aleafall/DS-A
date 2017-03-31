//
// Created by aleafall on 17-2-9.
//

#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		struct Ele {
			int e,fru;

			Ele(int e, int fru){
				this->e=e,this->fru=fru;
			}

			bool operator<(const Ele &ele){
				return fru > ele.fru;
			}
		};
		unordered_map<int, int> mp;
		for (auto item:nums) {
			if (mp.find(item) != mp.end()) {
				mp[item]++;
			} else {
				mp[item] = 1;
			}
		}
		vector<Ele> ve;
		for (auto item:mp) {
			ve.push_back(Ele(item.first, item.second));
		}
		sort(ve.begin(), ve.end());
		vector<int> ans;
		for (int i = 0; i < k; ++i) {
			ans.push_back(ve[i].e);
		}
		return ans;
	}
};