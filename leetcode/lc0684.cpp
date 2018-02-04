//
// Created by aleafall on 17-9-24.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
	int father[2001];
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		for (int i = 0; i < 2001; ++i) {
			father[i] = i;
		}
		vector<int> ans;
		for (auto &&item :edges) {
			if (findFather(item.front()) != findFather(item.back())) {
				Union(item.front(), item.back());
			} else {
				ans = item;
			}
		}
		return ans;
	}
	void Union(int a,int b) {
		int faA = findFather(a);
		int faB = findFather(b);
		if (faA != faB) {
			father[faB] = faA;
		}
	}
	int findFather(int x){
		if (x == father[x]) {
			return x;
		}
		int F = findFather(father[x]);
		father[x] = F;
		return F;
	}
};

int main() {
    Solution solution;
	vector<vector<int>> vi{{1, 2},
	               {1, 3},
	               {2, 3}};
	auto ans = solution.findRedundantConnection(vi);
	cout << ans.front() << " " << ans.back() << endl;
    return 0;
}