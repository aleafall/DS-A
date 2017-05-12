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
	int ans;
	int diameterOfBinaryTree(TreeNode *root) {
		ans = 0;
		postOrder(root);
		return ans;
	}

	int postOrder(TreeNode *node) {
		if (!node) {
			return 0;
		}
		int left = postOrder(node->left);
		int right = postOrder(node->right);
		ans = max(ans, left+right);
		return max(left, right) + 1;
	}
};
