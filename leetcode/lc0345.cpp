//
// Created by aleafall on 17-2-7.
//


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		string vo;
		for (auto &item:s) {
			if (isV(item)) {
				vo += item;
				item = 'a';
			}
		}
		if (vo.empty()) {
			return s;
		}
		int i = (int) (vo.size() - 1);
		for (auto &item:s) {
			if (item == 'a') {
				item = vo[i--];
			}
		}
		return s;
	}
	bool isV(char c){
		switch (c) {
			case 'a':
				return 1;
			case 'e':
				return 1;
			case 'i':
				return 1;
			case 'o':
				return 1;
			case 'u':
				return 1;
			case 'A':
				return 1;
			case 'E':
				return 1;
			case 'I':
				return 1;
			case 'O':
				return 1;
			case 'U':
				return 1;
			default:
				return 0;
		}
	}
};
