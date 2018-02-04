//
// Created by aleafall on 17-9-8.
//

#include<iostream>

using namespace std;

class Solution {
	int ans;
public:
	int longestConsecutive(TreeNode *root) {
		ans=0;
		preOrder(root, 1, 1);
		return ans;
	}
	preOrder(TreeNode *node,int leftCount,int rightCount){
		if (!node) {
			return;
		}
		ans=max(ans,max(leftCount,rightCount));
		if (node->left) {
			if (node->left->val == node->val + 1) {
				preOrder(node,leftCount+1,rightCount);
			} else {
				preOrder(node, 1, rightCount);
			}
		}
		if (node->right) {
			if (node->right->val == node->val + 1) {
				preOrder(node,leftCount,rightCount+1);
			} else {
				preOrder(node, leftCount, 1);
			}
		}
	}
};

