//
// Created by aleafall on 17-2-7.
//

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int pathSum(TreeNode *root, int sum) {
		int ans = 0;
		preOrder(root, sum, ans);
		return ans;
	}

	void preOrder(TreeNode *node, int sum, int &ans) {
		if (!node) {
			return;
		}
		getValue(node, 0, sum, ans);
		preOrder(node->left, sum, ans);
		preOrder(node->right, sum, ans);
	}

	void getValue(TreeNode *node, int temp, int sum, int &ans) {
		if (!node) {
			return;
		}
		temp += node->val;
		if (temp == sum) {
			ans++;
		}
		getValue(node->left, temp, sum, ans);
		getValue(node->right, temp, sum, ans);
	}
};
