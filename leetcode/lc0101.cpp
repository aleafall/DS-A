//
// Created by aleafall on 16-11-14.
//

#include <bits/stdc++.h>

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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return 1;
        }
        return isEqual(root->left, root->right);
    }

    bool isEqual(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) {
            return 1;
        }
        if (left == NULL) {
            return 0;
        }
        if (right == NULL) {
            return 0;
        }
        if (left->val != right->val) {
            return 0;
        }
        return
                isEqual(left->right, right->left) && isEqual(left->left, right->right);
    }
};
