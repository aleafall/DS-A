//
// Created by aleafall on 17-2-18.
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
	int TreeDepth(TreeNode *pRoot) {
		int ans = 0;
		preOrder(pRoot, 1, ans);
		return ans;
	}

	void preOrder(TreeNode *root, int depth, int &ans){
		if (!root) {
			return;
		}
		ans = max(ans, depth);
		preOrder(root->left, depth + 1, ans);
		preOrder(root->right, depth + 1, ans);
	}
};
