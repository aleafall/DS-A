//
// Created by aleafall on 16-12-6.
//
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string> &words) {
		vector<vector<int>> ans;
		unordered_map<string,int> ump;
		for (int i = 0; i < words.size(); ++i) {
			ump[words[i]] = i;
		}
		for (int i = 0; i < words.size(); ++i) {
			if (isPali(words[i]) && ump.count("") && words.size()) {
				ans.push_back(vector<int>{ump[words[i]], ump[""]});
			}
			string temp = words[i];
			reverse(temp.begin(), temp.end());
			if (ump.count(temp)) {
				ans.push_back(vector<int>{ump[words[i]], ump[temp]});
			}
			for (int i = 0; i < words[i].size(); ++i) {
				string left = words[i].substr(0, i + 1), right = words[i].substr(i + 1, words[i].size());
				if (isPali(left)) {
					string re_right = right;
					reverse(re_right.begin(), re_right.end());
					if (ump.count(re_right)) {
						ans.push_back(vector<int>{ump[words[i]], ump[re_right]});
					}
				}
				if (isPali(right)) {
					string re_left = left;
					reverse(re_left.begin(), re_left.end());
					if (ump.count(re_left)) {
						ans.push_back(vector<int>{ump[words[i]], ump[re_left]});
					}
				}
			}

		}
		return ans;
	}

	bool isPali(const string &str) {
		for (int i = 0; i < str.size() / 2; ++i) {
			if (str[i] != str[str.size() - 1 - i]) {
				return 0;
			}
		}
		return 1;
	}
};



