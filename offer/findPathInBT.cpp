//
// Created by aleafall on 17-2-21.
//

#include <iostream>
#include <vector>

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
	vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
		vector<vector<int>> ans;
		if (!root) {
			return ans;
		}
		vector<int> vi;
		preOrder(root, vi, ans, expectNumber);
		return ans;
	}
	void preOrder(TreeNode *node,vector<int> vi,vector<vector<int>> &ans,int expectNumber){
		if (!node) {
			return;
		}
		vi.push_back(node->val);
		if (!node->left && !node->right) {
			int sum=0;
			for (auto item:vi) {
				sum += item;
			}
			if (sum == expectNumber) {
				ans.push_back(vi);
			}
			return;
		}
		preOrder(node->left, vi, ans, expectNumber);
		preOrder(node->right, vi, ans, expectNumber);
	}
};
