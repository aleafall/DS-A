//
// Created by aleafall on 17-5-17.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;

	UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
	unordered_map<int, UndirectedGraphNode *> mp;
	unordered_set<int> vis;
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node) {
			return node;
		}
		UndirectedGraphNode *ans = new UndirectedGraphNode(node->label);
		mp.insert(make_pair(node->label, ans));
		DFS(node);
		return ans;
	}

	void DFS(UndirectedGraphNode *node) {
		if (!node) {
			return;
		}
		vis.insert(node->label);
		if (!mp.count(node->label)) {
			UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
			mp.insert(make_pair(node->label, newNode));
		}
		for (auto &&item :node->neighbors) {
			if (!item) {
				continue;
			}
			if (!mp.count(item->label)) {
				UndirectedGraphNode *newNode = new UndirectedGraphNode(item->label);
				mp.insert(make_pair(item->label, newNode));
			}
			mp[node->label]->neighbors.push_back(mp[item->label]);
			if (!vis.count(item->label)) {
				DFS(item);
			}
		}
	}
};
