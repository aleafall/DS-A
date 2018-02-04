//
// Created by aleafall on 17-5-13.
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
	bool isSubtree(TreeNode *s, TreeNode *t) {
		return !t || s && (isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
	}
	void preOrder(TreeNode *s,TreeNode *t, bool &flag){
		if (!s || flag) {
			return;
		}
		if (isSameTree(s, t)) {
			flag = 1;
			return;
		}
		preOrder(s->left, t, flag);
		preOrder(s->right,t, flag);
	}
	bool isSameTree(TreeNode *s,TreeNode *t){
		return (!s && !t) ||
		       ((s && t && s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right));
	}
};
