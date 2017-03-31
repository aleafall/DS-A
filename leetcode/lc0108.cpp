//
// Created by aleafall on 16-11-14.
//

#include <iostream>
#include <vector>
#include <stack>

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
	TreeNode *sortedArrayToBST(vector<int> &nums) {
		if (nums.empty()) {
			return NULL;
		}
		TreeNode *root = new TreeNode(nums[nums.size() / 2]);
		vector<int> vl = vector<int>(nums.begin(), nums.begin() + nums.size() / 2);
		vector<int> vr = vector<int>(vector<int>(nums.begin() + nums.size() / 2 + 1, nums.end()));
		root->left = sortedArrayToBST(vl);
		root->right = sortedArrayToBST(vr);
		return root;
	}
};
