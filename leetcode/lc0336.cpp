//
// Created by aleafall on 16-12-6.
//
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string> &words) {
		vector<vector<int>> ans;
		unordered_map<string,int> mp;
		for (int i = 0; i < words.size(); ++i) {
			mp[words[i]] = i;
		}
		for (auto &&item :mp) {
			if (item.first.empty()) {
				continue;
			}
			if (isPali(item.first) && mp.count("")) {
				ans.push_back({item.second, mp[""]});
				ans.push_back({mp[""], item.second});
			}
			auto rever = item.first;
			reverse(rever.begin(), rever.end());
			if (mp.count(rever)&&rever!=item.first) {
				ans.push_back({item.second, mp[rever]});
			}
			for (int i = 1; i < item.first.size(); ++i) {
				auto left = item.first.substr(0, i);
				auto right = item.first.substr(i);
				auto leftRe = left;
				reverse(leftRe.begin(), leftRe.end());
				auto rightRe = right;
				reverse(rightRe.begin(), rightRe.end());
				if (isPali(left) && mp.count(rightRe)) {
					ans.push_back({mp[rightRe], item.second});
				}
				if (isPali(right) && mp.count(leftRe)) {
					ans.push_back({item.second, mp[leftRe]});
				}
			}
		}
		return ans;
	}

	bool isPali(const string &str) {
		for (int i = 0; i < str.size() / 2; ++i) {
			if (str[i] != str[str.size() - 1 - i]) {
				return 0;
			}
		}
		return 1;
	}
};


int main() {
    Solution so;
	vector<string> vs{"abcd", "dcba", "lls", "s", "sssll"};
	vector<vector<int>> ans=so.palindromePairs(vs);
	for (auto &&item :ans) {
		cout << item.front() << " " << item.back() << endl;
	}
    return 0;
}
