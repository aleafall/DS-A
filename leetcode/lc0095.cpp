//
// Created by aleafall on 17-1-30.
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
	vector<TreeNode *> generateTrees(int n) {
		if (n <= 0) {
			return vector<TreeNode *>();
		}
		return generate(0, n - 1);
	}

	vector<TreeNode *> generate(int beg, int end){
		vector<TreeNode *> vt;
		if (beg > end) {
			vt.push_back(NULL);
			return vt;
		}
		for (int i = beg; i <= end; ++i) {
			vector<TreeNode *> left = generate(beg, i - 1);
			vector<TreeNode *> right = generate(i + 1, end);
			for (int j = 0; j < left.size(); ++j) {
				for (int k = 0; k < right.size(); ++k) {
					TreeNode *node = new TreeNode(i + 1);
					vt.push_back(node);
					node->left = left[j];
					node->right = right[k];
				}
			}
		}
		return vt;
	}
};
