//
// Created by aleafall on 17-2-23.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		return pre.empty() ? NULL : create(0, pre.size() - 1, 0, vin.size() - 1, pre, vin);
	}

	TreeNode *create(int preL, int preR, int inL, int inR, const vector<int> &pre, const vector<int> &vin) {
		if (preL > preR) {
			return NULL;
		}
		TreeNode *node = new TreeNode(pre[preL]);
		int k;
		for (k = inL; k <= inR; ++k) {
			if (pre[preL] == vin[k]) {
				break;
			}
		}
		int numLeft = k - inL;
		node->left = create(preL + 1, preL + numLeft, inL, k - 1, pre, vin);
		node->right = create(preL + numLeft + 1, preR, k + 1, inR, pre, vin);
		return node;
	}
};
