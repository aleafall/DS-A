//
// Created by aleafall on 17-9-26.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
	int kEmptySlots(vector<int>& flowers, int k) {
		set<int> st;
		for (int i = 0; i < flowers.size(); ++i) {
			st.insert(flowers[i]);
			auto pos = st.find(flowers[i]);
			if (pos != st.begin() && flowers[i]- *(--pos) == k + 1) {
				return i + 1;
			}
			pos = st.upper_bound(flowers[i]);
			if (pos != st.end() && *pos-flowers[i] == k + 1) {
				return i + 1;
			}
		}
		return -1;
	}
};
