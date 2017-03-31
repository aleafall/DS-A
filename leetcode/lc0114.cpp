//
// Created by aleafall on 16-11-11.
//

#include <iostream>

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
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        if (root->left) {
            TreeNode *temp = root->right;
            root->right=root->left;
            if (temp) {
                TreeNode *now = root->left;
                while (now->right) {
                    now = now->right;
                }
                now->right = temp;
            }
            root->left = NULL;
        }
    }
};
