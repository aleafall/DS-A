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
	TreeNode *deleteNode(TreeNode *root, int key) {
		if (!root) {
			return NULL;
		}
		TreeNode *ans = root;
		if (root->val == key) {
			if (root->left) {
				ans = root->left;
				TreeNode *right = root->left;
				while (right->right) {
					right = right->right;
				}
				right->right = root->right;
			} else if (root->right) {
				ans = root->right;
			} else {
				ans = NULL;
			}
		} else if (root->val > key) {
			ans->left = deleteNode(root->left, key);
		} else {
			ans->right = deleteNode(root->right, key);
		}
		if (ans) {
			ans->left = deleteNode(ans->left, key);
			ans->right = deleteNode(ans->right, key);
		}
		return ans;
	}
};
