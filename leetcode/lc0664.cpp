//
// Created by aleafall on 17-10-3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int strangePrinter(string s) {
		return cal(0, (int) s.size() - 1, s);
	}

	int cal(int beg, int end, string &s) {
		bool found = 0;
		int ans = 0, nextBeg = beg, nextEnd = end;
		while (beg <= end) {
			while (s[end] != s[beg]) {
				--end;
			}
			if (!found) {
				found = 1;
				nextBeg = end + 1;
			}
			ans++;
			for (beg++; beg < s.size() && s[beg] == s[beg - 1]; ++beg) {}
		}
		return ans + (nextBeg <= nextEnd ? cal(nextBeg, nextEnd, s) : 0);
	}
};


int main() {
	Solution solution;
	string s = "aaabbbsadfasfafadsgagasdagfdfgdhfghfghghgdhf";
	cout << solution.strangePrinter(s) << endl;
	return 0;
}
