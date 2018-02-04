//
// Created by aleafall on 18-1-28.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int reachNumber(int target) {
		long long now = 0;
		target = abs(target);
		for (int i = 1;; ++i) {
			now += i;
			if (now >= target && (now - target) % 2 == 0) {
				return i;
			}
		}
	}

};

int main(){
	Solution s;
	int target = -3;
	cout << s.reachNumber(target) << endl;
}
