//
// Created by aleafall on 17-9-27.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<string>> printTree(TreeNode *root) {
		int height = getHeight(root);
		int len = (1 << height) - 1;
		vector<vector<string>> ans(height, vector<string>(len, ""));
		if (!root) {
			return ans;
		}
		vector<int> pos(len+1, 0);
		preOrder(root, ans, pos, height, 0, 1);
		return ans;
	}

	void preOrder(TreeNode *node, vector<vector<string>> &ans,vector<int> &pos,int height,int level,int tag){
		if (!node) {
			return;
		}
		if (tag == 1) {
			pos[tag - 1] = ((1 << height) - 1) / 2;
			ans[0][pos[tag-1]] = to_string(node->val);
		} else {
			int lastPos = pos[tag / 2 - 1];
			if (tag & 1) {
				pos[tag - 1] = lastPos + ((1 << (height - level)) - 1) / 2+1;
			} else {
				pos[tag - 1] = lastPos - ((1 << (height - level)) - 1) / 2-1;
			}
			ans[level][pos[tag - 1]] = to_string(node->val);
		}
		preOrder(node->left, ans, pos, height, level + 1, tag * 2);
		preOrder(node->right, ans, pos, height, level + 1, tag * 2 + 1);
	}
	int getHeight(TreeNode *root){
		return root ? max(getHeight(root->left), getHeight(root->right)) + 1 : 0;
	}
};
