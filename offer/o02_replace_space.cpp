//
// Created by aleafall on 17-2-13.
//

//replace space

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
		int cnt = 0;
		for (int i = 0; i < length; ++i) {
			if (str[i] == ' ') {
				cnt++;
			}
		}
		char ans[length + 2 * cnt + 1];
		int j = 0;
		for (int i = 0; i < length; ++i,++j) {
			if (str[i] != ' ') {
				ans[j] = str[i];
			} else {
				ans[j] = '%';
				ans[++j] = '2';
				ans[++j] = '0';
			}
		}
		strcpy(str, ans);
	}
};
