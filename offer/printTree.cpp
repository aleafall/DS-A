//
// Created by aleafall on 17-2-17.
//

#include <iostream>
#include <queue>

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
	vector<vector<int> > Print(TreeNode *pRoot) {
		vector<vector<int>> ans;
		if (!pRoot) {
			return ans;
		}
		queue<TreeNode*> q;
		q.push(pRoot);
		while (!q.empty()) {
			int len = q.size();
			vector<int> now;
			for (int i = 0; i < len; ++i) {
				TreeNode *node = q.front();
				now.push_back(node->val);
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
				q.pop();
			}
			ans.push_back(now);
		}
		return ans;
	}

};
