//
// Created by aleafall on 17-9-23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int ans = 0;
		multiset<int> st;
		sort(g.begin(), g.end());
		reverse(g.begin(), g.end());
		for (auto &&item :s) {
			st.insert(item);
		}
		for (auto &&item :g) {
			auto pos = st.lower_bound(item);
			if (pos != st.end() && *pos >= item) {
				++ans;
				st.erase(pos);
			}
		}
		return ans;
	}
};
