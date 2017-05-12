//
// Created by aleafall on 17-4-21.
//

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		/*string ans;
		stack<string> st;
		vector<string> vs;
		string now;
		for (int i = 0; i < path.size(); ++i) {
			if (path[i] == '/') {
				if (now == "..") {
					if (!st.empty()) {
						st.pop();
					}
				} else if (now != "." && !now.empty()) {
					st.push("/" + now);
				}
				now.clear();
			} else {
				now += path[i];
			}
		}
		if (!now.empty()) {
			st.push(now);
		}
		while (!st.empty()) {
			vs.push_back((basic_string<char, char_traits<char>, allocator<char>> &&) st.top());
			st.pop();
		}
		for (int i = (int) vs.size() - 1; i >= 0; --i) {
			ans += vs[i];
		}*/
		string ans, now;
		vector<string> vs;
		stringstream ss(path);
		while (getline(ss, now, '/')) {
			if (now.empty() || now == ".") {
				continue;
			}
			if (now == ".." && !vs.empty()) {
				vs.pop_back();
			} else if (now != "..") {
				vs.push_back(now);
			}
		}
		for (auto &&item :vs) {
			ans += "/" + item;
		}
		return ans.empty() ? "/" : ans;
	}
};

int main() {
	Solution solution;
	string path = "/...";
	cout << solution.simplifyPath(path) << endl;
	return 0;
}
