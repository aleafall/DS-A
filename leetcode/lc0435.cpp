//
// Created by aleafall on 17-9-23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;

	Interval() : start(0), end(0) {}

	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	int eraseOverlapIntervals(vector<Interval> &intervals) {
		int ans = 0;
		if (intervals.empty()) {
			return 0;
		}
		sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
			if (a.start != b.start) {
				return a.start < b.start;
			}
			return a.end < b.end;
		});
		vector<int> dp(intervals.size(), 1);
		for (int i = 0; i < intervals.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (intervals[i].start >= intervals[j].end) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		return (int) intervals.size() - ans;
	}
};
