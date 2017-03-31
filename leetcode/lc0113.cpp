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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<int> vi;
        preOrder(root, vi, sum);
        return ans;
    }

    void preOrder(TreeNode *root, vector<int> vi,int sum){
        if (root == NULL) {
            return;
        }
        vi.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            int now=0;
            for (auto item:vi) {
                now+=item;
            }
            if (now == sum) {
                ans.push_back(vi);
            }
        }
        preOrder(root->left, vi, sum);
        preOrder(root->right, vi, sum);
    }
};
