//
// Created by aleafall on 17-4-20.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string ans;
		while (n>0) {
			int now = n % 26 ;
			ans += now ? now - 1 + 'A' : 'Z';
			n = (n / 26) ;
			if (now == 0) {
				--n;
			}
//			if (n <= 1 && now == 0) {
//				break;
//			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	Solution solution;
	cout << solution.convertToTitle(53) << endl;
}

