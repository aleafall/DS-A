//
// Created by aleafall on 16-11-10.
//

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int rob(TreeNode *root) {
		auto ans = DFS(root);
		return max(ans.first, ans.second);
	}

	pair<int, int> DFS(TreeNode *node){
		if (!node) {
			return make_pair();
		}
		auto left = DFS(node->left);
		auto right = DFS(node->right);
		pair<int,int> ans;
		ans.first = max(left.first, left.second) + max(right.first, right.second);
		ans.secon = left.first + right.first + node->val;
		return ans;
	}
};

