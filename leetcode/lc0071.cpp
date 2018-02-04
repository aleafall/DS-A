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
	string simplifyPath(string &path) {
		string ans, now;
		vector<string> vs;
		stringstream ss(path);
		while (getline(ss, now, '/')) {
			if (now == "..") {
				if (!vs.empty()) {
					vs.pop_back();
				}
			} else if (now == ".") {
				continue;
			} else {
				vs.push_back( now);
			}
		}
		for (auto &&item :vs) {
			if (!item.empty()) {
				ans += "/"+item;
			}
		}
		return ans.empty() ? "/" : ans;
	}
};

int main() {
	Solution solution;
	string path = "/home//foo/";
	cout << solution.simplifyPath(path) << endl;
	return 0;
}
