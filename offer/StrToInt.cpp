//
// Created by aleafall on 17-2-26.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		long long ans = 0;
		if (str.empty()) {
			return 0;
		}
		int flag = 1;
		int index = 0;
		if (str[0] == '+') {
			++index;
		} else if (str[0] == '-') {
			flag = -1;
			++index;
		}
		for (int i = index; i < str.size(); ++i) {
			if (str[i] >= '0' && str[i] <= '9') {
				ans = ans * 10 + str[i] - '0';
			} else {
				return 0;
			}
		}
		return (int) (ans < 0 || ans-1 > INT32_MAX ? 0 : flag * ans);
	}
};

int main(){
	Solution solution;
	string str("1a33");
	cout << solution.StrToInt(str) << endl;
}