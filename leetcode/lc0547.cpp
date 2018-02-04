//
// Created by t-xiuyan on 8/20/2017.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
	vector<int> father;

	int findCircleNum(vector<vector<int>> &M) {
		unordered_set<int> st;
		for (int i = 0; i < M.size(); ++i) {
			father.push_back(i);
		}
		for (int i = 0; i < M.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (M[i][j] == 1) {
					Union(i, j);
				}
			}
		}
		for (int i = 0; i < M.size(); ++i) {
			st.insert(findFather(i));
		}
		return (int) st.size();
	}

	int findFather(int x) {
		if (father[x] == x) {
			return x;
		}
		int F = findFather(father[x]);
		father[x] = F;
		return F;
	}

	void Union(int a, int b) {
		int faA = findFather(a);
		int faB = findFather(b);
		if (faA != faB) {
			father[faB] = faA;
		}
	}
};
