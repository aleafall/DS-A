//
// Created by t-xiuyan on 8/22/2017.
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
	int widthOfBinaryTree(TreeNode *root) {
		vector<pair<int,int>> vi;
		return DFS(root, 0, 1, vi);
	}

	int DFS(TreeNode *node, int level, int order, vector<pair<int, int>> &vi) {
		if (node == nullptr) {
			return 0;
		}
		if (vi.size() == level) {
			vi.push_back({order, order});
		} else {
			vi[level].first = min(vi[level].first,order);
			vi[level].second = max(vi[level].second,order);
		}
		return max(vi[level].second - vi[level].first + 1,
		           max(DFS(node->left, level + 1, 2 * order, vi), DFS(node->right, level + 1, 2 * order + 1, vi)));
	}
};
