//
// Created by aleafall on 17-3-6.
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
	int last, ans;
	int findBottomLeftValue(TreeNode *root) {
		last = -1;
		inOrder(root, 0);
		return ans;
	}

	void inOrder(TreeNode *node,int level){
		if (!node) {
			return;
		}
		inOrder(node->left, level + 1);
		if (level > last) {
			last = level;
			ans = node->val;
		}
		inOrder(node->right, level + 1);
	}
};
