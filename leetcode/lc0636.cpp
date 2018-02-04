//
// Created by aleafall on 17-9-25.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		vector<int> ans(n, 0);
		int sum = 0;
		stack<int> st;
		for (auto &&item :logs) {
			stringstream ss(item);
			vector<string> vi;
			string now;
			while (getline(ss, now, ':')) {
				vi.push_back(now);
			}
			if (vi[1] == "start") {
				st.push(stoi(vi[2]));
			} else {
				int beg = st.top(), end = stoi(vi[2]);
				st.pop();
				ans[stoi(vi[0])] += end - beg - sum;
				sum = end - beg;
			}
		}
		return ans;
	}
};

int main() {
	Solution solution;
	int n = 2;
	vector<string> vs{"0:start:0","1:start:2","1:end:5","0:end:6"};
	auto ans = solution.exclusiveTime(n, vs);
	for (auto &&item :ans) {
		cout << item << endl;
	}
    return 0;
}
