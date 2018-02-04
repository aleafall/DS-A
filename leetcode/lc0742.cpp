//
// Created by aleafall on 17-12-12.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int diff = 0x3fffffff;
	int ans = 0;
public:
	int findClosestLeaf(TreeNode *root, int k) {
		preOrder(root, k, NULL);
		return ans;
	}

	void preOrder(TreeNode *root, int k,TreeNode* pre){
		if (!root) {
			return;
		}
		if (!root->left && !root->right) {
			if (pre) {
				int temp = min(abs(k - pre->val), abs(k - root->val));
				if (temp<diff) {
					diff = temp;
					ans = root->val;
				}
			} else {
				ans = root->val;
			}
		}
		preOrder(root->left, k,root);
		preOrder(root->right, k,root);
	}
};
