//
// Created by aleafall on 17-10-13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) {
		int ans = 0;
		for (int first = 0; first + k <= s.size();) {
			int cnt[26] = {0};
			int mask = 0, max_last = first;
			for (int last = first; last < s.size(); ++last) {
				int i = s[last] - 'a';
				cnt[i]++;
				if (cnt[i] < k) {
					mask |= (1 << i);
				} else {
					mask &= (~(1 << i));
				}
				if (mask == 0) {
					ans = max(ans, last - first + 1);
					max_last=last;
				}
			}
			first = max_last + 1;
		}
		return ans;
	}
};

int main() {
	Solution solution;
	string s = "ababacb";
	int k = 3;
	cout << solution.longestSubstring(s, k) << endl;
    return 0;
}