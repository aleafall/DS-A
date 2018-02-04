//
// Created by aleafall on 17-9-26.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Interval {
	int start;
	int end;

	Interval() : start(0), end(0) {}

	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<int> findRightInterval(vector<Interval> &intervals) {
		vector<int> ans(intervals.size(), -1);
		map<int, int> mp;
		for (int i = 0; i < intervals.size(); ++i) {
			mp[intervals[i].start] = i;
		}
		for (int i = 0; i < intervals.size(); ++i) {
			auto pos = mp.lower_bound(intervals[i].end);
			if (pos != mp.end()) {
				ans[i] = pos->second;
			}
		}
		return ans;
	}
};

