//
// Created by aleafall on 17-9-8.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximumSwap(int num) {
		string str = to_string(num);
		int a[10] = {0};
		for (int i = 0; i < str.size(); ++i) {
			a[str[i] - '0'] = i;
		}
		for (int i = 0; i < str.size(); ++i) {
			for (int j = 9; j > str[i] - '0'; --j) {
				if (a[j] > i) {
					swap(str[i],str[a[j]]);
					return atoi(str.c_str());
				}
			}
		}
		return num;
	}
};

int main() {
	Solution solution;
	int num = 1993;
	cout << solution.maximumSwap(num) << endl;
    return 0;
}
