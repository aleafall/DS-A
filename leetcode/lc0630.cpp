//
// Created by t-xiuyan on 7/8/2017.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		multiset<int> st;
		int used_time = 0;
		sort(courses.begin(),courses.end(),[](vector<int> a,vector<int> b){ return a.back() < b.back(); });
		for (auto &&item :courses) {
			if (used_time + item.front() <= item.back()) {
				st.insert((int &&) item.front());
				used_time += item.front();
			} else if (*st.rbegin() > item.front()) {
				used_time += item.front() - *st.rbegin();
				st.erase(--st.end());
				st.insert((int &&) item.front());
			}
		}
		return st.size();
	}
};
