//
// Created by aleafall on 17-4-30.
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
	int Min = 0x3fffffff;
	int getMinimumDifference(TreeNode *root) {
		int pre = -1;
		inOrder(root, pre);
		return Min;
	}

	void inOrder(TreeNode *node, int &pre){
		if (!node) {
			return;
		}
		inOrder(node->left, pre);
		if (pre != -1) {
			Min = min(Min, abs(node->val - pre));
		}
		pre = node->val;
		inOrder(node->right, pre);
	}
};
