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
		unordered_map<char, string> mp1;
		unordered_map<string, char> mp2;
		vector<string> vs;
		stringstream ss(str);
		string now;
		while (getline(ss, now, ' ')) {
			vs.push_back(now);
		}
		for (int i = 0; i < pattern.size() && i < vs.size(); ++i) {
			if (mp1.count(pattern[i])) {
				if (mp1[pattern[i]] != vs[i] ) {
					return 0;
				}
			} else {
				if (mp2.count(vs[i]) && mp2[vs[i]] != pattern[i]) {
					return 0;
				}
				mp1[pattern[i]] = vs[i];
				mp2[vs[i]] = pattern[i];
			}
		}
		return 1;
	}
};

int main(){
	return 0;
}
