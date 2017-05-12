//
// Created by aleafall on 17-2-12.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int findComplement(int num) {
		int ans = 0;
		num = ~num;
		bool flag = 0;
		int check = 1 << 31;
		for (int i = 0; i < 32; ++i) {
			if (!flag && !(check & num)) {
				flag = 1;
			}
			if (flag) {
				ans = ans*2 + (check & num)/check;
			}
			num <<= 1;
		}
		return ans;
	}
};

int main(){
	Solution solution;
	cout << solution.findComplement(1) << endl;
	return 0;
}