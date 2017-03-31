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
	bool IsBalanced_Solution(TreeNode *pRoot) {
		if (!pRoot) {
			return 1;
		}
		return abs(getHeight(pRoot->left) - getHeight(pRoot->right)) < 2 && IsBalanced_Solution(pRoot->left) &&
		       IsBalanced_Solution(pRoot->right);

	}
	int getHeight(TreeNode *node){
		if (!node) {
			return 0;
		}
		return max(getHeight(node->left), getHeight(node->right)) + 1;
	}
};
