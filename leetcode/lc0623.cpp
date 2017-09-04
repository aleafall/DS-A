//
// Created by t-xiuyan on 8/24/2017.
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
	TreeNode *addOneRow(TreeNode *root, int v, int d) {
		if (d == 1) {
			TreeNode *node = new TreeNode(v);
			node->left=root;
			return node;
		}
		DFS(root, 1, v, d);
		return root;

	}
	void DFS(TreeNode *node,int level,int v,int d){
		if (!node) {
			return;
		}
		if (level == d - 1) {
			TreeNode *leftNode = new TreeNode(v), *rightNode = new TreeNode(v);
			leftNode->left = node->left, rightNode->right = node->right;
			node->left=leftNode,node->right=rightNode;
			return;
		}
		DFS(node->left, level + 1, v, d);
		DFS(node->right, level + 1, v, d);
	}
};
