//
// Created by aleafall on 17-4-28.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_set<string> st;
		for (int i = 0; i < (int) s.size() - 9; ++i) {
			if (isSub(s.substr(i + 1, string::npos), s.substr(i, 10))) {
				st.insert(s.substr(i, 10));
			}
		}
		vector<string> vs;
		for (auto &&item :st) {
			vs.push_back(item);
		}
		return vs;
	}
	bool isSub(const string &text,const string &pattern){
		if (text.size() < 10 || pattern.size() < 10) {
			return 0;
		}
		int i = 0, j = 0,k, m = (int) pattern.size();
		for (; i < pattern.size(); ++i) {
			if (text[i] != pattern[j]) {
				for (k = pattern.size() - 1, k >= 0; --k;) {
					if (pattern[k] == text[m]) {
						break;
					}
				}
				i = m - k;
				j = 0;
				m = i + (int) pattern.size();
			} else {
				if (j = pattern.size() - 1) {
					return 1;
				}
				++i, ++j;
			}
		}
		return 0;
	}
};
