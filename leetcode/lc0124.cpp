//
// Created by aleafall on 16-11-10.
//

#include <iostream>
#include <algorithm>

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
    int Max=INT32_MIN;
    int maxPathSum(TreeNode *root) {
        int ans = postOrder(root);
        return Max;
    }

    int postOrder(TreeNode *root){
        int ans;
        if (root->left == NULL && root->right == NULL) {
            Max = max(Max, root->val);
            ans=root->val;
        } else if (root->left && root->right) {
            int leftSum = postOrder(root->left);
            int rightSum = postOrder(root->right);
            ans = max(root->val, max(root->val + leftSum, root->val + rightSum));
            Max = max(max(Max,root->val+leftSum+rightSum), max(leftSum, rightSum));
            Max = max(Max, ans);
        } else if (root->left) {
            int leftSum = postOrder(root->left);
            ans = max(root->val, root->val + leftSum);
            Max = max(Max, max(leftSum, ans));
        } else {
            int rightSum = postOrder(root->right);
            ans = max(root->val, root->val + rightSum);
            Max = max(Max, max(rightSum, ans));
        }
        return ans;
    }
};
