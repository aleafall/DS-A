//
// Created by aleafall on 17-3-12.
//

#include<iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		stack<char> st;
		string ans;
		for (auto &&item :num) {
			while (k && !st.empty() && st.top() > item) {
				st.pop();
				--k;
			}
			st.push(item);
		}
		while (k) {
			st.pop();
			--k;
		}
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}
		reverse(ans.begin(), ans.end());
		while (!ans.empty() && ans.front() == '0') {
			ans.erase(ans.begin());
		}
		return ans.empty() ? "0" : ans;
	}
};

int main() {
    Solution solution;
	string num = "1111";
	int k = 3;
	cout << solution.removeKdigits(num, k) << endl;
    return 0;
}
