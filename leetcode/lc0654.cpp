//
// Created by t-xiuyan on 8/24/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
		return createNode(nums);
	}
	TreeNode *createNode(vector<int> vi){
		if (vi.empty()) {
			return nullptr;
		}
		auto maxIter = max_element(vi.begin(), vi.end());
		auto *node = new TreeNode(*maxIter);
		node->left = createNode(vector<int>(vi.begin(), maxIter));
		maxIter++;
		node->right = createNode(vector<int>(maxIter, vi.end()));
		return node;
	}
};
