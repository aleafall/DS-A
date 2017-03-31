//
// Created by aleafall on 16-11-10.
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
    bool flag=0;
    bool hasPathSum(TreeNode *root, int sum) {
        preOrder(root, 0, sum);
        return flag;
    }

    void preOrder(TreeNode *root, int now, int sum){
        if (root == NULL || flag) {
            return;
        }
        now+=root->val;
        if (root->left == NULL && root->right == NULL && now == sum) {
            flag = 1;
        }
        preOrder(root->left, now, sum);
        preOrder(root->right, now, sum);
    }
};
