//
// Created by aleafall on 17-2-18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
		queue<TreeNode *> q;
		q.push(pRoot);
		int level = 1;
		while (!q.empty()) {
			vector<int> now;
			int len = q.size();     //每一层的结点数
			for (int i = 0; i < len; ++i) {
				TreeNode *node = q.front();
				q.pop();
				now.push_back(node->val);
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			if (!(level & 1)) {     //偶数层
				reverse(now.begin(), now.end());
			}
			++level;
			ans.push_back(now);
		}
		return ans;
	}
};
