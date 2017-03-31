//
// Created by aleafall on 16-11-10.
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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<int> vi;
        preOrder(root, vi);
        return ans;
    }
    void preOrder(TreeNode *root,vector<int> vi){
        if (root == NULL) {
            return;
        }
        vi.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            string s;
            for (size_t i = 0; i <vi.size() ; ++i) {
                s += to_string(vi[i]);
                if (i < vi.size() - 1) {
                    s += "->";
                }
            }
            ans.push_back(s);
        }
        preOrder(root->left, vi);
        preOrder(root->right, vi);
    }
};
