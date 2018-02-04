//
// Created by aleafall on 17-9-19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPalindrome(string &s, int left, int right) {
		while (++left < --right) {
			if (s[left] != s[right]) {
				return 0;
			}
		}
		return 1;
	}
	bool validPalindrome(string s) {
		int left=-1,right=s.size();
		while (++left < --right) {
			if (s[left] != s[right]) {
				return isPalindrome(s, left -1, right) || isPalindrome(s, left, right+1);
			}
		}
		return 1;
	}
};

int main() {
	Solution solution;
	string s = "abc";
	cout << solution.validPalindrome(s) << endl;
	return 0;
}
