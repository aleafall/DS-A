//
// Created by aleafall on 17-9-15.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	unordered_set<int> st;
	bool ans = 0;
public:
	bool findTarget(TreeNode *root, int k) {
		preOrder(root, k);
		return ans;
	}
	void preOrder(TreeNode *node,int k){
		if (!node||ans) {
			return;
		}
		if (st.count(k - node->val)) {
			ans = 1;
			return;
		}
		st.insert(node->val);
		preOrder(node->left, k);
		preOrder(node->right, k);
	}
};
