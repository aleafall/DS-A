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
public:
	int longestUnivaluePath(TreeNode *root) {
		int ans = 0;
		preOrder(root, ans);
		return ans;
	}

	void preOrder(TreeNode *node, int &ans) {
		if (!node) {
			return;
		}
		ans = max(ans, cal(node, node->left) + cal(node, node->right));
		preOrder(node->left, ans);
		preOrder(node->right, ans);
	}

	int cal(TreeNode *root, TreeNode *node) {
		if (!node || node->val != root->val) {
			return 0;
		}
		return max(cal(root, node->left), cal(root, node->right)) + 1;
	}
};
