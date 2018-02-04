//
// Created by aleafall on 17-5-24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s2.size() < s1.size()) {
			return 0;
		}
		vector<int> v1(26, 0), v2(26, 0);
		for (int i = 0; i < s1.size(); ++i) {
			v1[s1[i] - 'a']++;
			v2[s2[i] - 'a']++;
		}
		if (v1 == v2) {
			return 1;
		}
		for (int i = s1.size(); i < s2.size(); ++i) {
			v2[s2[i] - 'a']++;
			v2[s2[i - s1.size()] - 'a']--;
			if (v1 == v2) {
				return 1;
			}
		}
		return 0;
	}
};
