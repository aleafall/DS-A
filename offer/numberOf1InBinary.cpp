//
// Created by aleafall on 17-2-17.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		/*int ans = 0, tag = 1;
		while (tag) {
			if (n & tag) {
				++ans;
			}
			tag = (tag << 1);
		}
		return ans;*/
		int ans = 0;
		while (n) {
			++ans;
			n &= (n - 1);
		}
		return ans;
	}
};

int main(){
	Solution solution;
	cout << solution.NumberOf1(10) << endl;
	return 0;
}
