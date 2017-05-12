//
// Created by aleafall on 16-10-18.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	long long Min = INT64_MIN;
	bool flag = 1;

	bool isValidBST(TreeNode *root) {
//        inOrder(root);
//        return flag;
		if (!root) {
			return 1;
		}
		return
				(!root->left || root->left->val <= root->val) &&
				(!root->right || root->right->val > root->val) &&
				isValidBST(root->left) && isValidBST(root->right);
	}

	void inOrder(TreeNode *node) {
		if (node == NULL) return;
		inOrder(node->left);
		if (node->val > Min) {
			Min = node->val;
		} else flag = 0;
		inOrder(node->right);
	}
};

int main() {
	Solution *solution = new Solution;
	TreeNode *root = new TreeNode(-2147483648);
	TreeNode *node = new TreeNode(1);
//    root->left = node;
	cout << solution->isValidBST(root) << endl;
	delete solution;
	delete root;
	delete node;
	return 0;
}