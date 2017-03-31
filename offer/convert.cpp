//
// Created by aleafall on 17-2-25.
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
	TreeNode *Convert(TreeNode *pRootOfTree) {
		if (!pRootOfTree) {
			return NULL;
		}
		TreeNode *ans = pRootOfTree;
		while (ans->left) {
			ans = ans->left;
		}
		TreeNode *lastNode = NULL;
		inOrder(lastNode, pRootOfTree);
		return ans;
	}
	void inOrder(TreeNode *&lastNode, TreeNode *root){
		if (!root) {
			return;
		}
		inOrder(lastNode, root->left);
		root->left = lastNode;
		if (lastNode) {
			lastNode->right = root;
		}
		lastNode = root;
		inOrder(lastNode, root->right);
	}
};

int main(){
	Solution solution;
	TreeNode *node[6];
	for (int i = 0; i < 6; ++i) {
		node[i] = new TreeNode(i + 1);
	}
	node[3]->left = node[1], node[3]->right = node[5];
	node[1]->left = node[0], node[1]->right = node[2];
	node[5]->left = node[4];
	TreeNode *ans = solution.Convert(node[3]);
	while (ans) {
		cout << ans->val << endl;
		ans = ans->right;
	}
	for (int i = 0; i < 6; ++i) {
		delete node[i];
	}
}