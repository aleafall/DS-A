//
// Created by aleafall on 17-2-26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> ans;
		DFS(ans, 0, str);
		return ans;
	}

	void DFS(vector<string> &ans, int index, string str) {
		if (index == str.size() - 1) {
			ans.push_back(str);
		}
		unordered_set<char> ust;
		sort(str.begin() + index, str.end());
		for (int i = index; i < str.size(); ++i) {
			if (ust.find(str[i]) == ust.end()) {
				ust.insert(str[i]);
				swap(str[i], str[index]);
				DFS(ans, index + 1, str);
			}
		}
	}
};
