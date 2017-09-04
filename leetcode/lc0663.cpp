//
// Created by t-xiuyan on 8/22/2017.
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
public:
	int sum;
	bool ans;
	bool checkEqualTree(TreeNode *root) {
		if (!root || (!root->left && !root->right)) {
			return 0;
		}
		sum = getSum(root);
		if (sum & 1) {
			return 0;
		}
		sum /= 2;
		ans = 0;
		preOrder(root);
		return ans;
	}
	void preOrder(TreeNode *node){
		if (!node||ans) {
			return;
		}
		int now = getSum(node);
		if (now == sum) {
			ans=1;
			return;
		}
		preOrder(node->left);
		preOrder(node->right);
	}
	int getSum(TreeNode *root){
		return root?root->val+getSum(root->left)+getSum(root->right):0;
	}
};