//
// Created by t-xiuyan on 7/15/2017.
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
	vector<double> averageOfLevels(TreeNode *root) {
		vector<double> ans;
		if (!root) {
			return ans;
		}
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			int len = q.size();
			double cur = 0;
			for (int i = 0; i < len; ++i) {
				TreeNode *node = q.front();
				cur += node->val;
				q.pop();
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			ans.push_back(cur / len);
		}
		return ans;
	}
};

