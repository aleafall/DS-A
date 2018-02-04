//
// Created by aleafall on 17-5-24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> vs(26,0),vp(26,0), ans;
		if (s.size() < p.size()) {
			return ans;
		}
		for (int i = 0; i < p.size(); ++i) {
			++vp[p[i] - 'a'];
			++vs[s[i] - 'a'];
		}
		if (vp == vs) {
			ans.push_back(0);
		}
		for (size_t i = p.size(); i < s.size(); ++i) {
			++vs[s[i] - 'a'];
			--vs[s[i - p.size()] - 'a'];
			if (vs == vp) {
				ans.push_back((int &&) (i - p.size() + 1));
			}
		}
		return ans;
	}
	bool isAnagrams(string &s,string &t){
		vector<int> vi(256, 0);
		for (auto &&item :s) {
			vi[item]++;
		}
		for (auto &&item :t) {
			vi[item]--;
		}
		for (auto &&item :vi) {
			if (item) {
				return 0;
			}
		}
		return 1;
	}
};

int main() {
	string s = "abab", t = "ab";
	Solution solution;
	vector<int> vi = solution.findAnagrams(s, t);
	for (auto &&item :vi) {
		cout << item << " ";
	}
	cout << endl;
}