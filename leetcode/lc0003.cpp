//
// Created by aleafall on 17-2-9.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans = 0;
		for (int i = 0; i < s.size(); ++i) {
			int vis[256] = {0};
			for (int j = i; j < s.size(); ++j) {
				vis[s[j]]++;
				if (vis[s[j]]>1){
					ans = max(ans, j - i);
					break;
				}
				if (j == s.size() - 1) {
					ans = max(ans, j - i + 1);
				}
				if (ans == s.size()) {
					break;
				}
			}
		}
		return ans;
	}
};
