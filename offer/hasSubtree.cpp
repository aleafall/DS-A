//
// Created by aleafall on 17-2-17.
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
	bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
		if (!pRoot1 || !pRoot2) {
			return 0;
		}
		return isEqual(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}

	bool isEqual(TreeNode *root, TreeNode *target){
		if (!target) {
			return 1;
		}
		if (!root) {
			return 0;
		}
		return root->val == target->val && isEqual(root->left, target->left) && isEqual(root->right, target->right);
	}
};
