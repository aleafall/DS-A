//
// Created by t-xiuyan on 6/17/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string decodeString(string s) {
		int index = 0;
		return decodeString(s, index);
	}
	string decodeString(string s,int &index){
		string ans;
		while (index < s.size() && s[index] != ']') {
			if (!isdigit(s[index])) {
				ans += s[index++];
			} else {
				int cnt = 0;
				while (index < s.size() && isdigit(s[index])) {
					cnt = cnt * 10 + s[index++] - '0';
				}
				++index;
				string subString = decodeString(s, index);
				++index;
				for (int i = 0; i < cnt; ++i) {
					ans += subString;
				}
			}
		}
		return ans;
	}
};


