//
// Created by aleafall on 17-5-25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	vector<string> ans;
public:
	vector<string> restoreIpAddresses(string s) {
		if (s.size() > 12) {
			return ans;
		}
		vector<int> vi{0};
		DFS(vi, s);
		return ans;
	}

	void DFS(vector<int> vi,  string &s) {
		if (vi.size() == 4) {
			if (s.size() - vi.back() > 0 && s.size() - vi.back() < 4) {
				int last = stoi(s.substr(vi.back(), s.size()));
				string temp = s.substr(vi.back(), s.size());
				if (check(temp)) {
					string now;
					for (int i = 0; i < vi.size(); ++i) {
						if (i < (int) vi.size() - 1) {

							now += s.substr(vi[i], vi[i + 1] - vi[i]);
							now += ".";
						} else {
							now += s.substr(vi[i], s.size());
						}
					}
					ans.push_back(now);
					return;
				}
			}
		}
		for (int i = vi.back() + 1; i - vi.back() < 4 && i < s.size(); ++i) {
			string temp = s.substr(vi.back(), i - vi.back());
			if (check(temp)) {
				vi.push_back(i);
				DFS(vi, s);
				vi.pop_back();
			}
		}
	}
	bool check(string &s){
		int num = stoi(s);
		if ((num && s.front() == '0') || (!num && s.size() > 1) || (num > 255)) {
			return 0;
		}
		return 1;
	}
};

int main(){
	string s = "0000";
	Solution solution;
	auto ans = solution.restoreIpAddresses(s);
	for (auto &&item :ans) {
		cout << item << endl;
	}
}
