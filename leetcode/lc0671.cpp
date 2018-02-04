//
// Created by aleafall on 17-9-8.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int findSecondMinimumValue(TreeNode *root) {
		if (!root || !root->left || (root->val == root->left->val && root->val == root->right->val)) {
			return -1;
		}
		int ans=root->val;
		preOrder(root->left, root->val, ans);
		preOrder(root->right, root->val, ans);
		return ans;
	}

	void preOrder(TreeNode *node, int rootValue, int &ans) {
		if (!node) {
			return;
		}
		if (node->val > rootValue) {
			ans = ans == rootValue ? node->val : min(ans, node->val);
			return;
		}
		preOrder(node->left, rootValue, ans);
		preOrder(node->right, rootValue, ans);
	}
};
