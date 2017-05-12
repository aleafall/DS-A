//
// Created by aleafall on 17-4-26.
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
	TreeNode *convertBST(TreeNode *root) {
		int now = 0;
		inOrder(root, now);
		return root;
	}
	void inOrder(TreeNode *node,int &now){
		if (!node) {
			return;
		}
		inOrder(node->right, now);
		now += node->val;
		node->val = now;
		inOrder(node->left, now);
	}
};
