//
// Created by aleafall on 17-9-11.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	vector<vector<string>> ans;
public:
	vector<vector<string>> partition(string s) {
		if (s.empty()) {
			return ans;
		}
		vector<string> vs;
		DFS(0, s, vs);
		return ans;

	}
	void DFS(int index,string &s,vector<string> &vs){
		if (index >= s.size()) {
			ans.push_back(vs);
		}
		for (int i = 1; i <=s.size()-index; ++i) {
			string now = s.substr(index, i);
			if (isPalindrome(now)) {
				vs.push_back(now);
				DFS(index + i, s, vs);
				vs.pop_back();
			}
		}
	}
	bool isPalindrome(string &s){
		if (s.empty()) {
			return 0;
		}
		for (int i = 0; i < s.size() / 2; ++i) {
			if (s[i] != s[s.size() - 1 - i]) {
				return 0;
			}
		}
		return 1;
	}
};
