//
// Created by aleafall on 17-9-24.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	string nextClosestTime(string time) {
		unordered_set<char> st;
		for (auto &&item :time) {
			if (item != ':') {
				st.insert(item);
			}
		}
		auto mm = stoi(time.substr(0, 2)), ss = stoi(time.substr(3, 2));
		while (1) {
			ss++;
			if (ss>= 60) {
				ss = 0;
				mm++;
			}
			if (mm >= 24) {
				mm = 0;
			}
			auto left = to_string(mm), right = to_string(ss);
			time[0] == left.size() > 1 ? left[0] : '0';
			time[1] = left.size() > 1 ? left[1] : left[0];

			time[3] = right.size() > 1 ? right[0] : '0';
			time[4] = right.size() > 1 ? right[1] : right[0];
			int cnt = 0;
			for (auto &&item :time) {
				if (st.count(item)) {
					++cnt;
				}
			}
			if (cnt == 4) {
				return time;
			}
		}
	}

};

int main() {
	Solution solution;
	string str = "01:32";
	cout << solution.nextClosestTime(str) << endl;
    return 0;
}