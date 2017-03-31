//
// Created by aleafall on 16-11-10.
//

#include <iostream>
#include <vector>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = create(0, (int) inorder.size() - 1, 0, (int) postorder.size() - 1, inorder, postorder);
        return root;
    }

    TreeNode *create(int postL, int postR, int inL, int inR, vector<int> &inorder, vector<int> &postorder){
        if (inL > inR) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[postR]);
        int k;
        for (k = inL; k <= inR; ++k) {
            if (postorder[postR] == inorder[k]) {
                break;
            }
        }
        int numLeft=k-inL;
        root->left = create(postL, postL + numLeft - 1, inL, k - 1, inorder, postorder);
        root->right = create(postL + numLeft, postR - 1, k + 1, inR, inorder, postorder);
        return root;
    }
};