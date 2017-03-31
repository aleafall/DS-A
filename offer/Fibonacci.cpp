//
// Created by aleafall on 17-2-26.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int a[50] = {0};

	int Fibonacci(int n) {
		if (n == 0 || n == 1) {
			return n;
		}
		return a[n] ? a[n] : a[n] = Fibonacci(n - 1) + Fibonacci(n - 2), a[n];
	}
};

int main(){
	Solution solution;
	cout << solution.Fibonacci(38) << endl;
}
