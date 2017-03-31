//
// Created by aleafall on 17-2-17.
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
	void Mirror(TreeNode *pRoot) {
		if (!pRoot) {
			return;
		}
		Mirror(pRoot->left);
		Mirror(pRoot->right);
		swap(pRoot->left, pRoot->right);
	}
};