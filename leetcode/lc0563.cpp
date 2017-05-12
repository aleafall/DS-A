//
// Created by aleafall on 17-4-26.
//

#include <iostream>
#include <unordered_map>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	unordered_map<TreeNode *, int> mp;
	int ans = 0;
	int findTilt(TreeNode *root) {
		ans = 0;
		inOrder(root);
		return ans;
	}
	void inOrder(TreeNode *node){
		if (!node) {
			return;
		}
		inOrder(node->left);
		inOrder(node->right);
		int left = node->left ? node->left->val : 0;
		int right = node->right ? node->right->val : 0;
		node->val += left + right;
		ans += abs(left - right);
	}
};
