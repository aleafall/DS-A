//
// Created by aleafall on 16-11-9.
//

#include <iostream>
#include <vector>

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
    vector<TreeNode*> pre1,in1,pre2,in2;
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return (p == NULL && q == NULL) ||
               ((p && q && p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }

};
