//
// Created by aleafall on 16-10-18.
//

#include <iostream>
#include <vector>

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL) return NULL;
        if (root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) return root;
        else return left != NULL ? left : right;
    }
};

int main() {
    Solution *solution = new Solution;
    TreeNode *node[10];
    for (int i = 0; i < 10; ++i) {
        node[i] = new TreeNode(i);
    }
    node[3]->left = node[5];
    node[3]->right = node[1];
    node[5]->left = node[6];
    node[5]->right = node[2];
    node[1]->left = node[0];
    node[1]->right = node[8];
    node[2]->left = node[7];
    node[2]->right = node[4];
    TreeNode *ans = solution->lowestCommonAncestor(node[3], node[5], node[4]);
    cout << ans->val << endl;
    delete solution;
    for (int i = 0; i < 10; ++i) {
        delete node[i];
    }
    return 0;
}