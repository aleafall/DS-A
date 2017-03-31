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
    int ans=0;
    int countNodes(TreeNode *root) {
        pair<int, int> pa = getHeight(root);
        if (pa.first == pa.second) {
            int temp=1;
            for (int i = 0; i < pa.first; ++i) {
                temp*=2;
            }
            ans=temp-1;
        } else {
            ans = countNodes(root->left) + countNodes(root->right) + 1;
        }
        return ans;
    }

    pair<int, int> getHeight(TreeNode *root) {
        pair<int, int> pa{0, 0};
        if (root == NULL) {
            return pa;
        }
        TreeNode *temp = root;
        while (root) {
            pa.first++;
            root=root->left;
        }
        while (temp) {
            pa.second++;
            temp = temp->right;
        }
        return pa;
    }
};
