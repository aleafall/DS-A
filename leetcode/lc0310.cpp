//
// Created by aleafall on 17-9-22.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
	int height;
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
		if (n == 1) {
			return vector<int>{0};
		}
		vector<unordered_set<int>> adj(n);
		for (auto &&item :edges) {
			adj[item.first].insert(item.second);
			adj[item.second].insert(item.first);
		}
		vector<int> leaves;
		for (int i = 0; i < n; ++i) {
			if (adj[i].size() == 1) {
				leaves.push_back(i);
			}
		}
		while (n > 2) {
			n -= leaves.size();
			vector<int> temp;
			for (int i = 0; i < leaves.size(); ++i) {
				int item = *adj[leaves[i]].begin();
				adj[item].erase(leaves[i]);
				if (adj[item].size() == 1) {
					temp.push_back(item);
				}
			}
			leaves = temp;
		}
		return leaves;
	}
};

int main() {
	Solution solution;
	vector<pair<int, int>> edges{{0, 1},
	                             {0, 2},
	                             {0, 3},
	                             {3, 4}};
	int n = 5;
	auto ans = solution.findMinHeightTrees(n, edges);
	for (auto &&item :ans) {
		cout << item << endl;
	}
    return 0;
}