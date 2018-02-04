//
// Created by aleafall on 17-11-6.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	string longestWord(vector<string>& words) {
		unordered_set<string> st;
		for (auto &&item :words) {
			st.insert(item);
		}
		sort(words.begin(), words.end(), [](string &a, string &b) {
			if (a.size() != b.size()) {
				return a.size() > b.size();
			}
			return a < b;
		});
		for (auto &&item :words) {
			auto now = item.substr(0, item.size() - 1);
			bool found = 1;
			while (!now.empty()) {
				if (!st.count(now)) {
					found = 0;
				}
				now.pop_back();
			}
			if (found) {
				return item;
			}
		}
		return "";
	}
};
