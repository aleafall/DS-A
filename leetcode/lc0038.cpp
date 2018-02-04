//
// Created by aleafall on 16-11-14.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n < 1) {
			return "";
		}
		string ans = "1";
		for (int i = 1; i < n; ++i) {
			string next;
			int cnt = 0;
			for (int j = 0; j < ans.size(); ++j) {
				if (j == 0 || ans[j] == ans[j - 1]) {
					++cnt;
				} else {
					next += (to_string(cnt) + ans[j-1]);
					cnt = 1;
				}
				if (j == (int) ans.size() - 1) {
					next += (to_string(cnt) + ans[j]);
				}
			}
			ans = next;
		}
		return ans;
	}
};

int main() {
	Solution solution;
	for (int i = 1; i <= 10; ++i) {
		cout << i <<" " << solution.countAndSay(i) << endl;
	}
}