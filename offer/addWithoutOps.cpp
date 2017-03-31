//
// Created by aleafall on 17-2-17.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int Add(int num1, int num2) {
		return num2 ? Add(num1 ^ num2, (num1 & num2) << 1) : num1;
		int a = 1, b = 2;
		a ^= b ^= a ^= b;
		cout << a << " " << b << endl;
		return num1;
	}
};
int main(){
	Solution solution;
	int num1 = 23, num2 = 78;
	cout << solution.Add(num1, num2) << endl;
	return 0;
}
