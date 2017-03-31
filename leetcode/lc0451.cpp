//
// Created by aleafall on 17-2-9.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	struct Ch {
		char c;
		int fru;

		Ch(char c, int fru){
			this->c=c;
			this->fru=fru;
		}
		bool operator<(const Ch &ch){
			return fru<ch.fru;
		}

	};
	string frequencySort(string s) {
		map<char,int> mp;
		for (auto item:s) {
			if (mp.find(item) != mp.end()) {
				mp[item]++;
			} else {
				mp[item] = 1;
			}
		}
		string ans;
		vector<Ch> vc;
		for (auto item:mp) {
			vc.push_back(Ch(item.first, item.second));
		}
		sort(vc.begin(), vc.end());
		for (auto item:vc) {
			ans.insert(0, string(item.fru, item.c));
		}
		return ans;
	}
};
