//
// Created by aleafall on 17-2-28.
//

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
	bool isNumeric(char *string) {
		bool hasE = 0, dot = 0, symbol = 0;
		int len = (int) strlen(string);
		for (int i = 0; i < len; ++i) {
			if (string[i] == 'e' || string[i] == 'E') {
				if (i == len - 1 || hasE) {
					return 0;
				}
				hasE = 1;
			} else if (string[i] == '+' || string[i] == '-') {
				if (symbol && string[i - 1] != 'e' && string[i-1] != 'E') {
					return 0;
				}
				if (!symbol && i && string[i - 1] != 'e' && string[i - 1] != 'E') {
					return 0;
				}
				symbol = 1;
			} else if (string[i] == '.') {
				if (hasE || dot) {
					return 0;
				}
				dot = 1;
			} else if (string[i] < '0' || string[i] > '9') {
				return 0;
			}
			cout << "i " << i << endl;
		}
		return 1;
	}
};

int main(){
	Solution solution;
	char c[] = {"-1E-16"};
	cout << solution.isNumeric(c) << endl;
}