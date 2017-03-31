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
    int ans=0;
    int maxDepth(TreeNode *root) {
        preOrder(root, 1);
        return ans;
    }
    void preOrder(TreeNode *root,int level){
        if (root == NULL) {
            return;
        }
        ans = max(ans, level);
        preOrder(root->left, level + 1);
        preOrder(root->right, level + 1);
    }
};
