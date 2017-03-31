//
// Created by aleafall on 17-2-21.
//

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool isSymmetrical(TreeNode *pRoot) {
		return !pRoot || isSame(pRoot->left, pRoot->right);
	}

	bool isSame(TreeNode *left, TreeNode *right) {
		return (!left && !right) || (left && right && left->val == right->val && isSame(left->left, right->right) &&
		                             isSame(left->right, right->left));
	}

};
