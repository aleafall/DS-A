//
// Created by aleafall on 17-3-6.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	map<int, int> mp;
	vector<int> largestValues(TreeNode *root) {
		vector<int> ans;
		inOrder(root, 0);
		for (auto &&item:mp) {
			ans.push_back(item.second);
		}
		return ans;
	}
	void inOrder(TreeNode *node,int level){
		if (!node) {
			return;
		}
		inOrder(node->left, level + 1);
		if (mp.count(level)) {
			if (mp[level] < node->val) {
				mp[level] = node->val;
			}
		} else {
			mp[level] = node->val;
		}
		inOrder(node->right, level + 1);
	}
};
