//
// Created by aleafall on 17-4-28.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string,int> mp;
		vector<string> ans;
		for (int i = 0; i < (int)s.size() - 10; ++i) {
			mp[s.substr(i, 10)]++;
		}
		for (auto &&item :mp) {
			if (item.second > 1) {
				ans.push_back(item.first);
			}
		}
		return ans;
	}
};
