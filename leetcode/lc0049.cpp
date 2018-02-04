//
// Created by aleafall on 17-5-24.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string,vector<int>> mp;
		vector<vector<string>> ans;
		for (int i = 0; i < strs.size(); ++i) {
			string now = strs[i];
			sort(now.begin(), now.end());
			mp[now].push_back(i);
		}
		for (auto &&item :mp) {
			vector<string> now;
			for (auto &&i:item.second) {
				now.push_back(strs[i]);
			}
			ans.push_back(now);
		}
		return ans;
	}
};

int main(){
	vector<string> strs{""};
	Solution solution;
	auto ans = solution.groupAnagrams(strs);
}
