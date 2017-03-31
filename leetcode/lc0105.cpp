//
// Created by aleafall on 16-11-10.
//

#include <iostream>
#include <algorithm>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        TreeNode *root = create(0, (int) preorder.size() - 1, 0, (int) inorder.size() - 1,preorder,inorder);
        return root;
    }
    TreeNode *create(int preL,int preR,int inL,int inR,vector<int> &preorder, vector<int> &inorder){
        if (preL > preR) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[preL]);
        int k;
        for (k = inL; k <= inR; ++k) {
            if (preorder[preL] == inorder[k]) {
                break;
            }
        }
        int numLeft=k-inL;
        root->left = create(preL + 1, preL + numLeft, inL, k - 1, preorder, inorder);
        root->right = create(preL + numLeft + 1, preR, k + 1, inR, preorder, inorder);
        return root;
    }
};