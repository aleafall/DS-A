//
// Created by aleafall on 17-10-14.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
	struct cmp {
		bool operator<(const pair<string, int> &a, const pair<string, int> &b) {
			if (a.second != b.second) {
				return a.second > b.second;
			}
			return a.first < b.first;
		}
	};

	vector<string> topKFrequent(vector<string> &words, int k) {
		vector<string> ans;
		unordered_map<string, int> mp;
		for (auto &&item :words) {
			mp[item]++;
		}
		priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
		vector<pair<string, int>> vs;
		for (auto &&item :mp) {
			vs.emplace_back(item.first, item.second);
		}
		sort(vs.begin(), vs.end(), [](pair<string, int> &a, pair<string, int> &b) {
			if (a.second != b.second) {
				return a.second > b.second;
			}
			return a.first < b.first;
		});
		for (int i = 0; i < k; ++i) {
			ans.push_back(vs[i].first);
		}
		return ans;
	}
};

int main() {
	Solution solution;
	return 0;
}
