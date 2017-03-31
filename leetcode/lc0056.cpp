//
// Created by aleafall on 16-10-26.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Definition for an interval.
 *  */
struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        if (intervals.empty()) {
            return ans;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        auto now=intervals[0];
        for (size_t i = 0; i <intervals.size() ; ++i) {
            if (intervals[i].start >= now.start && intervals[i].start <= now.end && intervals[i].end >= now.end) {
                now.end=intervals[i].end;
            } else if (intervals[i].end<=now.end) {
                continue;
            }
            else {
                ans.push_back(now);
                now = intervals[i];
            }
        }
        ans.push_back(now);
        return ans;
    }

    static bool cmp(Interval a, Interval b){
        if (a.start != b.start) {
            return a.start<b.start;
        }
        return a.end < b.end;
    }
};

int main(){
    Solution *solution=new Solution;
    vector<Interval> vi{Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
//    vi.clear();
//    vi.push_back(Interval(1, 4));
//    vi.push_back(Interval(2, 3));
    vector<Interval> ans = solution->merge(vi);
    for (size_t i = 0; i <ans.size() ; ++i) {
        cout<<ans[i].start<<" "<<ans[i].end<<endl;
    }
    delete solution;
    return 0;
}