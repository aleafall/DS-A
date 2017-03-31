//
// Created by aleafall on 16-10-26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        auto now = intervals[0];
        for (size_t i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start >= now.start && intervals[i].start <= now.end && intervals[i].end >= now.end) {
                now.end = intervals[i].end;
            } else if (intervals[i].end <= now.end) {
                continue;
            } else {
                ans.push_back(now);
                now = intervals[i];
            }
        }
        ans.push_back(now);
        return ans;
    }

    static bool cmp(Interval a, Interval b) {
        if (a.start != b.start) {
            return a.start < b.start;
        }
        return a.end < b.end;
    }
};
