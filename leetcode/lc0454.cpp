//
// Created by aleafall on 17-3-10.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int ans = 0;
		unordered_map<int, int> ump1, ump2;
		init(A, B, ump1);
		init(C, D, ump2);
		for (auto item:ump1) {
			if (ump2.count(-item.first)) {
				ans += item.second * ump2[-item.first];
			}
		}
		return ans;
	}

	void init(vector<int> &v1, vector<int> &v2, unordered_map<int, int> &ump) {
		for (int i = 0; i < v1.size(); ++i) {
			for (int j = 0; j < v2.size(); ++j) {
				++ump[v1[i] + v2[j]];
			}
		}
	}
};
