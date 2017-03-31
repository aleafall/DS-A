//
// Created by aleafall on 16-10-17.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode *root) {
        inOrder(root);
        return ans;
    }
    void inOrder(TreeNode *root){
        if (root==NULL)
            return;
        inOrder(root->left);
        ans.push_back(root->val);
        inOrder(root->right);
    }
};
