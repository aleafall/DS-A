//
// Created by aleafall on 17-3-9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> mp(256, 0);
		for (auto &&item :t) {
			mp[item]++;
		}
		int cnt = t.size(), left = 0, right = 0, len = INT32_MAX, index = 0;
		while (right < s.size()) {
			if (mp[s[right++]]-- > 0) {
				cnt--;
			}
			while (cnt == 0) {
				if (right - left < len) {
					len = right - (index = left);
				}
				if (mp[s[left++]]++ == 0) {
					++cnt;
				}
			}
		}
		return len == INT32_MAX ? "" : s.substr(index, len);
		vector<int> vs(256, 0), vt(256, 0);
		if (s.size() < t.size()) {
			return "";
		}
		string ans;
		int i = 0, j = 0;
		while (j < t.size()) {
			vs[s[j]]++;
			vt[t[j++]]++;
		}
		if (vs == vt) {
			ans = t;
		}
		for (int i = 0; i < vt.size(); ++i) {
			cout << vs[i] << " ";
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}
		cout << endl;
		for (int i = 0; i < vt.size(); ++i) {
			cout << vt[i] << " ";
			if ((i + 1) % 10 == 0) {
				cout << endl;
			}
		}
		cout << endl;
		while (j < s.size()) {
			while (j < s.size() && !isContain(vs, vt)) {
				cout << "not in " << s.substr(0, j) << endl;
				vs[s[j++]]++;
			}
			cout << "test " << s.substr(i, j - i + 1) << endl;
			while (isContain(vs, vt)) {
				int len = min((int) s.size() - 1, j) - i + 1;
				if (ans.empty() || ans.size() > len) {
					cout << "before " << ans << endl;
					ans = s.substr(i, len);
					cout << "after " << ans << endl;
				}
				vs[s[i++]]--;
			}
		}
		return ans;
	}

	bool isContain(vector<int> &vs, vector<int> &vt) {
		for (int i = 0; i < vs.size(); ++i) {
			if (vs[i] < vt[i]) {
				return 0;
			}
		}
		return 1;
	}

};

int main(){
	Solution solution;
	string s = "ADOBECODEBANC";
	string t = "ABC";
	s = "abc";
	t = "b";
	string ss = "122323232323232";
	cout << atoi(ss.c_str()) << endl;
	cout << solution.minWindow(s, t) << endl;
}