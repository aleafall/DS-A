//
// Created by aleafall on 17-9-19.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
	bool ans;
	stack<char> st;
public:
	bool checkValidString(string s) {
		ans = 0;
		DFS(s, 0, ans);
		return ans;
	}

	void DFS(string &s, int index, bool &ans) {
		if (ans) {
			return;
		}
		if (index >= s.size()) {
			ans = st.empty();
			return;
		}
		if (s[index] == '(') {
			st.push(s[index]);
			DFS(s, index + 1, ans);
			st.pop();
		} else if (s[index] == '*') {
			st.push('(');
			DFS(s, index + 1, ans);
			st.pop();
			DFS(s, index + 1, ans);
			if (!st.empty()) {
				st.pop();
				DFS(s, index + 1, ans);
				st.push('(');
			}
		} else {
			if (!st.empty()) {
				st.pop();
				DFS(s, index + 1, ans);
				st.push('(');
			}
		}
	}
};

int main() {
	Solution s;
	string str = "(*)))";
	cout << s.checkValidString(str) << endl;
	return 0;
}