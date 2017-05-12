//
// Created by aleafall on 17-4-28.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		return check(s, t) && check(t, s);
	}

	bool check(const string &s, const string &t) {
		unordered_map<char, char> mp;
		for (int i = 0; i < s.size(); ++i) {
			if (mp.count(s[i])) {
				if (mp[s[i]] != t[i]) {
					return 0;
				}
			} else {
				mp[s[i]] = t[i];
			}
		}
		return 1;
	}
};
