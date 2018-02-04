//
// Created by aleafall on 17-9-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nextGreaterElement(int n) {
		string str = to_string(n);
		bool found = 0;
		long long ans = 0;
		for (int i = str.size() - 1; i > 0; --i) {
			if (str[i] > str[i - 1]) {
				found = 1;
				int j;
				for (j = str.size() - 1; j >= i; --j) {
					if (str[j] > str[i - 1]) {
						break;
					}
				}
				swap(str[i - 1], str[j]);
				sort(str.begin() + i, str.end());
				ans = stoll(str);
				break;
			}
		}
		return found && ans <= INT32_MAX ? (int) ans : -1;
	}
};

int main() {
	Solution solution;
	int n = 12443322;
	cout << solution.nextGreaterElement(n) << endl;
    return 0;
}