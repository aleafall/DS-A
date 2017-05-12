//
// Created by aleafall on 17-4-21.
//

#include <iostream>

using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) {
			return 0;
		}
		int i = 0, j = 0, k;
		int m = needle.size();
		for (; i < haystack.size();) {
			if (haystack[i] != needle[j]) {
				for (k = needle.size() - 1; k >= 0; --k) {
					if (needle[k] == haystack[m]) {
						break;
					}
				}
				i = m - k;
				j = 0;
				m = i + (int) needle.size();
			} else {
				if (j == needle.size() - 1) {
					return i - j;
				}
				++i, ++j;
			}
		}
		return -1;
	}
};

int main() {

	return 0;
}
