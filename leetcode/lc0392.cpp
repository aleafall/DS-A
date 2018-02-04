//
// Created by aleafall on 17-5-30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int index = 0;
		for (auto &&item :t) {
			if (index<s.size()&& s[index] == item) {
				++index;
			}
		}
		return index == s.size();
	}
};

int main() {
	Solution solution;
	string s = "axc", t = "ahbgdc";
	cout << solution.isSubsequence(s, t) << endl;
    return 0;
}