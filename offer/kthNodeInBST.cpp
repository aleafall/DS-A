//
// Created by aleafall on 17-2-20.
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
	TreeNode *KthNode(TreeNode *pRoot, int k) {
		if (!pRoot) {
			return NULL;
		}
		TreeNode *ans = NULL;
		inOrder(pRoot, ans, k);
		return ans;
	}

	void inOrder(TreeNode *root, TreeNode *&ans,int &k){
		if (!root||ans) {
			return;
		}
		inOrder(root->left, ans,k);
		--k;
		if (!k) {
			ans = root;
			return;
		}
		inOrder(root->right, ans, k);
	}
};
