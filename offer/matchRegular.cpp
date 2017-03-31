//
// Created by aleafall on 17-2-27.
//

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
	bool match(char *str, char *pattern) {
		if (!str || !pattern) {
			return 0;
		}
		return Next(str, pattern);
	}

	bool Next(char *str, char *pattern) {
		if (*pattern == '\0') {
			return *str == '\0';
		}
		if (*(pattern + 1) == '*') {
			if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
				return Next(str + 1, pattern) || Next(str, pattern + 2);
			} else {
				return Next(str, pattern + 2);
			}
		}
		if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
			return Next(str + 1, pattern + 1);
		}
		return 0;
	}
};
