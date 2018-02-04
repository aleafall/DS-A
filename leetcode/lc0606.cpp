//
// Created by aleafall on 17-9-24.
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
	string tree2str(TreeNode *t) {
		if (!t) {
			return "";
		} else if (t->left && t->right) {
			return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
		} else if (t->left) {
			return to_string(t->val) + "(" + tree2str(t->left) + ")";
		} else if (t->right) {
			return to_string(t->val) + "()(" + tree2str(t->right) + ")";
		} else {
			return to_string(t->val);
		}
	}
};

int main() {
	const int x = 1;
	int *p;
	const int **q= static_cast<const int **>(&p);
    return 0;
}