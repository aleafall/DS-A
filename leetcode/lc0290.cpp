//
// Created by aleafall on 17-4-28.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		string now;
		vector<string> vs;
		unordered_map<string,char> mp;
		stringstream ss(str);
		while (getline(ss, now, ' ')) {
			vs.push_back(now);
		}
		if (pattern.size() != vs.size()) {
			return 0;
		}
		vector<string> p[256];
		for (int i = 0; i < pattern.size(); ++i) {
			if (p[pattern[i]].empty()) {
				p[pattern[i]].push_back(vs[i]);
			} else if (p[pattern[i]].front() != vs[i]) {
				return 0;
			}
			if (mp.count(vs[i]) && mp[vs[i]] != pattern[i]) {
				return 0;
			}
			mp[vs[i]] = pattern[i];
		}
		return 1;
	}
};

int main(){
	return 0;
}
