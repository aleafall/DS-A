//
// Created by aleafall on 16-10-18.
//

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 *  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        inOrder(root);
        return root;
    }
    void inOrder(TreeNode *root){
        if (root==NULL) return;
        inOrder(root->left);
        inOrder(root->right);
        swap(root->left,root->right);
    }
};
