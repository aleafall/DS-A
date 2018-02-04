//
// Created by aleafall on 17-11-20.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class MyCalendar {
	map<int, int> mp;
public:
	MyCalendar() {

	}

	bool book(int start, int end) {
		auto pos = mp.lower_bound(start);
		bool ans = 0;
		if (pos != mp.end()) {

			auto newStart = pos->second;
			mp.erase(pos);
			mp[end] = newStart;
			ans = 1;
		} else {
			mp[end] = start;
			ans = 1;
		}
		return ans;
	}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
