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
    bool isBalanced(TreeNode *root) {
        if (root == NULL) {
            return 1;
        }
        return abs(getHeight(root->left) - getHeight(root->right)) <= 1 && isBalanced(root->left) &&
               isBalanced(root->right);
    }

    int getHeight(TreeNode *root){
        if (root == NULL) {
            return 0;
        }
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};
