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
	int sumOfLeftLeaves(TreeNode *root) {
		if (!root) {
			return 0;
		}
		int ans = 0;
		if (root->left) {
			if (!root->left->left && !root->left->right) {
				ans = root->left->val;
			} else {
				ans += sumOfLeftLeaves(root->left);
			}
		}
		if (root->right) {
			ans += sumOfLeftLeaves(root->right);
		}
		return ans;
	}
};
